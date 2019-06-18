#ifndef VENDA_H
#define VENDA_H

#include <cstring>
#include <ctime>

using namespace std;

class Venda {
public:
	// TAMANHO BYTES = 108
	Venda();
	Venda(string titulo, string vencimentoDoTitulo, string dataVenda, double precoUnitario, double quantidade, double valor);

	void setTitulo(string titulo);
	void setDataDeVencimento(string dataDeVencimento);
	void setDataVenda(string dataVenda);
	void setPrecoUnitario(double precoUnitario);
	void setQuantidade(double quantidade);
	void setValor(double valor);

	string getTitulo();
	string getDataDeVencimento();
	string getDataVenda();
	double getPrecoUnitario();
	double getQuantidade();
	double getValor();

private:
	string titulo;
	string dataDeVencimento, dataVenda;
	double precoUnitario;
	double valor, quantidade;
};

#endif // !VENDA_H