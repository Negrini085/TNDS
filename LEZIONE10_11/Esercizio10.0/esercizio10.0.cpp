#include "GenRandom.h"

#include <iostream>
#include <cstdlib>

#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH1F.h"



using namespace std;

int main(int argc, char** argv){

	if(argc != 3) {
		cout << "Funzionamento programma: " << argv[0] << " <numero valori casuali desiderati> <numero di bin> " << endl;
		return -1;
	}

	double x1, x2, x3, x4;
	GenRandom generatore(1);
	int npunti = atoi(argv[1]);
	int nbin = atoi(argv[2]);
	double min = 5; double max = 10;
	



	TApplication myApp("myApp", 0, 0);
	TH1F *isto1 = new TH1F("isto1", "Probabilita' uniforme", nbin, 5, 10);
	TH1F *isto2 = new TH1F("isto2", "Probabilita' esponenziale", nbin, 0, 20);
	TH1F *isto3 = new TH1F("isto3", "Probabilita' gaussiana A/R", nbin, 0, 20);
	TH1F *isto4 = new TH1F("isto4", "Probabilita' gaussiana", nbin, 0, 20);

	isto1->StatOverflows( "kTRUE" ); isto2->StatOverflows( "kTRUE" ); 
	isto3->StatOverflows( "kTRUE" ); isto4->StatOverflows( "kTRUE" );
	

	for(int i=0; i<npunti; i++) {
		x1 = generatore.Unif(min, max); x2 = generatore.Exp(1); 
		x3 = generatore.GaussAR(10,1); x4 = generatore.GaussBM(10, 1);

		isto1->Fill(x1); isto2->Fill(x2); 
		isto3->Fill(x3); isto4->Fill(x4); 

		}

	TCanvas* c1 = new TCanvas("c1", "Uniforme"); TCanvas* c2 = new TCanvas("c2", "Esponenziale"); 
	TCanvas* c3 = new TCanvas("c3", "Gaussiana A/R"); TCanvas* c4 = new TCanvas("c4", "Gaussiana Box-Muller");

	c1 -> cd(); isto1 -> Draw();
	c2 -> cd(); isto2 -> Draw();
	c3 -> cd(); isto3 -> Draw();
	c4 -> cd(); isto4 -> Draw();
	myApp.Run();

	return 0;
}