#include "EquazioniDifferenziali.h"
#include "FunzioniVettoriali.h"
#include "OperazioniVector.h"
#include "funzioni.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TAxis.h"


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv){

	if(argc != 2){
		cout << "Utilizzo del programma: " << argv[0] << " <numero di step>" << endl;
		return -1;
	}
	int nstep = atoi(argv[1]);

	if(nstep < 1) { 
		cout << "Numero di step non valido: esco!!" << endl;
	return -2;
	}

	
	OscillatoreArmonico oscillatore(1);
	double tmax = 70; 	 	

	//Eulero e Runge Kutta da confrontare
	Eulero eul; RungeKutta4 kutta4;

	TApplication myApp("myApp", 0, 0);

	//Creo grafici pos vs tempo - stampo a video errore commesso a tmax
	Confronto_Metodi(tmax, nstep, oscillatore, eul, kutta4);
	
	//Determino andamento errori nei due metodi
	vector<double> err = errori(tmax, oscillatore, eul, kutta4);
	
	//Grafico ora l'errore del Metodo di Runge Kutta
	Visualizza_Andamento_Errore(err, tmax);	
	
	

	myApp.Run();

	return 0;
}

