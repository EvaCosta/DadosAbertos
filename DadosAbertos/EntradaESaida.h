#ifndef ENTRADA_E_SAIDA_H
#define ENTRADA_E_SAIDA_H

#include <string>

using namespace std;

void limparTela();

void promptUniversal();

void finalizarPrograma();

string lerString();

int lerDado();

char leChar();

void exibeMensagem(string mensagem);

double ajustaValor(string valor);

void ocultaCursor();
#endif // !ENTRADA_E_SAIDA_H