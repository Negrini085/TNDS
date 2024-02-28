#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TF1.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv){

	if(argc != 2){ cout << "Funzionamento programma: " << argv[0] << " <precisione desiderata>" << endl; return -1; }

	double prec = atof(argv[1]); double appo; 
	int num = 10000; string tmp1, tmp2;

	vector<int> estrazioni {100, 500, 1000, 5000, 10000, 50000};
	vector<double> dev; ifstream filein;

	//Canvas per distribuzione valori
	TApplication myApp("myApp", 0, 0);
	TCanvas* c = new TCanvas("c", "Metodo della Media"); c -> Divide(2, 3);
	//Apro stream file
	filein.open("Media.dat"); 
	if(!filein) { cout << "File di input non trovato: esco!!" << endl; return -3; }

	//Disegno i grafici sulle varie pad
	for(int i=0; i<6; i++){
		//Titoli per istogramma
		tmp1 = "Media" + to_string(estrazioni[i]);
		tmp2 = "Integrale metodo Media:" + to_string(estrazioni[i]) + " punti";
		//Istogramma
		TH1F* histo = new TH1F(tmp1.c_str(), tmp2.c_str(), 200, 9.7, 10.9);
		histo -> StatOverflows( "kTRUE" );
		
		//Riempio il TH1F con i valori generati da CalcoloIntegrali
		for(int j=0; j<num; j++) { filein >> appo;	histo -> Fill(appo); }
		dev.push_back(histo -> GetStdDev()); c -> cd(i+1); histo -> Draw();
	}
	filein.close();

	//Studio l'andamento della deviazione standard
	TCanvas* err1 = new TCanvas("err1", "Andamento errore: metodo della media");
	TGraph erroreM; erroreM.SetTitle("Andamento errore: metodo della Media; Numero; Errore");
	erroreM.GetXaxis() -> CenterTitle(); erroreM.GetYaxis() -> CenterTitle();

	//Riempio TGraph
	for(int i=0; i<6; i++) { erroreM.SetPoint(i, estrazioni[i], dev[i]); }

	//Eseguo il fit
	TF1* f1 = new TF1("f","[0]/sqrt(x)",0., 51000);
	cout << "Fit metodo della Media: " << endl; erroreM.Fit(f1);	
	cout << endl << endl << endl;

	//Numero di estrazioni necessarie per avere una certa precisione
	cout << "Numero di estrazioni necessarie per ottenere la precisione desiderata  con metodo della Media: " << pow(f1 -> GetParameter(0)/prec ,2) << "." << endl << endl << endl;

	erroreM.Draw("ALP");	


	myApp.Run();
return 0;
}