#include "ProgressBar.h"
#include "Console.h"
#include <iostream>

using namespace std;

ProgressBar::ProgressBar() {}

ProgressBar::ProgressBar(int x, int y, int comprimento){
	this->x = x;
	this->y = y;
	this->comprimento = comprimento;
	barraCriada = false;
	showShape(x, y, comprimento);
}

/*Exibe o preenchimento e a porcentagem da barra de progresso na tela.
 */
void ProgressBar::showProgress(int valor){

	double progressoDaBarra = 100.0f / comprimento;

	if (valor <= comprimento) {
		if(valor == 0 ) 	
			Console::gotoxy(x + 2 + valor, y+1);
		else	
			Console::gotoxy(x + valor, y + 1);

		Console::textColor(Background::MAGENTA, Foreground::MAGENTA);
		cout << (char)(PREENCHIMENTO);
		
		//Se a porcentagem for menor do que a metade do comprimento da barra, o background permanece da cor padrão.
		if (valor > (comprimento / 2) -2)
			Console::textColor(Background::MAGENTA, Foreground::WHITE);
		//Caso contrário o background é alterado.
		else
			Console::textColor(Background::BLACK, Foreground::LIGHT_GRAY);
		
		Console::gotoxy(comprimento / 2 + 5 , y + 1);	
		
		cout << int(valor*progressoDaBarra) << "%";
		Console::textColor(Background::BLACK, Foreground::LIGHT_GRAY);
	}
}

/* Posiciona o cursor de acordo com as coordenadas x e y.
 * Utilizando os caracteres da tabela ASCII exibe o contorno da barra de progresso na tela.
 */
void ProgressBar::showShape(int x, int y, int comprimento){
	setlocale(LC_ALL, ".850");

	Console::gotoxy(x, y); cout << (char)(CSE);
	for (int i = 0; i < comprimento; i++)
		 cout << (char)(LH);
	
	cout << (char)(CSD);
	
	
	Console::gotoxy(x, y + 1); cout << (char)(LV);

	Console::gotoxy(comprimento + 7, y + 1); cout << (char)(LV);

	Console::gotoxy(x, y + 2); cout << (char)(CIE);

	for (int i = 1; i < comprimento + 1; i++) 
		cout << (char)(LH);
	
	cout << (char)(CID);

	barraCriada = true;
	//setlocale(LC_ALL, ".1252");
}
/* Exibe a barra de progresso no console
* A partir do tamanho do arquivo é feito o calculo para exibir o preenchimento da barra.
*/
//void ProgressBar::show(int valor) {
//	showProgress();
//}