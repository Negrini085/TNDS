#include "IntegraliMontecarlo.h"
#include "GenRandom.h"
#include "Funzioni.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){

	int num = 10000; MonteCarlo integra; Seno funz(1);
	vector<double> estrazioni {100, 500, 1000, 5000, 10000, 50000};

	cout << endl << "Stampo valori a file! " << endl;

	//Output su file
	ofstream fileoutMED; fileoutMED.open("Media.dat");
	ofstream fileoutHM; fileoutHM.open("HitMiss.dat");

	//Calcolo i valori
	for(int j=0; j<estrazioni.size(); j++) {
		//Calcolo valore integrale a Ntot fissato num volte
		for(int i=0; i<num; i++) { 
			fileoutMED << integra.MED(0, M_PI, estrazioni[j], funz) << " ";
			fileoutHM << integra.HM(0, M_PI, estrazioni[j], funz, 1) << " ";
			} 
		fileoutMED << endl; fileoutHM << endl;
	}
	fileoutMED.close(); fileoutHM.close();

	cout << endl << "Valori generati: eseguire 'Grafici' per visualizzare l'andamento dell'errore" << endl << endl;

return 0;
}