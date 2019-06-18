#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#define CSE 218
#define CSD 191 
#define LH 196     
#define LV 179      
#define CIE 192    
#define CID 217
#define PREENCHIMENTO 219
#include <Windows.h>

class ProgressBar{
public:
	ProgressBar();
	ProgressBar(int x, int y , int comprimento);
	void showProgress(int valor);
	//void show();

private:
	int x, y, comprimento;
	bool barraCriada;

	void showShape(int x, int y, int comprimento);
};
#endif // !PROGRESS_BAR_H
