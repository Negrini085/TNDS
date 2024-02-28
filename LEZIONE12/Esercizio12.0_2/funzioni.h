#ifndef __funzioni_h__
#define __funzioni_h__

#include "prisma.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TH2F.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


//Funzione per generare valori
void Genera(vector<double>& contenitore, int nmis, EsperimentoPrisma& esp) {
	for(int i=0; i<nmis; i++) { 
		//Genero pseudo misure e analizzo
		esp.Misura(); esp.Analizza();
		//Riempio contenitore
		contenitore.push_back(esp.Getth0_mis());
		contenitore.push_back(esp.Getth1_mis());
		contenitore.push_back(esp.Getth2_mis());
		contenitore.push_back(esp.GetA_mis());
		contenitore.push_back(esp.GetB_mis());
		contenitore.push_back(esp.Getdm1_mis());
		contenitore.push_back(esp.Getdm2_mis());
		contenitore.push_back(esp.GetN1_mis());
		contenitore.push_back(esp.GetN2_mis());
	}

}



//Funzione per grafici sui theta misurati
void Theta_Mis(vector<double>& contenitore, int nmis, EsperimentoPrisma& esp) {
	string tmp, tmp1; 
	//Estremi grafico
	vector<double> estr {esp.Getth0_real(), esp.Getth1_real(), esp.Getth2_real(), esp.GetSigma()};
	TCanvas* c = new TCanvas("c", "Pseudo misure generate"); c -> Divide(3, 1);

	for(int j=0; j<3; j++) {
		tmp = "tetha" + to_string(j); tmp1 = "Distribuzione angolo theta" + to_string(j); 
		TH1F* histo = new TH1F(tmp.c_str(), tmp1.c_str(), 100, estr[j] - 5 * estr[4] , estr[j] + 5 * estr[4]);
		
		histo -> GetXaxis() -> SetTitle("Valori");
		histo -> GetYaxis() -> SetTitle("Numero");

		for(int i=0; i<nmis; i++) { histo -> Fill(contenitore[i * contenitore.size()/nmis  + j]); }
	
	c -> cd(j+1); histo -> Draw();
	}
}



//Parametri per costruire gli altri grafici - valori Real e estremi per Istogrammi
vector<double> Parametri(EsperimentoPrisma& esp, int i) {
	vector<double> par;

	if(i == 0) {
		par.push_back(esp.GetA_real()); par.push_back(esp.GetB_real());
		par.push_back(0.001); par.push_back(3 * pow(10, -16));
	}

	else if(i == 1) {
		par.push_back( esp.Getdm1_real() ); par.push_back( esp.Getdm2_real() );
		par.push_back(0.0003); par.push_back(0.0003);
	}

	else if(i == 2) {
		par.push_back( esp.GetN1_real() ); par.push_back( esp.GetN2_real() );
		par.push_back(0.0003); par.push_back(0.0003);
	}


return par;
}



//Funzione per scegliere il nome del grafico
void Nome_grafico(int j, string& tmp, string& tmp1, string& tmp2) {

		if(j == 0) {
			tmp = "Distribuzione coefficiente A";
			tmp1 = "Distribuzione coefficiente B";
			tmp2 = "Correlazione AB";
		}

		else if(j == 1) {
			tmp = "Distribuzione angolo dm1";
			tmp1 = "Distribuzione angolo dm2";
			tmp2 = "Correlazione angoli dm1 - dm2";
		}

		else if(j == 2){
			tmp = "Distribuzione indice di rifrazione n1";
			tmp1 = "Distribuzione indice di rifrazione n2";
			tmp2 = "Correlazione indici di rifrazione";
		}

}


//Creazione degli altri grafici
void Mis_Correlazioni(vector<double>& contenitore, int nmis, EsperimentoPrisma& esp) {
	//Variabili di appoggio
	string tmp, tmp1, tmp2, tmp3;
	double appo, appo1;

	for(int i=0; i<3; i++) {
		tmp = "c" + to_string(i);
		TCanvas* c = new TCanvas(tmp.c_str(), "Distribuzione pseudo-misure"); c -> Divide(3, 1);

		//Parametri per grafici
		vector<double> par = Parametri(esp, i);
		Nome_grafico(i, tmp, tmp1, tmp2);

		//Istogrammi
		tmp3 = "histo" + to_string(i) + "1" ;
		TH1F* histo0 = new TH1F(tmp3.c_str(), tmp.c_str(), 100, - 5 * par[2], 5 * par[2]); histo0 -> StatOverflows( "kTRUE" );
		tmp3 = "histo" + to_string(i) + "2" ;
		TH1F* histo1 = new TH1F(tmp3.c_str(), tmp1.c_str(), 100, - 5 * par[3], 5 * par[3]); histo1 -> StatOverflows( "kTRUE" );
		tmp3 = "histo" + to_string(i) + "3" ;
		TH2F* corr = new TH2F(tmp3.c_str(), tmp2.c_str(), 100, - 5 * par[2], 5 * par[2], 100, - 5 * par[3], 5 * par[3]);

		double a{}, b{}, a2{}, b2{}, ab{};

		
		for(int j=0; j<nmis; j++) {
			//Determino variabile da mettere in primo istogramma - differenza fra misurato e vero
			appo = contenitore[j * contenitore.size()/nmis + 3 + 2*i] - par[0]; 
			a += appo; a2 += pow(appo, 2); histo0 -> Fill(appo);

			//Determino variabile da mettere in secondo istogramma - differenza fra misurato e vero
			appo1 = contenitore[j * contenitore.size()/nmis + 4 + 2*i] - par[1]; 
			b += appo1; b2 += pow(appo1, 2); histo1 -> Fill(appo1);

			corr -> Fill(appo, appo1); ab += appo * appo1;

		}
		a /= nmis; b /= nmis; a2 /= nmis; b2 /= nmis; ab /= nmis;

		cout << "Coefficiente " + tmp2 + ": " << (ab -a*b)/(sqrt(a2 - pow(a, 2)) * sqrt(b2 - pow(b, 2))) << endl;

		c -> cd(1); 
		histo0 -> GetXaxis() -> SetTitle("Valore"); 
		histo0 -> GetYaxis() -> SetTitle("Numero"); histo0 -> Draw();
		c -> cd(2); 
		histo1 -> GetXaxis() -> SetTitle("Valore"); 
		histo1 -> GetYaxis() -> SetTitle("Numero"); histo0 -> Draw();
		c -> cd(3); 
		corr -> GetXaxis() -> SetTitle(tmp.c_str()); 
		corr -> GetYaxis() -> SetTitle(tmp1.c_str()); corr -> Draw();
	}
	
}

#endif //__funzioni_h__