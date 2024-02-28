#include "Viscosità.h"
#include "GenRandom.h"
#include "Grafici.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TF1.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv){

	if(argc != 2) {
		cout << "Funzionamento programma: " << argv[0] << " <numero di simulazioni desiderate> " << endl;
		return -1;
	}

	string tmp, tmp1;
	int nsim = atoi(argv[1]); 
	vector<double> raggi { 0.005, 0.01};
	Viscosita esperimento(raggi[0]);

	TApplication myApp("myApp", 0, 0);

	//Effettuo la simulazione considerando tutte le fonti di errore
	Simulazioni_3errori(esperimento, nsim, raggi);

	//Simulazione: fonte d'errore misura del raggio
	Simulazioni_ErroreSulRaggio(esperimento, nsim, raggi);

	//Simulazione: fonte d'errore misure delle posizioni
	Simulazioni_ErroreSullePosizioni(esperimento, nsim, raggi);

	//Simulazione: fonte d'errore misura dell'intervallo temporale
	Simulazioni_ErroreSulTempo(esperimento, nsim, raggi);

	
	myApp.Run();


return 0;
}