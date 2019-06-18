#include <iostream>
#include <conio.h>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <Windows.h>
#include "EntradaESaida.h"

void exibeMensagem(string mensagem) {
	cout << mensagem;
}

double ajustaValor(string valor){
	  valor.erase(remove(valor.begin(), valor.end(), '.'), valor.end());
	
	  return  stod(valor);
}

void limparTela() {
	system("cls||clear");
}

void promptUniversal() {
	cout << "\n\n";
	system("pause");
}

void finalizarPrograma() {
	exibeMensagem("\nPrograma finalizado com sucesso. ");
}

string lerString() {
	string dado;

	do {
		getline(cin, dado);
	} while (dado == "");

	return dado;
}

int lerDado() {
	int dado;

	cin >> dado;

	return dado;
}

char leChar(){
	char opcao;

	cin >> opcao;

	opcao = toupper(opcao);
	return opcao;
}

void ocultaCursor(){
	CONSOLE_CURSOR_INFO cursor = { 1, FALSE };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}