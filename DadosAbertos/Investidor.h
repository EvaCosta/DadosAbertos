#ifndef INVESTIDOR_H
#define INVESTIDOR_H

#include<time.h>
#include<string>

using namespace std;
class Investidor {
public:
	Investidor();
	Investidor(int codigo, int idade, string dataDeAdesao, string estadoCivil, string genero,
		string profissao, string cidadeInvestidor, string paisInvestidor, string uf, bool situacaoConta, bool operou1Ano);

	void setCodigo(int codigo);
	void setIdade(int idade);
	void setDataDeAdesao(string dataDeAdesao);
	void setEstadoCivil(string estadoCivil);
	void setGenero(string genero);
	void setProfissao(string profissao);
	void setCidadeInvestidor(string cidadeInvestidor);
	void setPaisInvestidor(string paisInvestidor);
	void setUf(string uf);
	void setSituacaoConta(string situacaoConta);
	void setOperou1Ano(string operou1Ano);
	void setLinhaCompleta(char *linha);

	int getCodigo();
	int getIdade();
	string getDataDeAdesao();
	string getEstadoCivil();
	string getGenero();
	string getProfissao();
	string getCidadeInvestidor();
	string getPaisInvestidor();
	string getUf();
	string getSituacaoConta();
	string getOperou1Ano();
	string getLinhaCompleta();
private:
	int codigo;
	int idade;
	string dataDeAdesao;
	string estadoCivil, genero, profissao, cidadeInvestidor, paisInvestidor;
	string uf;
	string situacaoConta, operou1Ano;
	string linhaCompleta;
};

#endif // !INVESTIDOR_H
