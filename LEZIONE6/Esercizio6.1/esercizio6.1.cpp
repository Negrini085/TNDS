#include "Funzioni.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char** argv){

	if(argc != 4) {
		cout << "Funzionamento programma: " << argv[0] << " <primo coefficiente> <secondo coefficiente> <terzo coefficiente> " << endl;
		exit(-1);
	}

	
	Parabola prova(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	cout << prova.Eval(-prova.GetB()/(2*prova.GetA())) << endl;

return 0;
}