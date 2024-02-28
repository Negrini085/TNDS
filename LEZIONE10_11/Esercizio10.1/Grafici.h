#ifndef __Grafici_h__
#define __Grafici_h__

#include "GenRandom.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TF1.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void AndamentoDistribuzioneSomme(const vector<double>& estrazioni, const vector<int>& n_dasom, vector<double>& var){
	//Variabili  di appoggio (cambiamento titoli dei grafici e somme)
	string tmp, tmp1; 
	double appo; int k, nsom;

	//Creo la canvas e la divido
	TCanvas* c = new TCanvas("c", "Andamento della distribuzione delle somme"); c -> Divide(3, 2);

	for(int i=0; i < n_dasom.size(); i++){
		//Scrivo gli opportuni titoli
		tmp = "somme" + to_string(n_dasom[i]);
		tmp1 = "Distribuzione somme: " + to_string(n_dasom[i]) + " addendi";
		//Genero l'istogramma, calcolo numero somme e mi posiziono in pad desiderata
		TH1F* somme = new TH1F(tmp.c_str(), tmp1.c_str(), 100, 0, n_dasom[i]);
		nsom = estrazioni.size()/n_dasom[i]; c -> cd(i + 1);
		//Riempio l'istogramma
		for(int j = 0; j<nsom; j++){
			appo = 0; k = j;
			do{ appo += estrazioni[k]; k++; }while(k < j + n_dasom[i]);
			somme -> Fill(appo);
		}
		somme -> Draw(); var.push_back( pow(somme -> GetStdDev(), 2));
	}
}



//Come scala la varianza
void ScaloVarianza(const vector<double>& var, const vector<int>& n_dasom){

	TCanvas* c2 = new TCanvas("c2", "Andamento Varianza");
	//Dichiaro il grafico e la funzione con cui verrà effettuato il fit
	TGraph* andVar = new TGraph(); andVar -> SetTitle("Andamento Varianza; Numero; Varianza");
	andVar -> GetXaxis() -> CenterTitle( true ); andVar -> GetYaxis() -> CenterTitle( true );
	TF1* f = new TF1("f", "pow([0], 2)*x", 0, 40);

	//Riempio il TGraph
	for(int i=0; i<var.size(); i++) { andVar -> SetPoint(i, n_dasom[i], var[i]);}
	cout << "Fit andamento della varianza: " << endl;
	andVar -> Fit(f); andVar -> Draw("ALP");

	cout << endl << "Il coefficiente angolare della retta è: " << f -> GetParameter(0) << "." << endl;

}



#endif //__Grafici_h__