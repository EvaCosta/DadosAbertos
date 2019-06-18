#ifndef PESQUISA_H
#define PESQUISA_H

#include "Vetor.h"
#include "EntradaESaida.h"
#include "GerenciaDados.h"
/* Lê uma data de venda, pesquisa no conjunto de dados importados e, se encontrar, exibe os
* tipos de títulos do Tesouro Direto, a data de vencimento, a quantidade e o valor total vendido
* de cada título na data pesquisada. Se não houver nenhuma venda no dia consultado exibe a
* mensagem Nenhum tipo de título do Tesouro Direto foi vendido em DD/MM/AAA, onde DD/MM/AAA
* é a data de venda pesquisada.*/
void numeroVendas(Vetor &vetor);

/* Realiza a pesquisa no vetor de Vendas, a data armazenada no objeto venda é quebrada sendo retirado o delimitador "\".
* Os valores correspondentes a dia, mês e ano são somados e é feita a comparação entre a data passado por parametro e a data
* ajustada do objeto. Caso as datas sejam iguais são exibidos os dados e o valor de retorno da função é 0, caso contrário retorna 1.
*/
int pesquisaData(int dataInt, Vetor &vetor);

/* Recebe a data e a partir do delimitador "/" com o uso de strtok quebra a data e atribui para as variaveis
* dia, mes e ano respectivamente.
* Verifica se a data foi passada no formato correto DD/MM/AAAA, em caso negativo retorna -1 , caso contrário verifica se os
* valores referentes a dia, mes e ano estão corretos, em caso negativo retorna 1, caso contrário soma os valores das variaveis.
*/
int ajustaData(string data);

//Soma os valores da data
int dataInt(int dia, int mes, int ano);

//Valida se a data está correta.
bool verificaData(int dia, int mes, int ano);

/* Lê o tipo de título do Tesouro Direto e uma data de venda, pesquisa no conjunto de dados
* importados e, se encontrar, exibe a data de vencimento, a quantidade e o valor total vendido do
* tipo de título escolhido na data pesquisada. Se não houver nenhuma venda desse título no dia
* consultado exibe a mensagem Nenhuma venda do título NomeTD foi realizada em DD/MM/AAA,
* onde DD/MM/AAA é a data de venda e NomeTD o nome do tipo de título pesquisados pelo
* usuário.*/
void tipoDeTitulo(Vetor &vetor);

/* Realiza a pesquisa no vetor de Vendas, verifica se existe uma transação correspondente com o titulo
* efetuada na data passada or argumento
* Caso encontre informações referentes a pesquisa o valor de retorno da função é 0, caso contrário retorna 1.
*/
int pesquisaDataTitulo(int dataInt, string titulo, Vetor &vetor);

/* Realiza a pesquisa no vetor de Vendas, a partir do titulo passado por argumento,
* percorre o objeto e verifica se o titulo corresponde ao dados armazenados no objeto.
* Caso os titulos sejam iguais são exibidos os dados e o valor de retorno da função é 0, caso contrário retorna 1.
*/
int pesquisaPorTitulo(string titulo, Vetor &vetor);

#endif // !PESQUISA_H
