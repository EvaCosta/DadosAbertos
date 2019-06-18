#ifndef RELATORIO_H
#define RELATORIO_H

//#include "Cabecalhos.h"
#include "GerenciaDados.h"
#include "Vetor.h"
#include "Pesquisa.h"

void menuRelatorio(Vetor &vetor, GerenciaDados &gerenciaDados);
void informacoesMenuRelatorio();
void escolheOpcaoMenuRelatorio(int opcao, Vetor &vetor, GerenciaDados &gerenciaDados);
void tituloDoTesouro(Vetor &vetor);
bool verificaMaiorData(int valorData1, int valorData2);
int pesquisaDataPorPeriodo(int valorDataInicial, int valorDataFinal, string dataInicial, string dataFinal, Vetor &vetor);
void investidoresPorEstadoCivil(Vetor &vetor);
void investidoresPorGenero(Vetor &vetor, GerenciaDados &gerenciaDados);
void investidoresPorRegiao(Vetor &vetor, GerenciaDados &gerenciaDados);
int verificaRegiao(string unidadeFederativa);

#endif // !RELATORIO_H
