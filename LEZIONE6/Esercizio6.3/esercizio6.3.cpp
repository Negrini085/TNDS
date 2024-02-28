#include "Funzioni.h"
#include "Bisezione.h"


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv){

	//Controllo sui parametri passati
	if(argc != 3){
		cout << "Funzionamento programma: " << argv[0] << " <precisione richiesta> <numero massimo iterazioni>" << endl;
		cout << "Numero massimo iterazioni: numero massimo di bisezioni consentite per ottenere la precisione richiesta." << endl;
		return -1;
	}

	//Precisione richiesta e numero massimo iterazioni
	double prec = atof(argv[1]); int nmax = atoi(argv[2]);
	//Funzione e "cercatore" dello zero
	Bisezione Ricerca(prec, nmax); 	DaValutare test;

	double appo, ncifre;

	for(int i=1; i<=20; i++){
		//Determino lo zero e valuto le cifre significative
		appo = Ricerca.CercaZeri(i*M_PI, i*M_PI+M_PI/2, test);
		ncifre = ceil(-log10(Ricerca.GetPrecision()));
		cout << fixed;
		cout << "Nell'intervallo: (" << setw(2) << i << "π" << ", " << setw(2) << 2* i + 1 << "π/2) la funzione si annulla in: "<< setprecision(ncifre) << appo << " +/- " << Ricerca.GetPrecision() << "." << endl;

		//Riporto m_precisione al valore inserito da terminale e pongo a zero n_it
		Ricerca.SetPrecision(prec); Ricerca.SetN(0);
		
	}

return 0;
}