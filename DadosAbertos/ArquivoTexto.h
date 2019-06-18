// Esta classe fornece os m�todos b�sicos para manipular um arquivo texto em disco.
#ifndef ARQUIVO_TEXTO
#define ARQUIVO_TEXTO

#define ARQUIVO_INVESTIDOR 0
#define ARQUIVO_VENDA 1
#define NUMERO_MAXIMO_ELEMENTOS_VECTOR 30000


#include <fstream>
#include <cstring>
#include <vector>
#include "Vetor.h"


using namespace std;

/* Define os tipos de acesso que podem ser usados para acessar o arquivo. Os modos dispon�veis s�o:

ACRESCENTAR: abre o arquivo somente para acrescentar dados no fim do arquivo;
ESCRITA: abre o arquivo somente para a escrita de dados;
LEITURA: abre o arquivo somente para a leitura de seu conte�do.
*/
enum TipoDeAcesso { ACRESCENTAR, ESCRITA, LEITURA };

class ArquivoTexto {
public:
	ArquivoTexto();

	// Fecha o arquivo texto antes do objeto ser removido da mem�ria.
	~ArquivoTexto();

	/* Abre um arquivo texto identificado pelo par�metro nomeArquivo.
	* O modo de abertura do arquivo deve ser especificado por uma das constantes de TipoDeAcesso.
	* Se o arquivo n�o existir ele ser� criado. Se o modo for ESCRITA e o arquivo j� existir em disco,
	* todo o seu conte�do ser� exclu�do.
	* Retorna true se o arquivo foi aberto com sucesso e false caso contr�rio.
	*/
	bool abrir(string nomeArquivo, TipoDeAcesso modo);

	/* Escreve no arquivo texto o conte�do do objeto string armazenado no par�metro conteudo.
	* A escrita sempre ocorre no fim do arquivo.
	* Retorna true se a opera��o foi realizada com sucesso e false caso contr�rio.
	*/
	bool escrever(string conteudo);

	/* L� o conte�do do arquivo texto linha por linha.
	* Armazena os dados em uma matriz de vector.
	* Retorna true caso tenha feito corretamente a leitura dos dados.
	* Em caso de erro retorna false.
	*/
	bool ler(Vetor &vetor/*, GerenciaDados &gerenciaDados*/);

	// Fecha o arquivo texto.
	void fechar();

	// Obt�m o nome do arquivo texto.
	string getNomeArquivo();

	
private:
	string nomeArquivo;
	ifstream inputFile;
	ofstream outputFile;
};
#endif 