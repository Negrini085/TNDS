#include "funzioni.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;


int main( int argc , char** argv ) {

  if (argc != 4){
    cout << "Uso del programma : " << argv[0] << " <n_data> <nome file input> <nome file output> " << endl;
    return -1 ;
  }  
  
  int ndati = atoi(argv[1]);
	vector<double> dati = Leggi<double>(argv[2], ndati);
  Stampa(dati);
	cout << endl << endl;
  cout << "media    = " << CalcoloMedia<double>(dati) << endl;
  cout << "varianza = " << CalcoloVarianza<double>(dati) << endl;
  cout << "mediana  = " << CalcoloMediana<double>(dati) << endl; 
	cout << endl << endl;

	cout << "Il contenuto del vettore è riportato anche sul file: " << argv[3] << endl << endl;
  Stampa(dati, argv[3]);
  
return 0;
}

/****************************************************
*                CODICI DI ERRORE:                  *
*	-1	Errore in passaggio parametri al main         *
*	-2	Errore in apertura/creazione file di output   *
* -3  Errore riguardante file di input              *
*****************************************************/