#include <iomanip>
#include "Console.h"
#include "ProgressBar.h"
#include "EntradaESaida.h"
#include "GerenciaDados.h"
#include "Relatorio.h"

GerenciaDados::GerenciaDados(){}

bool GerenciaDados::adicionaDadosNoObjeto(Vetor &vetor, int tipoArquivo,int ocultaBarra) {
	int contador = 0, tamanho = 0;
	Investidor investidor;
	char linha[256];
	cout << fixed << setprecision(2);
	ProgressBar *investidoresProgressBar = NULL, *vendasProgressBar = NULL;
	if (tipoArquivo == ARQUIVO_INVESTIDOR) {
		if (ocultaBarra == 0)
			investidoresProgressBar = new ProgressBar(6, 10, 90);
			
			for (int indice = 0; indice < vetor.obterTamanhoInvestidorString(); indice++) {
				strcpy_s(linha, sizeof(linha), vetor.obterInvestidorString(indice).c_str());
				vetor.adicionarInvestidorNoObjeto(leituraDeDadosVetorInvestidor(linha));
				
				if(ocultaBarra == 0){
					investidoresProgressBar->showProgress((contador * 100) / vetor.obterTamanhoInvestidorString());
					contador++;
				}
			}
			
			
		}

	else if (tipoArquivo == ARQUIVO_VENDA) {
		if (ocultaBarra == 0)
			vendasProgressBar = new ProgressBar(6, 5, 45);
		
		int contador = 1;
		for (int indice = 0; indice < vetor.obterTamanhoVendasString(); indice++) {
			strcpy_s(linha, sizeof(linha), vetor.obterVendaString(indice).c_str());
			vetor.adicionarVendaNoObjeto(leituraDeDadosVetorVenda(linha));
			
			if (ocultaBarra == 0) {
				vendasProgressBar->showProgress((contador * 100) / vetor.obterTamanhoVendasString());
				contador++;
			}
		}
	}

	return true;
}

/* Quebra a string separando os dados a partir do delimitador ";"
* Armazena os dados obtidos a partir da string em um Objeto.
* Retorna o objeto estático investidor.
*/
Investidor GerenciaDados::leituraDeDadosVetorInvestidor(char *linha) {
	Investidor investidor;
	char *token = NULL, *nexttoken = NULL;
	int verificador = 0;

	token = strtok_s(linha, ";", &nexttoken);
	investidor.setCodigo(atoi(token));

	while (token != NULL) {
		token = strtok_s(NULL, ";", &nexttoken);
		if (token != NULL) {
			switch (verificador) {
			case 0: investidor.setDataDeAdesao(token); verificador++; break;
			case 1: investidor.setEstadoCivil(token); verificador++; break;
			case 2: investidor.setGenero(token); verificador++;  break;
			case 3: investidor.setProfissao(token); verificador++; break;
			case 4: investidor.setIdade(atoi(token)); verificador++;  break;
			case 5: investidor.setUf(token); verificador++; break;
			case 6: investidor.setCidadeInvestidor(token); verificador++; break;
			case 7: investidor.setPaisInvestidor(token); verificador++; break;
			case 8: investidor.setSituacaoConta(token); verificador++; break;
			case 9: investidor.setOperou1Ano(token); verificador++; break;
			}
		}
	}
	return investidor;
}

/* Quebra a string separando os dados a partir do delimitador ";"
* Armazena os dados obtidos a partir da string em um Objeto.
* Retorna o objeto estático venda.
*/
Venda GerenciaDados::leituraDeDadosVetorVenda(char *linha) {
	char *token = NULL, *nexttoken = NULL;
	int verificador = 0;
	Venda vendas;

	token = strtok_s(linha, ";", &nexttoken);
	vendas.setTitulo(token);

	while (token != NULL) {
		token = strtok_s(NULL, ";", &nexttoken);
		if (token != NULL) {
			switch (verificador) {
			case 0: vendas.setDataDeVencimento(token); verificador++; break;
			case 1: vendas.setDataVenda(token); verificador++; break;
			case 2: vendas.setPrecoUnitario(ajustaValor(token)); verificador++;  break;
			case 3: vendas.setQuantidade(ajustaValor(token)); verificador++; break;
			case 4: vendas.setValor(ajustaValor(token)); verificador++; break;
			}
		}
	}

	return vendas;
}

