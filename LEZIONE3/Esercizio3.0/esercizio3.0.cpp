#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "Vettore.h"
#include "funzioni.h"

int main ( int argc, char** argv ){

  if ( argc != 4 ) {
    cout << "Uso del programma : " << argv[0] << " <n_data> <nome file input> <nome file output> " << endl;
    return -1 ;
  }

  int ndati = atoi(argv[1]);
	Vettore<double> dati = Read<double>(argv[2], ndati);
  Stampa(dati);
	cout << endl << endl;
  cout << "media    = " << CalcoloMedia<double>(dati) << endl;
  cout << "varianza = " << CalcoloVarianza<double>(dati) << endl;
  cout << "mediana  = " << CalcoloMediana<double>(dati) << endl; 
	cout << endl << endl;

	cout << "Il contenuto del vettore è riportato anche sul file: " << argv[3] << endl << endl;
  Stampa(argv[3], dati);
  
return 0;
}

/*CODICI DI ERRORE:
  -1   Errore in passaggio parametri al main
  -2   Errore per indice troppo grande
	-3	 Errore per file non esistente
	-4 	 Errore per end of file
	-5	 Mancata apertura file di output*/