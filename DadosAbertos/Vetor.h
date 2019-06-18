#ifndef VETOR_H
#define VETOR_H

#include <vector> 

#include "Investidor.h"
#include "Venda.h"

class Vetor {
public:
	Vetor();

	bool adicionarInvestidorString(string linha);
	bool adicionarVendaString(string linha);
	int obterTamanhoInvestidor();
	bool adicionarInvestidorNoObjeto(Investidor &investidor);
	bool adicionarVendaNoObjeto(Venda &venda);
	bool removeInvestidorNoObjeto();

	int obterTamanhoVendas();
	int obterTamanhoVendasString();
	int obterTamanhoInvestidorString();
	int obterQtdeLinhasInvestidorString();
	int obterQtdeLinhasVendaString();
	void exibirVendasPorData(int i);
	string & obterVendaString(int posicao);
	string & obterInvestidorString(int posicao);

	Venda & obterVenda(int posicao);
	Investidor & obterInvestidor(int posicao);
	
	void limpaVectorDeObjetosInvestidores();

private:
	vector<Investidor> investidores;
	vector<Venda> vendas;
	vector<string> investidor;
	vector<string> venda;
	int linhasArquivoInvestidor , linhasArquivoVenda;
};

#endif // !VETOR_H
