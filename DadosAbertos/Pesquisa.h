#ifndef PESQUISA_H
#define PESQUISA_H

#include "Vetor.h"
#include "EntradaESaida.h"
#include "GerenciaDados.h"
/* L� uma data de venda, pesquisa no conjunto de dados importados e, se encontrar, exibe os
* tipos de t�tulos do Tesouro Direto, a data de vencimento, a quantidade e o valor total vendido
* de cada t�tulo na data pesquisada. Se n�o houver nenhuma venda no dia consultado exibe a
* mensagem Nenhum tipo de t�tulo do Tesouro Direto foi vendido em DD/MM/AAA, onde DD/MM/AAA
* � a data de venda pesquisada.*/
void numeroVendas(Vetor &vetor);

/* Realiza a pesquisa no vetor de Vendas, a data armazenada no objeto venda � quebrada sendo retirado o delimitador "\".
* Os valores correspondentes a dia, m�s e ano s�o somados e � feita a compara��o entre a data passado por parametro e a data
* ajustada do objeto. Caso as datas sejam iguais s�o exibidos os dados e o valor de retorno da fun��o � 0, caso contr�rio retorna 1.
*/
int pesquisaData(int dataInt, Vetor &vetor);

/* Recebe a data e a partir do delimitador "/" com o uso de strtok quebra a data e atribui para as variaveis
* dia, mes e ano respectivamente.
* Verifica se a data foi passada no formato correto DD/MM/AAAA, em caso negativo retorna -1 , caso contr�rio verifica se os
* valores referentes a dia, mes e ano est�o corretos, em caso negativo retorna 1, caso contr�rio soma os valores das variaveis.
*/
int ajustaData(string data);

//Soma os valores da data
int dataInt(int dia, int mes, int ano);

//Valida se a data est� correta.
bool verificaData(int dia, int mes, int ano);

/* L� o tipo de t�tulo do Tesouro Direto e uma data de venda, pesquisa no conjunto de dados
* importados e, se encontrar, exibe a data de vencimento, a quantidade e o valor total vendido do
* tipo de t�tulo escolhido na data pesquisada. Se n�o houver nenhuma venda desse t�tulo no dia
* consultado exibe a mensagem Nenhuma venda do t�tulo NomeTD foi realizada em DD/MM/AAA,
* onde DD/MM/AAA � a data de venda e NomeTD o nome do tipo de t�tulo pesquisados pelo
* usu�rio.*/
void tipoDeTitulo(Vetor &vetor);

/* Realiza a pesquisa no vetor de Vendas, verifica se existe uma transa��o correspondente com o titulo
* efetuada na data passada or argumento
* Caso encontre informa��es referentes a pesquisa o valor de retorno da fun��o � 0, caso contr�rio retorna 1.
*/
int pesquisaDataTitulo(int dataInt, string titulo, Vetor &vetor);

/* Realiza a pesquisa no vetor de Vendas, a partir do titulo passado por argumento,
* percorre o objeto e verifica se o titulo corresponde ao dados armazenados no objeto.
* Caso os titulos sejam iguais s�o exibidos os dados e o valor de retorno da fun��o � 0, caso contr�rio retorna 1.
*/
int pesquisaPorTitulo(string titulo, Vetor &vetor);

#endif // !PESQUISA_H
