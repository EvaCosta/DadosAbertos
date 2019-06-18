#include <iostream>
#include <cstring>
#include <clocale>
#include <iomanip>
#include "ProgressBar.h"
#include "Console.h"
#include <Windows.h>
#include "Relatorio.h"

void menuRelatorio(Vetor &vetor, GerenciaDados &gerenciaDados) {

	int opcaoMenu;
	do {
		informacoesMenuRelatorio();
		opcaoMenu = lerDado();
		escolheOpcaoMenuRelatorio(opcaoMenu, vetor, gerenciaDados);
	} while (opcaoMenu != 5);


}

void informacoesMenuRelatorio() {
	cout << "\n\n ---------- Relatórios do Tesouro Direto ---------- \
			 \n1. Títulos do tesouro direto \
             \n2. Investidores por estado civil \
			 \n3. Investidores por gênero \
			 \n4. Investidores por região \
			 \n5. Sair \
			 \n\n Escolha:  ";
}

void escolheOpcaoMenuRelatorio(int opcao, Vetor &vetor, GerenciaDados &gerenciaDados) {
	limparTela();
	switch (opcao) {
	case 1: tituloDoTesouro(vetor); break;
	case 2: investidoresPorEstadoCivil(vetor);  break;
	case 3: investidoresPorGenero(vetor, gerenciaDados);  break;
	case 4: investidoresPorRegiao(vetor, gerenciaDados); break;
	case 5: break;
	default:
		break;
	}
}
// Lê o tipo de título do Tesouro Direto e uma data de venda.
void tituloDoTesouro(Vetor &vetor) {
	string dataInicial, dataFinal;
	int valorDataInicial, valorDataFinal;
	char op;
	do {
		exibeMensagem("\n ----------- Relatório no Tesouro Direto -----------\n");
		exibeMensagem("\nData Inicial de venda (DD/MM/AAAA): ");

		dataInicial = lerString();

		valorDataInicial = ajustaData(dataInicial);

		exibeMensagem("\nData Final de venda (DD/MM/AAAA): ");

		dataFinal = lerString();

		valorDataFinal = ajustaData(dataFinal);

		//pesquisa no conjunto de dados.
		if (pesquisaDataPorPeriodo(valorDataInicial, valorDataFinal, dataInicial, dataFinal, vetor) == 1) {
			exibeMensagem("\nNenhuma venda foi realizada nesse periodo.\n");
		}

		exibeMensagem("\nDeseja realizar outra pesquisa? S/N\n");
		op = leChar();
		limparTela();
	} while (op != 'N');
}

bool verificaMaiorData(int valorData1, int valorData2) {
	return valorData1 > valorData2;
}

/* Pesquisa no vector os dados e, se encontrar, exibe a data de vencimento, a quantidade e o valor total
 * vendido do tipo de título escolhido na data pesquisada.
 */
