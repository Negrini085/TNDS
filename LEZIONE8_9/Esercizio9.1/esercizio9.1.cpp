#include "EquazioniDifferenziali.h"
#include "FunzioniVettoriali.h"
#include "OperazioniVector.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv){
	
	if(argc!= 2){
		cout << "Utilizzo del programma: " << argv[0] << " <numero di step>. " << endl;
		return -1;
	}

	TApplication myApp("myApp",0,0);
	TGraph sol;
	
	OscillatoreArmonico prova(1);
	double nstep = atof(argv[1]);
	double tmax = 70;
	double h = tmax/nstep;
	double t = 0;
	vector<double> x {0,1};

	Eulero lavora;
	//Evolvo la posizione e riempio il grafico
	for(int i = 0; i<nstep; i++){
		x = lavora.Passo(t, x, h, prova);
		sol.SetPoint(i, t, x[0]);
		t+=h;
	}

	sol.SetTitle("Soluzione; t; X");
  sol.GetXaxis()->CenterTitle(true);
  sol.GetYaxis()->CenterTitle(true);


	sol.Draw("ALP");
	myApp.Run();


	return 0;
}