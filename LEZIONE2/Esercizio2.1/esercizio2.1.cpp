#include <iostream>
#include <fstream>
#include <cstdlib>

#include "funzioni.h"
#include "Vettore.h"

using namespace std;

int main ( int argc, char** argv ) {

	if(argc<4){//errore in utilizzo del programma
    cout<<"Uso del programma:" << argv[0] << " <numero dati> <filename input> <filename output>" << endl;
    return -1;
  }

	int ndati = atoi(argv[1]);
	Vettore contenitore = Read(argv[2], ndati);

	Stampa(contenitore);

	cout << endl; //Calcolo media, varianza e mediana
	cout << "La media dei dati selezionati è la seguente: " << CalcoloMedia(contenitore) << "." << endl;
	cout << "La varianza dei dati selezionati è la seguente: " << CalcoloVarianza(contenitore) << "." << endl;
	cout << "La mediana dei dati selezionati è la seguente: " << CalcoloMediana(contenitore) << "." << endl << endl;

	cout << "I dati originali sono stati stampati anche sul file: " << argv[3] << endl;
	Stampa(argv[3], contenitore);

return 0;
}