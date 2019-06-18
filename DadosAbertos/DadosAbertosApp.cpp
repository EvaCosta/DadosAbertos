#include <iostream>
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include "ArquivoTexto.h"
#include "EntradaESaida.h"
#include "Vetor.h"
#include "ProgressBar.h"
#include "Console.h"
#include "DadosAbertos.h"
#include "Relatorio.h"
#include "Pesquisa.h"

int main() {
	return iniciar();
}

int iniciar() {
	Vetor vetor;
	GerenciaDados gerenciaDados;
	setlocale(LC_ALL, "pt-BR");
	dadosAbertos(vetor, gerenciaDados);
	return 0;
}

void dadosAbertos(Vetor &vetor, GerenciaDados &gerenciaDados) {
	int opcao=0;

	do {
		menu();
		opcao = lerDado();
		escolheOpcao(opcao, vetor, gerenciaDados);
	} while (opcao != 4);
}

void menu() {
	cout << "\n\n ---------- Tesouro Direto ---------- \n \
			 \n1. Importação de Dados tesouro Direto \
			 \n2. Consultas \
             \n3. Relatórios \
			 \n4. Sair \
			 \n\n Escolha:  ";
}

void escolheOpcao(int opcao, Vetor &vetor, GerenciaDados &gerenciaDados) {
	int opcaoMenu = 0;

	limparTela();

	switch (opcao) {
	case 1:
		//Exibe uma mensagem informando ao usuário se os dados já estiverem em memória.
		if (vetor.obterQtdeLinhasVendaString() > 0) {
			cout << "\nOs dados já foram importados.\n";
			promptUniversal();
			limparTela();

		}
		else {
			importarDados(vetor);
		}

		break;
	case 2: 
		if (vetor.obterQtdeLinhasVendaString() == 0) {
			cout << "\nNenhum dado em memória, é necessário importar os dados!\n.";
			promptUniversal();
			limparTela();
		}
		else {
			menuConsulta(vetor); 
		}
		break;
	case 3: 
		if (vetor.obterQtdeLinhasVendaString() == 0) {
			cout << "\nNenhum dado em memória, é necessário importar os dados!\n.";
			promptUniversal();
			limparTela();
		}
		else {
			menuRelatorio(vetor, gerenciaDados);
		}
		break;
	case 4: finalizarPrograma();
	}

	
}

void importarDados(Vetor &vetor/*, GerenciaDados &gerenciaDados*/) {
	limparTela();
	ocultaCursor();
	Console::gotoxy(1, 1); cout << "Importando os dados do Tesouro Direto...";

	Console::gotoxy(3, 4); cout << "1. Vendas do Tesouro Direto";
	analisarArquivo("VendasTesouroDireto.csv", vetor/*, gerenciaDados*/, ARQUIVO_VENDA);
	
	Console::gotoxy(3, 9);
	cout << "2. Investidores do Tesouro Direto";
	analisarArquivo("InvestidoresTesouroDireto.csv", vetor/*, gerenciaDados*/, ARQUIVO_INVESTIDOR);

	cout << "\n\n\n\tDados importados com sucesso!";
	promptUniversal();
	limparTela();
	setlocale(LC_ALL, ".1252");
}

/*  A partir do nome do arquivo é realizada a abertura do mesmo, em caso de sucesso é iniciada a leitura
*  Caso contrário é informado ao usuário que o arquivo não pode ser aberto.
*/
int analisarArquivo(string nomeArquivo, Vetor &vetor/*, GerenciaDados &gerenciaDados*/, int verificador) {
	int tamanhoDoVectorVendas = vetor.obterTamanhoVendasString(), tamanhoDoVectorInvestidores = vetor.obterTamanhoInvestidorString();
	ArquivoTexto arquivoTexto;

	bool status = arquivoTexto.abrir(nomeArquivo, TipoDeAcesso::LEITURA);
	

	//Se o arquivo for aberto corretamente, realiza a leitura.
	if (status) {
		
		//Realiza a leitura do arquivo.
		arquivoTexto.ler(vetor/*, gerenciaDados*/);
	
		//Fecha o arquivo.
		arquivoTexto.fechar();
	}
	else {
		exibeMensagem("\nArquivo incorreto");
	}
	return 0;
}

void menuConsulta(Vetor &vetor) {
	int opcaoMenu;
	do {
		informacoesMenu();
		opcaoMenu = lerDado(); 
		escolheOpcaoMenuConsulta(opcaoMenu, vetor);
	} while (opcaoMenu !=3);
	
}

void informacoesMenu() {
	cout << "\n ---------- Pesquisa no Tesouro Direto ---------- \n \
			 \n1. Número de vendas a partir da data \
             \n2. Tipo de Título \
			 \n3. Sair \
			 \n\n Escolha:  ";
}

void escolheOpcaoMenuConsulta(int opcao, Vetor &vetor) {
	limparTela();
	switch (opcao) {
	case 1: numeroVendas(vetor); break;
	case 2: tipoDeTitulo(vetor); break;
	case 3: break;
	default:
		break;
	}
}