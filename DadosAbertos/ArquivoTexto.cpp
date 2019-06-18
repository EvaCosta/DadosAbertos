// Implementa os servi�os da classe ArquivoTexto.
//#include "Cabecalhos.h"

#include <iostream>
#include <conio.h>
#include "ArquivoTexto.h"
#include "EntradaESaida.h"
#include "ProgressBar.h"
#include "Console.h"
#include "GerenciaDados.h"

// Construtor padr�o.
ArquivoTexto::ArquivoTexto() {}

// Fecha o arquivo texto antes do objeto ser removido da mem�ria.
ArquivoTexto::~ArquivoTexto() {
	fechar();
}

/* Abre um arquivo texto identificado pelo par�metro nomeArquivo.
 * O modo de abertura do arquivo deve ser especificado por uma das constantes de TipoDeAcesso.
 * Se o arquivo n�o existir ele ser� criado. 
 * Se o modo for ESCRITA e o arquivo j� existir em disco, todo o seu conte�do ser� exclu�do.
 * Retorna true se o arquivo foi aberto com sucesso e false caso contr�rio.
*/
bool ArquivoTexto::abrir(string nomeArquivo, TipoDeAcesso modo) {
	this->nomeArquivo = nomeArquivo;

	// Abre o arquivo segundo o modo de abertura.
	switch (modo) {
	case ACRESCENTAR: outputFile.open(nomeArquivo, ios::app);
		if (outputFile.is_open()) return true;
		break;

	case ESCRITA: outputFile.open(nomeArquivo, ios::out);
		if (outputFile.is_open()) return true;
		break;

	case LEITURA: inputFile.open(nomeArquivo, ios::in);
		/* O teste abaixo verifica se foi retornado um ponteiro v�lido, diferente de nulo, se sim o teste � true indicando que o arquivo foi aberto com sucesso.
		Caso contr�rio, um ponteiro nulo indica que houve erro ao tentar abrir o arquivo.
		*/
		if (inputFile) return true;
	}
	return false;
} // abrir()

  /* L� o conte�do do arquivo texto linha por linha.
   * Armazena os dados em uma matriz de vector.
   * Retorna true caso tenha feitoool corretamente a leitura dos dados.
   * Em caso de erro retorna false.
  */
bool ArquivoTexto::ler(Vetor &vetor/*, GerenciaDados &gerenciaDados*/) {
	char linha[256];
	int  cont = 0;
	int tipoArquivo = -1;
	GerenciaDados gerenciaDados;
	
	// Verifica se ocorreu erro ao acessar o arquivo.
	if (!inputFile) {
		return false;
	}


	if (!nomeArquivo.compare("InvestidoresTesouroDireto.csv"))
		tipoArquivo = ARQUIVO_INVESTIDOR;
	if (!nomeArquivo.compare("VendasTesouroDireto.csv"))
		tipoArquivo = ARQUIVO_VENDA;

	// ignora primeira linha que corresponde ao cabe�alho do arquivo.
	inputFile.getline(linha, 256); 

	// L� o conte�do do arquivo at� atingir o fim do arquivo.
	do { // L� o conte�do de uma linha limitada a 256 caracteres ou at� encontrar o caractere nova linha ('\n'). 

		//Realiza a leitura da linha do arquivo.
		inputFile.getline(linha, 256);

		if (strcmp(linha, "") == 0)
			break;

		//Se o arquivo corresponder ao arquivo de Investidores adiciona a linha no vector de strings.
		if (tipoArquivo == ARQUIVO_INVESTIDOR) {
			vetor.adicionarInvestidorString(linha);
		}
		//Se o  arquivo corresponder ao arquivo de Vendas adiciona o objeto no vector de Vendas.
		else if (tipoArquivo == ARQUIVO_VENDA) {
			vetor.adicionarVendaString(linha);			
		}
		else {
			cout << "Nome n�o corresponde a nenhum arquivo especificado!" << endl;
			return false;
			
		}//if(!inputFile.eof())
	} while (!inputFile.eof());

	bool dadosImportadosObjeto = gerenciaDados.adicionaDadosNoObjeto(vetor, tipoArquivo, 0);
	return dadosImportadosObjeto;
} // ler()

  /* Escreve no arquivo texto o conte�do do objeto string armazenado no par�metro conteudo.
  * A escrita do conteudo sempre ocorre no fim do arquivo.
  * Retorna true se a opera��o foi realizada com sucesso e false caso contr�rio.
  */
bool ArquivoTexto::escrever(string conteudo) {
	/* Escreve no arquivo se ele estiver aberto.
	* Posiciona o ponteiro de posi��o de arquivo no fim e escreve o conte�do.
	*/
	if (outputFile.is_open()) {
		outputFile.seekp(0, ios::end);
		outputFile << conteudo << endl;
		return true;
	}
	return false;
} // escrever()

  //Fecha o arquivo texto.
void ArquivoTexto::fechar() {
	// Fecha o arquivo se estiver aberto.
	if (inputFile.is_open()) inputFile.close();
	if (outputFile.is_open()) outputFile.close();
}

//Obt�m o nome do arquivo texto.
string ArquivoTexto::getNomeArquivo() {
	return nomeArquivo;
}



