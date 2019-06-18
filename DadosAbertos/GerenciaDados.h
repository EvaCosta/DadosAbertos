#ifndef GERENCIA_DADOS_H
#define GERENCIA_DADOS_H

#include <iostream>
#include "Investidor.h"
#include "Venda.h"
#include "Vetor.h"
#include "ArquivoTexto.h"


class GerenciaDados{
public:
	GerenciaDados();

	bool adicionaDadosNoObjeto(Vetor &vetor, int tipoArquivo,int ocultaBarra);

	/* Quebra a string separando os dados a partir do delimitador ";"
	* Armazena os dados obtidos a partir da string em um Objeto.
	* Retorna o objeto estático investidor.
	*/
	Investidor leituraDeDadosVetorInvestidor(char *linha);

	Venda leituraDeDadosVetorVenda(char *linha);

private:

};

#endif // !GERENCIA_DADOS_H
