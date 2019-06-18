#include <iostream>
#include <locale>
#include "ProgressBar.h"
#include "Console.h"

using namespace std;

int testar() {
	setlocale(LC_ALL, ".850");
	ProgressBar vendasProgreeBar(6, 5, 58), investidoresProgreeBar(6, 10, 58);
	
	//Console::clrscr();
	Console::textColor(Background::BLACK, Foreground::YELLOW);
	Console::gotoxy(1, 1); cout << "Importando os dados do Tesouro Direto...";

	Console::gotoxy(3, 4); cout << "1. Vendas do Tesouro Direto";
	Console::gotoxy(3, 9); cout << "2. Investidores do Tesouro Direto";
	for (int p = 1; p <= 15000; p++) 
		vendasProgreeBar.show(p / 30000.0 * 100);
	

	for (int p = 1; p <= 100000; p++)
		investidoresProgreeBar.show(p / 200000.0 * 100);

	cout << endl << endl << endl;
	Console::textColor(Background::BLACK, Foreground::LIGHT_GRAY);
	cout << endl;
	return 0;
}

int main() {
	return testar();
}