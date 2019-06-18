#include "Investidor.h"

Investidor::Investidor() {
	codigo = idade = 0;
}

Investidor::Investidor(int codigo, int idade, string dataDeAdesao, string estadoCivil, string genero,
	string profissao, string cidadeInvestidor, string paisInvestidor, string uf, bool situacaoConta, bool operou1Ano) {
	this->codigo = codigo;
	this->idade = idade;
	this->dataDeAdesao = dataDeAdesao;
	this->estadoCivil = estadoCivil;
	this->genero = genero;
	this->profissao = profissao;
	this->cidadeInvestidor = cidadeInvestidor;
	this->paisInvestidor = paisInvestidor;
	this->uf = uf;
	this->situacaoConta = situacaoConta;
	this->operou1Ano = operou1Ano;
}
void Investidor::setCodigo(int codigo) {
	this->codigo = codigo;
}
void Investidor::setIdade(int idade) {
	this->idade = idade;
}
void Investidor::setDataDeAdesao(string dataDeAdesao) {
	this->dataDeAdesao = dataDeAdesao;
}
void Investidor::setEstadoCivil(string estadoCivil) {
	this->estadoCivil = estadoCivil;
}
void Investidor::setGenero(string genero) {
	this->genero = genero;
}
void Investidor::setProfissao(string profissao) {
	this->profissao = profissao;
}
void Investidor::setCidadeInvestidor(string cidadeInvestidor) {
	this->cidadeInvestidor = cidadeInvestidor;
}
void Investidor::setPaisInvestidor(string paisInvestidor) {
	this->paisInvestidor = paisInvestidor;
}
void Investidor::setUf(string uf) {
	this->uf = uf;
}
void Investidor::setSituacaoConta(string situacaoConta) {
	this->situacaoConta = situacaoConta;
}
void Investidor::setOperou1Ano(string operou1Ano) {
	this->operou1Ano = operou1Ano;
}

void Investidor::setLinhaCompleta(char * linha){
	linhaCompleta = linha;
}

int Investidor::getCodigo() {
	return codigo;
}
int Investidor::getIdade() {
	return idade;
}
string Investidor::getDataDeAdesao() {
	return dataDeAdesao;
}
string Investidor::getEstadoCivil() {
	return estadoCivil;
}
string Investidor::getGenero() {
	return genero;
}
string Investidor::getProfissao() {
	return profissao;
}
string Investidor::getCidadeInvestidor() {
	return cidadeInvestidor;
}
string Investidor::getPaisInvestidor() {
	return paisInvestidor;
}
string Investidor::getUf() {
	return uf;
}
string Investidor::getSituacaoConta() {
	return situacaoConta;
}
string Investidor::getOperou1Ano() {
	return operou1Ano;
}

string Investidor::getLinhaCompleta(){
	return linhaCompleta;
}
