#include "FunzioniScalari.h"
#include "MonteCarlo2D.h"
#include "GenRandom.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
	
	ofstream fileout; MonteCarlo2D integra; Integranda f;
	vector<int> estrazioni {100, 500, 1000, 5000, 10000, 50000};
	vector<double> xlim {1, 2}; vector<double> ylim {1, 2};

	fileout.open("Media.dat"); 
	if(!fileout) { cout << "Problemi in apertura file output: esco!" << endl; return -1;}

	//Valuto integrali
	for(int j=0; j<estrazioni.size(); j++) {

		integra.SetN(estrazioni[j]);
		for(int k=0; k<10000; k++) { fileout << integra.MED(f, xlim, ylim) << " "; }

	fileout << endl;
	}

	fileout.close();

return 0;	
}