int pesquisaDataPorPeriodo(int valorDataInicial, int valorDataFinal, string dataInicial, string dataFinal, Vetor &vetor) {
	char *titulosDoTesouroDireto[] = { "Tesouro IGPM+ com Juros Semestrais","Tesouro IPCA+ com Juros Semestrais","Tesouro IPCA+","Tesouro Prefixado com Juros Semestrais","Tesouro Prefixado", "Tesouro Selic" };
	double quantidade[6] = { 0,0,0,0,0,0 };
	double valor[6] = { 0,0,0,0,0,0 };

	int dataNoObjeto, retorno = 1;
	int cont = 0;

	/* Percorre o vector de Investidor, verifica se a data obtida do vector correponde ao intervalo
	 * solicitado, adiciona para cada titulo correspondente o valor e a quantidade respectivamente
	 */
	for (int i = 0; i < vetor.obterTamanhoVendas(); i++) {
	
		dataNoObjeto = ajustaData(vetor.obterVenda(i).getDataVenda());
		if (dataNoObjeto >= valorDataInicial && dataNoObjeto <= valorDataFinal) {
			for (int indice = 0; indice < 6; indice++){
				if (vetor.obterVenda(i).getTitulo() == titulosDoTesouroDireto[indice]) {
					quantidade[indice] += vetor.obterVenda(i).getQuantidade();
					valor[indice] += vetor.obterVenda(i).getValor();

					retorno = 0;
				}

			}
		}
		
	}
	limparTela();
	cout << "\nOs dados estão sendo coletados...\n";

	cout << "\n---------------------- Relatório de Vendas por Data ---------------------- \n";
	cout << "\nPeriodo de " << dataInicial << " à " << dataFinal << "." << endl;

	for (int i = 0; i < 6; i++) {
		if (quantidade[i] > 0) {
			cout << "\n-=> " << titulosDoTesouroDireto[i];
			cout << "\n\tQuantidade: R$ " << fixed << setprecision(2) << quantidade[i];
			cout << "\n\tValor total: R$ " << fixed << setprecision(2) << valor[i] << endl;
		}
	}

	return retorno;
}
/* Exibe a relação dos dez tipos de estado civil,  mostrando pra cada um a quantidade e a média de idade 
 * de investidores.
 */
