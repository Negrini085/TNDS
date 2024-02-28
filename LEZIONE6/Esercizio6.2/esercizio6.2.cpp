#include "FunzioneBase.h"
#include "Bisezione.h"
#include "Solutore.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
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
	Parabola cavia(3,5,-2); Bisezione Ricerca(prec, nmax);
	
	//Cerco lo zero
	double appo = Ricerca.CercaZeri(0, 1, cavia);
	//Numero di cifre significative
	int ncifre = ceil(-log10(Ricerca.GetPrecision()));

	cout << fixed;
	cout << setprecision(ncifre) << "La funzione analizzata assume lo zero in: x=("<< appo << " +/- " << Ricerca.GetPrecision() << ")" << endl;

return 0;
}