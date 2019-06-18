#ifndef DADOS_ABERTOS_S
#define DADOS_ABERTOS_H

#include <iostream>
#include <clocale>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ArquivoTexto.h"
#include "EntradaESaida.h"
#include "Vetor.h"
#include "ProgressBar.h"
#include "Console.h"
#include "GerenciaDados.h"

int main();
int iniciar();

void dadosAbertos(Vetor &vetor, GerenciaDados &gerenciaDados);

void menu();;
void escolheOpcao(int opcao, Vetor &vetor, GerenciaDados &gerenciaDados);

void importarDados(Vetor &vetor/*, GerenciaDados &gerenciaDados*/);

/*  A partir do nome do arquivo é realizada a abertura do mesmo, em caso de sucesso é iniciada a leitura
*  Caso contrário é informado ao usuário que o arquivo não pode ser aberto.
*/
int analisarArquivo(string nomeArquivo, Vetor &vetor/*, GerenciaDados &gerenciaDados*/, int verificador);

/* Exibe a barra de progresso no console
* A partir do tamanho do arquivo é feito o calculo para exibir o preenchimento da barra.
*/
//void barraDeProgresso(double numLinhas, int verificador);

void menuConsulta(Vetor &vetor);
void informacoesMenu();
void escolheOpcaoMenuConsulta(int opcao, Vetor &vetor);
void tituloDoTesouro(Vetor &vetor);
bool verificaMaiorData(int valorData1, int valorData2);
int pesquisaDataPorPeriodo(int valorData1, int valorData2, Vetor & vetor);

#endif // !DADOS_ABERTOS_H
