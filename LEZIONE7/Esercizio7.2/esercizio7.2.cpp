#include "Integrale.h"
#include "Funzioni.h"
#include "Runtime.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv){

	if(argc != 2){
		cout << "Funzionamento programma: " << argv[0] << " <precisione desiderata> " << endl;
		return -1;
	}

	Seno test(1,1);	double prec = atof(argv[1]); Trapezi calcola(0,M_PI);

	//Determino integrale con precisione desiderata
	vector<double> ris = Determina_Integrale(test, calcola, prec);

	cout << scientific;
	cout << "Il valore dell'integrale è: " << setprecision(ceil(-log10(ris[1]))) << ris[0] << " con una precisione di: " << setprecision(0) << ris[1] << " ottenuta con "  << setprecision(2) << ris[2] << " passi" << endl;

	return 0;
}