void investidoresPorEstadoCivil(Vetor &vetor) {
	//Caso o arquivo esteja configurado para ANSI a comparação é feita com os caracteres especiais.
	char *estadoCivil[10] = { "Desquitado(a)", "ViÃºvo(a)","Divorciado(a)", "Casado(a) com brasileiro(a) nato(a)","Casado(a) com brasileiro(a) naturalizado(a)","Casado(a) com estrangeiro(a)", "Separado judic.", "UniÃ£o estÃ¡vel", "NÃ£o se aplica", "Solteiro(a)" };
	char *estadoCivilAcentuado[10] = { "Desquitado(a)", "Viúvo(a)","Divorciado(a)", "Casado(a) com brasileiro(a) nato(a)","Casado(a) com brasileiro(a) naturalizado(a)","Casado(a) com estrangeiro(a)", "Separado judic.", "União estável", "Não se aplica", "Solteiro(a)" };
	int quantidade[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int idade[10] = { 0,0,0,0,0,0,0,0,0,0 };

	/* Percorre o vector Investidor comparando com os dados armazenados no array
	 * ao encontrar um dado correspondente armazena a quantidade e idade
	 * refentes a cada estado civil.
	 */
	for (int i = 0; i < vetor.obterTamanhoInvestidor(); i++) {
		for (int linha = 0; linha < 10; linha++) {
			if (vetor.obterInvestidor(i).getEstadoCivil() == estadoCivil[linha] || vetor.obterInvestidor(i).getEstadoCivil() == estadoCivilAcentuado[linha]) {
				quantidade[linha]++;

				idade[linha] += vetor.obterInvestidor(i).getIdade();
			}

		}
	}

	limparTela();
	cout << "\nOs dados estão sendo coletados ...\n";


	
	//Exibe a relação de investidores por estado civil.
	cout << "\n---------------------- Relatório Investidores por Estado Civil ---------------------- \n";
	
	
	for (int i = 0; i < 10; i++) {
		if (quantidade[i] > 0) {
			cout << "\n-=> "<<  estadoCivilAcentuado[i];
			cout << "\n\tQuantidade: " << quantidade[i];
			cout << "\n\tMédia de Idade: " << fixed << setprecision(0) << idade[i] / (quantidade[i]) << "anos." <<endl;
		}
	}
	promptUniversal();
	limparTela();
}

/* Exibe a relação dos três tipos de gênero mostrando pra cada um a quantidade e a idade média dos 
 * investidores do Tesouro Direto.
 */
void investidoresPorGenero(Vetor &vetor, GerenciaDados &gerenciaDados) {
	char *genero[3] = { "M", "F","N" };
	char *generoCompleto[] = { "Masculino", "Feminino", "Não se aplica" };
	int quantidade[3] = { 0,0,0 };
	int idade[3] = { 0,0,0 };
	
	/* Percorre o vector Investidor comparando com os dados armazenados no array
	* ao encontrar um dado correspondente armazena a quantidade e idade
	* refentes a cada genero.
	*/
	for (int i = 0; i < vetor.obterTamanhoInvestidor(); i++) {
		for (int linha = 0; linha < 3; linha++) {
			if (vetor.obterInvestidor(i).getGenero() == genero[linha]) {
				quantidade[linha]++;

				idade[linha] += vetor.obterInvestidor(i).getIdade();
			}

		}
	}

	limparTela();
	cout << "\nOs dados estão sendo coletados...\n";


	cout << "\n---------------------- Relatório Investidores por Gênero ---------------------- \n";
	for (int i = 0; i < 3; i++) {
		if (quantidade[i] > 0) {
			cout << "\n-=> " << generoCompleto[i];
			cout << "\n\tQuantidade: " << quantidade[i];
			cout << "\n\tMédia de Idade: " << idade[i] / quantidade[i] << endl;
		}
	}

	
	promptUniversal();
	limparTela();
}

/* Exibe a relação das cinco regiões do Brasil mostrando pra cada uma a quantidade e idade
 * média dos investidores do Tesouro Direto.
 */
void investidoresPorRegiao(Vetor &vetor, GerenciaDados &gerenciaDados) {
	int numeroDeLinhas = 0;
	string regiaoDoBrasil[] = { "Norte", "Nordeste", "Centro-Oeste", "Sudeste", "Sul" };
	int quantidade[5] = { 0,0,0,0,0 };
	int idade[5] = { 0,0,0,0,0 };
	int regioes[5] = { 0,0,0,0,0 };
	int regiao;
	int cont = 0;
	
	for (int i = 0; i < vetor.obterTamanhoInvestidor(); i++) {
		regiao = verificaRegiao(vetor.obterInvestidor(i).getUf());
		regioes[regiao]++;
		idade[regiao] += vetor.obterInvestidor(i).getIdade();
		quantidade[regiao]++;

	}
		
	cout << "\nOs dados estão sendo coletados...\n";

	cout << "\n---------------------- Relatório Investidores por Região ---------------------- \n";
		
	for (int i = 0; i < 5; i++) {
		if (quantidade[i] > 0) {
			cout << "\n-=> " << regiaoDoBrasil[i];
			cout << "\n\tQuantidade: " << quantidade[i];
			cout << "\n\tMédia de Idade: " << idade[i] / quantidade[i] << "anos." << endl;
		}
	}
	
	promptUniversal();
	limparTela();
}

/* Verifica a qual região pertence a unidade federativa passada por parametro.
 * Retorna o número correspondente caso encontre a região e - caso contrário.
*/
int verificaRegiao(string unidadeFederativa) {
	string norte[] = { "AC","AP","AM","PA","RO","RR","TO" };
	string nordeste[] = { "AL", "BA","CE","MA","PB","PE","PI","RN","SE" };
	string centroOeste[] = { "DF", "GO", "MT", "MS" };
	string sudeste[] = { "ES", "MG", "RJ", "SP" };
	string sul[] = { "PR", "RS", "SC" };

	for (int i = 0; i < 7; i++) { if (unidadeFederativa == norte[i]) return 0; }
	for (int i = 0; i < 9; i++) { if (unidadeFederativa == nordeste[i]) return 1; }
	for (int i = 0; i < 4; i++) { if (unidadeFederativa == centroOeste[i]) return 2; }
	for (int i = 0; i < 4; i++) { if (unidadeFederativa == sudeste[i]) return 3; }
	for (int i = 0; i < 4; i++) { if (unidadeFederativa == sul[i]) return 4; }

	return - 1;
}