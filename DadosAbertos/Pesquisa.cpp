#include <iostream>
#include "Pesquisa.h"

/* Lê uma data de venda, pesquisa no conjunto de dados importados e, se encontrar, exibe os
* tipos de títulos do Tesouro Direto, a data de vencimento, a quantidade e o valor total vendido
* de cada título na data pesquisada. Se não houver nenhuma venda no dia consultado exibe a
* mensagem Nenhum tipo de título do Tesouro Direto foi vendido em DD/MM/AAA, onde DD/MM/AAA
* é a data de venda pesquisada.*/
void numeroVendas(Vetor &vetor) {
	string data;
	char op;
	do {
		exibeMensagem("\n ----------- Pesquisa no Tesouro Direto -----------\n");
		exibeMensagem("\n Data de venda (DD/MM/AAAA): ");

		data = lerString();

		int dataInt = ajustaData(data);
		if (pesquisaData(dataInt, vetor) == 1) {
			exibeMensagem("\n Nenhum tipo de título do Tesouro Direto foi vendido em " + data + ".\n");
		}

		exibeMensagem("\n Deseja realizar outra pesquisa? S/N\n");
		op = leChar();
		limparTela();
	} while (op != 'N');
}

/* Realiza a pesquisa no vetor de Vendas, a data armazenada no objeto venda é quebrada sendo retirado o delimitador "\".
* Os valores correspondentes a dia, mês e ano são somados e é feita a comparação entre a data passado por parametro e a data
* ajustada do objeto. Caso as datas sejam iguais são exibidos os dados e o valor de retorno da função é 0, caso contrário retorna 1.
*/
int pesquisaData(int dataInt, Vetor &vetor) {
	int dataNoObjeto, retorno = 1;

	for (int i = 0; i < vetor.obterTamanhoVendas(); i++) {
		dataNoObjeto = ajustaData(vetor.obterVenda(i).getDataVenda());

		if (dataInt == dataNoObjeto) {
			vetor.exibirVendasPorData(i);
			retorno = 0;
		}
	}
	return retorno;
}

/* Recebe a data e a partir do delimitador "/" com o uso de strtok quebra a data e atribui para as variaveis
* dia, mes e ano respectivamente.
* Verifica se a data foi passada no formato correto DD/MM/AAAA, em caso negativo retorna -1 , caso contrário verifica se os
* valores referentes a dia, mes e ano estão corretos, em caso negativo retorna 1, caso contrário soma os valores das variaveis.
*/
int ajustaData(string data) {
	char *token = NULL, *nexttoken = NULL;
	char date[12];
	int somatorio;
	int dia, mes, ano;
	int contDelimitador = 0;
	bool validacaoData;

	strcpy_s(date, sizeof(date), data.c_str());

	token = strtok_s(date, "/", &nexttoken);
	dia = atoi(token);

	while (token != NULL) {
		token = strtok_s(NULL, "/", &nexttoken);

		if (token != NULL) {
			if (contDelimitador == 0) {
				mes = atoi(token);
				contDelimitador++;
			}
			else if (contDelimitador == 1)
				ano = atoi(token);
		}
	}

	if (contDelimitador == 1) {
		validacaoData = verificaData(dia, mes, ano);

		if (validacaoData == true)
			somatorio = dataInt(dia, mes, ano);
		else
			return 1;

		return somatorio;
	}
	else
		return -1;
}

//Soma os valores da data
int dataInt(int dia, int mes, int ano) {
	return dia + (mes * 30) + (ano * 365);
}

//Valida se a data está correta.
bool verificaData(int dia, int mes, int ano) {
	if ((dia > 0 && dia <= 31) && (mes > 0 && mes <= 12) && (ano > 0 && ano <= 2018)) { //verifica se os numeros sao validos
		if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) { //verifica se o ano e bissexto
			return true;
		}
		else if (dia <= 28 && mes == 2) { //verifica o mes de feveireiro
			return true;
		}
		else if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) { //verifica os meses de 30 dias
			return true;
		}
		else if ((dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) { //verifica os meses de 31 dias
			return true;
		}
	}
	return false;
}

/* Lê o tipo de título do Tesouro Direto e uma data de venda, pesquisa no conjunto de dados
* importados e, se encontrar, exibe a data de vencimento, a quantidade e o valor total vendido do
* tipo de título escolhido na data pesquisada. Se não houver nenhuma venda desse título no dia
* consultado exibe a mensagem Nenhuma venda do título NomeTD foi realizada em DD/MM/AAA,
* onde DD/MM/AAA é a data de venda e NomeTD o nome do tipo de título pesquisados pelo
* usuário.*/
void tipoDeTitulo(Vetor &vetor) {
	string titulo, data;
	int op;

	do {
		exibeMensagem("\n ----------- Pesquisa no Tesouro Direto -----------\n");
		exibeMensagem("\nTítulo: ");

		titulo = lerString();

		exibeMensagem("\nData de venda (DD/MM/AAAA): ");

		data = lerString();

		int dataInt = ajustaData(data);

		if (pesquisaDataTitulo(dataInt, titulo, vetor) == 1)
			exibeMensagem("\nNenhuma venda do título" + titulo + " foi realizada em " + data + ".\n");


		exibeMensagem("\nDeseja realizar outra pesquisa? S/N");
		op = leChar();
		limparTela();
	} while (op != 'N');
}

/* Realiza a pesquisa no vetor de Vendas, verifica se existe uma transação correspondente com o titulo
* efetuada na data passada or argumento
* Caso encontre informações referentes a pesquisa o valor de retorno da função é 0, caso contrário retorna 1.
*/
int pesquisaDataTitulo(int dataInt, string titulo, Vetor &vetor) {
	int dataNoObjeto, retorno = 1;

	for (int i = 0; i < vetor.obterTamanhoVendas(); i++) {
		dataNoObjeto = ajustaData(vetor.obterVenda(i).getDataVenda());
		if (dataInt == dataNoObjeto && titulo.compare(vetor.obterVenda(i).getTitulo()) == 0) {
			vetor.exibirVendasPorData(i);
			retorno = 0;
		}
	}
	return retorno;
}

/* Realiza a pesquisa no vetor de Vendas, a partir do titulo passado por argumento,
* percorre o objeto e verifica se o titulo corresponde ao dados armazenados no objeto.
* Caso os titulos sejam iguais são exibidos os dados e o valor de retorno da função é 0, caso contrário retorna 1.
*/
int pesquisaPorTitulo(string titulo, Vetor &vetor) {
	int retorno = 1;

	for (int i = 0; i < vetor.obterTamanhoVendas(); i++) {
		if (titulo == vetor.obterVenda(i).getTitulo()) {
			vetor.exibirVendasPorData(i);
			retorno = 0;
		}
	}
	return retorno;
}
