#include "funzioni.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1F.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main( int argc , char** argv ) {

  if ( argc != 4 ) {
    cout << "Uso del programma : " << argv[0] << " <numero dati> <nome file input> <nome file output> " << endl;
    return -1 ;
  }  

	//Leggo il numero di dati desiderato da file
	vector<double> dati = Leggi<double>(argv[2], atoi(argv[1]));

	//Creo l'istogramma
  TApplication app("app",0,0);
	TH1F histo ("histo","Valori caricati", 100, -10, 100); histo.StatOverflows( "kTRUE" );
	histo.GetXaxis() -> SetTitle("Valori");
	histo.GetYaxis() -> SetTitle("Numero dati per bin");

	//Riempio l'istogramma
  for ( int k = 0 ; k < dati.size() ; k++ ){ histo.Fill( dati[k] );} 
	cout << endl;

	//Calcolo i parametri statistici	
  cout << "Media dei valori caricati: " << histo.GetMean() << endl;
	cout << "Varianza dei valori caricati: " << pow(histo.GetStdDev(), 2) << endl;
	cout << "Mediana dei valori caricati: " << CalcoloMediana(dati) << endl;

	//Stampo i dati a file
	Stampa(dati, argv[3]);


	//Disegno l'istogramma
  TCanvas mycanvas("mycanvas","Istogramma");
  histo.Draw();


  app.Run();

return 0;  
}

/****************************************************
*                CODICI DI ERRORE:                  *
*	-1	Errore in passaggio parametri al main         *
*	-2	Errore in apertura/creazione file di output   *
* -3  Errore riguardante file di input              *
*****************************************************/
