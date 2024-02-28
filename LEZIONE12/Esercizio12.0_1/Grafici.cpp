/***************************************************
*     PROGRAMMA DI ANALISI DELLE PSEUDO_MISURE     *
***************************************************/
#include "GenRandom.h"
#include "funzioni.h"
#include "prisma.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TH2F.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


int main(){
	//Variabili per titoli dei grafici
	string tmp, tmp1, tmp2, tmp3; 
	//Variabili di appoggio e per true_value
	double appo, appo1; EsperimentoPrisma esp;
	//Variabili per calcolo coefficienti di correlazione
	double a{}, b{}, ab{}, a2{}, b2{}; int i=0; 
	//Nomi file dati
	vector<string> nomi_file{ "CoefficientiA_B.dat", "IndiciRifrazione.dat", "DeviazioneMinima.dat"};

	TApplication myApp("myApp", 0, 0); 


	/******************************************
	*     GRAFICI: theta0, theta1, theta2     *
	******************************************/
	ifstream filein;	filein.open("Angoli.dat"); 
	if(!filein) { cout << "File di input non trovato: esco!!" << endl; exit(-1); }

	//Creo il grafico per gli angoli theta0, theta1, theta2
	TCanvas* c1 = new TCanvas("c100", "Angoli misurati"); c1 -> Divide(3, 1);
	//Creo i TH1F
	TH1F* histo0 = new TH1F("histo0", " Angolo theta0: valori misurati", 100, esp.Getth0_real() - 5*esp.GetSigma(), esp.Getth0_real() + 5*esp.GetSigma());
	TH1F* histo1 = new TH1F("histo1", " Angolo theta1: valori misurati", 100, esp.Getth1_real() - 5*esp.GetSigma(), esp.Getth1_real() + 5*esp.GetSigma());
	TH1F* histo2 = new TH1F("histo2", " Angolo theta2: valori misurati", 100, esp.Getth2_real() - 5*esp.GetSigma(), esp.Getth2_real() + 5*esp.GetSigma());

	//Riempio i tre istogrammi
	while(filein >> appo) {
		histo0 -> Fill(appo);
		filein >> appo; histo1 -> Fill(appo);
		filein >> appo; histo2 -> Fill(appo);
	}
	filein.close();
	//Disegno i tre grafici
	c1 -> cd(1); histo0 -> Draw(); c1 -> cd(2); histo1 -> Draw(); c1 -> cd(3); histo2 -> Draw();



/******************************************
*             ALTRI GRAFICI               *
******************************************/
	for(int j=0; j<3; j++) {
		//Apro stream da file
		filein.open(nomi_file[j].c_str());
		if(!filein) { cout << "Errore in apertura file: esco!!" << endl; exit(-3);}
		
		//Titoli per la canvas
		tmp = "c" + to_string(j + 1); tmp1 = "Valori misurati";
		TCanvas* c = new TCanvas(tmp.c_str(), tmp1.c_str()); c -> Divide(3, 1);

		//Scelgo nome grafico
		Nome_grafico(j, tmp, tmp1, tmp2);

		//Scelgo estremi grafico - riporto valori reali
		vector<double> estremi = Parametri_grafico(j, esp);

		tmp3 = "histo" + to_string(j) + "1" ;
		TH1F* histo0 = new TH1F(tmp3.c_str(), tmp.c_str(), 100, - 5 * estremi[2], 5 * estremi[2]); histo0 -> StatOverflows( "kTRUE" );
		tmp3 = "histo" + to_string(j) + "2" ;
		TH1F* histo1 = new TH1F(tmp3.c_str(), tmp1.c_str(), 100, - 5 * estremi[3], 5 * estremi[3]); histo1 -> StatOverflows( "kTRUE" );
		tmp3 = "histo" + to_string(j) + "3" ;
		TH2F* corr = new TH2F(tmp3.c_str(), tmp2.c_str(), 100, - 5 * estremi[2], 5 * estremi[2], 100, - 5 * estremi[3], 5 * estremi[3]);

		while(filein >> appo) {
			appo -= estremi[0]; histo0 -> Fill(appo);
			filein >> appo1; appo1 -= estremi[1]; histo1 -> Fill(appo1);
			corr -> Fill(appo, appo1);
			//Effettuo calcoli necessari per coefficiente di correlazione
			ab += appo * appo1; a += appo; b += appo1; a2 += appo*appo; b2 += appo1*appo1; i++;
		}
		ab = ab/i; a = a/i; b = b/i; a2 = a2/i; b2 = b2/i;

		cout << "Coefficiente di " + tmp2 << ": " << (ab - a*b)/(sqrt(a2 - a*a)*sqrt(b2 - b*b)) << endl;
		//Riporto a zero le variabili
		a = 0; b = 0; ab = 0; a2 = 0; b2 = 0; i = 0;

		//Titoli assi grafico histo0
		histo0 -> GetXaxis() -> SetTitle("Valori");
		histo0 -> GetYaxis() -> SetTitle("Numero");
		//Titoli assi grafico histo1
		histo1 -> GetXaxis() -> SetTitle("Valori");
		histo1 -> GetYaxis() -> SetTitle("Numero");
		//Titoli grafico correlazione
		corr -> GetXaxis() -> SetTitle(tmp.c_str());
		corr -> GetYaxis() -> SetTitle(tmp1.c_str());

		filein.close();

		//Disegno nelle pad
		c -> cd(1); histo0 -> Draw(); 
		c -> cd(2);	histo1 -> Draw();
		c -> cd(3); corr -> Draw();
		
	}

	myApp.Run();
return 0;
}