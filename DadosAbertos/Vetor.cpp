#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Vetor.h"

//Construtor default.
Vetor::Vetor(){}

//Adiciona o Objeto venda no final do vector.
bool Vetor::adicionarVendaString(string linha) {
	venda.push_back(linha);
	linhasArquivoVenda++;
	return true;
}

//Adiciona o Objeto investidor no final do vector.
bool Vetor::adicionarInvestidorString(string linha) {
	investidor.push_back(linha);
	linhasArquivoInvestidor++;
	return true;
}

//Armazena no vector de Investidores os dados.
bool Vetor::adicionarVendaNoObjeto(Venda &venda) {
	vendas.push_back(venda);
	return true;
}

//Armazena no vector de Investidores os dados.
bool Vetor::adicionarInvestidorNoObjeto(Investidor & investidor) {
	investidores.push_back(investidor);
	return true;
}

//Armazena no vector de Investidores os dados.
bool Vetor::removeInvestidorNoObjeto() {
	investidores.clear();
	return true;
}

int Vetor::obterTamanhoVendasString(){
	return venda.size();
}

int Vetor::obterTamanhoVendas() {
	return vendas.size();
}

int Vetor::obterTamanhoInvestidor() {
	return investidores.size();
}

//Obtém o tamanho do vector investidor.
 int Vetor::obterTamanhoInvestidorString() {
	return investidor.size();
}

 int Vetor::obterQtdeLinhasInvestidorString(){
	 return linhasArquivoInvestidor;
 }

 int Vetor::obterQtdeLinhasVendaString(){
	 return linhasArquivoVenda;
 }

 // Exibe de acordo com a posição passada por parametro os dados correspondentes no vector de Venda
void Vetor::exibirVendasPorData(int i) {
		cout << "\n-=> " << vendas[i].getTitulo() << "\n";
		cout << "\tData de Vencimento: " << vendas[i].getDataDeVencimento() << "\n";
		cout << "\tQuantidade: " << vendas[i].getQuantidade() << "\n";
		cout << "\tValor: R$ " << vendas[i].getValor() << "\n";
}

//Obtém e retorna a string de acordo com a posição. Retorna o objeto se a posição for válida e um objeto vazio caso contrário.
string & Vetor::obterVendaString(int posicao){
	string auxiliar;
	if (posicao >= 0 && posicao <= obterTamanhoVendasString()) {
		return venda.at(posicao);
	}
	return auxiliar;
}

//Obtém e retorna o objeto de acordo com a posição. Retorna o objeto se a posição for válida e um objeto vazio caso contrário.
Venda & Vetor::obterVenda(int posicao) {
	static Venda auxiliar;
	if (posicao >= 0 && posicao <= obterTamanhoVendas()) {
		return vendas[posicao];
	}
	return auxiliar;
}

//Obtém e retorna a string de acordo com a posição. Retorna o objeto se a posição for válida e um objeto vazio caso contrário.
string & Vetor::obterInvestidorString(int posicao) {
	string auxiliar;
	if (posicao >= 0 && posicao <= obterTamanhoInvestidorString()) {
	//	cout << "\n"<< investidor.at(posicao);
		return investidor[posicao];
	}
	return auxiliar;
}

//Obtém e retorna o objeto de acordo com a posição. Retorna o objeto se a posição for válida e um objeto vazio caso contrário.
Investidor & Vetor::obterInvestidor(int posicao) {
	static Investidor auxiliar;
	if (posicao >= 0 && posicao <= obterTamanhoInvestidor()) {
		//cout << "\nteste entrou aqui " << investidores[posicao].getEstadoCivil() << "!!!!";
		return investidores[posicao];
	}
	return auxiliar;
}

void Vetor::limpaVectorDeObjetosInvestidores(){
	investidores.clear();
}
