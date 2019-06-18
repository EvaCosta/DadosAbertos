#include <iostream>
#include "Venda.h"

Venda::Venda() {
	precoUnitario = 0;
	quantidade = 0;
	valor = 0;
}

Venda::Venda(string titulo, string vencimentoDoTitulo, string dataVenda, double precoUnitario, double quantidade, double valor) {
	this->titulo = titulo;
	this->dataDeVencimento = vencimentoDoTitulo;
	this->dataVenda = dataVenda;
	this->precoUnitario = precoUnitario;
	this->quantidade = quantidade;
	this->valor = valor;
}

void Venda::setTitulo(string titulo) {
	this->titulo = titulo;
}

void Venda::setDataDeVencimento(string vencimentoDoTitulo) {
	this->dataDeVencimento = vencimentoDoTitulo;
}

void Venda::setDataVenda(string dataVenda) {
	this->dataVenda = dataVenda;
}

void Venda::setPrecoUnitario(double precoUnitario) {
	this->precoUnitario = precoUnitario;
}

void Venda::setQuantidade(double quantidade) {
	this->quantidade = quantidade;
}

void Venda::setValor(double valor) {
	this->valor = valor;
}

string Venda::getTitulo() {
	return titulo;
}

string Venda::getDataDeVencimento() {
	return dataDeVencimento;
}

string Venda::getDataVenda() {
	return dataVenda;
}

double Venda::getPrecoUnitario() {
	return precoUnitario;
}

double Venda::getQuantidade() {
	return quantidade;
}

double Venda::getValor() {
	return valor;
}
