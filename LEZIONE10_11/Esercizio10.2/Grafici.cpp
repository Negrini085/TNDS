#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TF1.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main() {

	double appo; string tmp1, tmp2; int num = 10000; 
	vector<int> estrazioni {100, 500, 1000, 5000, 10000, 50000};
	vector<string> metodi {"Media", "Hit/Miss"};
	vector<string> nomi_file { "Media.dat", "HitMiss.dat"};
	vector<double> dev;
	ifstream filein;
	

	TApplication myApp("myApp", 0, 0); 
	

	for(int k=0; k<2; k++) {
		tmp1 = "c" + metodi[k]; tmp2 = "Metodo " + metodi[k];
		//Creo la canvas e la divido in pad come desiderato
		TCanvas * c1 = new TCanvas(tmp1.c_str(), tmp2.c_str()); c1 -> Divide(2, 3);
		//Apro la comunicazione con il file di input
		filein.open(nomi_file[k].c_str()); 
		if(!filein) { cout << "File di input non trovato: esco!!" << endl; exit(-3); }

		//Disegno i grafici sulle varie pad
		for(int i=0; i<6; i++){
		c1 -> cd(i+1);
		tmp1 = metodi[k] + to_string(estrazioni[i]);
		tmp2 = "Integrale metodo " + metodi[k] + ":" + to_string(estrazioni[i]) + " punti";
		TH1F* histo = new TH1F(tmp1.c_str(), tmp2.c_str(), 200, 1.5, 2.5);
		histo -> StatOverflows( "kTRUE" );
		
		//Riempio il TH1F con i valori generati da CalcoloIntegrali
		for(int j=0; j<num; j++) {
			filein >> appo;	histo -> Fill(appo);
		}
		dev.push_back(histo -> GetStdDev());
		histo -> Draw();
	}
	filein.close();
	}

	cout << "Verifica dell'andamento dell'errore in funzione del numero di punti: " << endl << endl;

	for(int i=0; i<2; i++) {
		//Titoli per canvas
		tmp2 = "err" + to_string(i+1); tmp1 = "Andamento errore: Metodo" + metodi[i];
		TCanvas* err = new TCanvas(tmp2.c_str(), tmp1.c_str());

		TGraph* errore = new TGraph(); tmp2 = "Andamento errore: metodo " + metodi[i] + "; Numero; Errore";
		errore -> SetTitle(tmp2.c_str());
		errore -> GetXaxis() -> CenterTitle(); errore -> GetYaxis() -> CenterTitle();

		//Riempio il grafico
		for(int k=0; k<dev.size()/2.; k++) {
			errore -> SetPoint(k, estrazioni[k], dev[k + i * dev.size()/2]);
		}

		//Funzione per fit
		tmp1 = "f" + to_string(i); TF1* f = new TF1(tmp1.c_str(),"[0]/sqrt(x)",0., 51000);
		cout << endl << "Fit: metodo " + metodi[i] << endl; errore -> Fit(f);

		cout << endl << endl << endl;
		//Numero di estrazioni necessarie per avere una certa precisione
		cout << "Numero di estrazioni necessarie per ottenere una precisione di 0.001  con metodo della Media: " << pow(f -> GetParameter(0)/0.001 ,2) << "." << endl << endl << endl;

		errore -> Draw("ALP");		
	}

	myApp.Run();	
return 0;
}