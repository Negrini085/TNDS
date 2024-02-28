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

	cout << "I dati presi in ingresso sono: " << endl;
	Stampa(dati, ndati);
	
  cout  << endl << "La media dei dati selezionati è: " << CalcoloMedia(dati, ndati) << "." << endl;
  cout << "La varianza dei dati selezionati è: " << CalcoloVarianza(dati, ndati) << "." << endl << endl;
	cout << "Copio i dati originali in un secondo vettore per riordinarli!!" << endl;
	double* copia = Copia(dati, ndati);	selection_sort(copia, ndati);
	cout << "Riordinamento effettuato!!" << endl << endl;
	cout  << "La mediana dei dati selezionati è: " << CalcoloMediana(copia, ndati) << "." << endl << endl << endl;
	cout << "I dati sono stati ordinati in ordine crescente e riportati nel file: "  << argv[3] << endl;
	cout << endl << endl;

	Stampa(argv[3], copia, ndati);

	delete[] dati;
	delete[] copia;
  return 0;
}

//Codici di errore
//-1   errore in utilizzo del programma (dati in entrata mancanti/errati)
//-2   richiesta di un numero troppo elevato di dati