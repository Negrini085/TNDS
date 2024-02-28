#include "funzioni.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char** argv){

	if(argc<4){//errore in utilizzo del programma
    cout<<"Uso del programma:" << argv[0] << " <n_data> <filename input> <filename output>" << endl;
    return -1;
  }

  int ndati=atoi(argv[1]);
  double* dati = CaricaDaFile(argv[2], ndati);
	cout << endl << endl;
	cout << "Vettore caricato!!" << endl;

  cout << "La media dei dati selezionati è: " << CalcoloMedia(dati, ndati) << "." << endl;
  cout << "La varianza dei dati selezionati è: " << CalcoloVarianza(dati, ndati) << "." << endl;
	double* copia = Copia(dati, ndati);
	selection_sort(dati, ndati);
	cout  << "La mediana dei dati selezionati è: " << CalcoloMediana(dati, ndati) << "." << endl;
	cout << endl << endl;

	Stampa(argv[3], dati, ndati);
	cout << "I dati sono stati ordinati in ordine crescente e riportati nel file: "  << argv[3] << endl;
	cout << endl;



	delete[] dati;
	delete[] copia;
  return 0;
}
//Codici di errore
//-1   errore in utilizzo del programma (dati in entrata mancanti/errati)
//-2   richiesta di un numero troppo elevato di dati