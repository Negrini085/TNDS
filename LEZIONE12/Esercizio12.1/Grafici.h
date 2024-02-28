#ifndef __Grafici_h__
#define __Grafici_h__

#include "GenRandom.h"
#include "Viscosità.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"
#include "TF1.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

//Simulo l'esperimento e grafico i risultati considerando tutte le fonti di incertezza
void Simulazioni_3errori(Viscosita& esperimento, int nsim, const vector<double>& raggi) {

	string tmp, tmp1;	
	//Eseguo le due simulazioni con tutte le fonti di incertezza - stessa canvas e due pad differenti
	TCanvas* c1 = new TCanvas("c1", "Valori del coefficiente di attrito viscoso");
	c1 -> Divide(2, 1);
	for(int k=0; k<2; k++){
		//Setto il raggio della sfera di cui simulerò il moto
		esperimento.SetRaggioR(raggi[k]);
		//Titoli per il TH1F
		tmp = "eta" + to_string(k+1);
		tmp1 = "Coefficiente di Viscosità: raggio sfera " + to_string(raggi[k]) + " m ";
		//Creo il TH1F e mi posiziono nella Pad desiderata
		TH1F* eta = new TH1F(tmp.c_str(), tmp1.c_str(), 100, 0.73, 0.93); 
		eta -> StatOverflows ( "kTRUE" );	c1 -> cd(k + 1);	
		//Riempio l'istogramma	
		for(int i=0; i<nsim; i++){
		esperimento.Misura();
		esperimento.Analizza();
		eta -> Fill(esperimento.GetEtaM());
		}
		//Disegno
		eta -> Draw();
	}

}




//Simulazione: errore solo sul raggio
void Simulazioni_ErroreSulRaggio(Viscosita& esperimento, int nsim, const vector<double>& raggi) {
	string tmp, tmp1;

	//Eseguo le due simulazioni con solo errore sul raggio - stessa canvas e due pad differenti
	TCanvas* c2 = new TCanvas("c2", "Incertezza solo sul raggio");
	c2 -> Divide(2, 1); 
	//Pongo a zero i due errori "non desiderati"
	esperimento.SetErrPos(0); esperimento.SetErrTmp(0);
		for(int k=0; k<2; k++){
		//Setto il raggio della sfera di cui simulerò il moto
		esperimento.SetRaggioR(raggi[k]);
		//Titoli per il TH1F
		tmp = "eta" + to_string(k+1) + ": sigmaR";
		tmp1 = "Coefficiente di Viscosità: raggio sfera " + to_string(raggi[k]) + " m ";
		//Creo il TH1F e mi posiziono nella Pad desiderata
		TH1F* eta = new TH1F(tmp.c_str(), tmp1.c_str(), 100, 0.73, 0.93); 
		eta -> StatOverflows ( "kTRUE" );	c2 -> cd(k + 1);	
		//Riempio l'istogramma	
		for(int i=0; i<nsim; i++){
		esperimento.Misura();
		esperimento.Analizza();
		eta -> Fill(esperimento.GetEtaM());
		}
		//Disegno
		eta -> Draw();
	}
}




//Simulazione: errore solo sulle posizioni
void Simulazioni_ErroreSullePosizioni(Viscosita& esperimento, int nsim, const vector<double>& raggi) {
	string tmp, tmp1;

	//Eseguo le due simulazioni con solo errore sulla posizione - stessa canvas e due pad differenti
	TCanvas* c3 = new TCanvas("c3", "Incertezza solo sulla posizione");
	c3 -> Divide(2, 1); 
	//Pongo a zero i due errori "non desiderati"
	esperimento.SetErrPos(0.001); esperimento.SetErrTmp(0); esperimento.SetErrRag(0);
		for(int k=0; k<2; k++){
		//Setto il raggio della sfera di cui simulerò il moto
		esperimento.SetRaggioR(raggi[k]);
		//Titoli per il TH1F
		tmp = "eta" + to_string(k+1) + ": sigmaP";
		tmp1 = "Coefficiente di Viscosità: raggio sfera " + to_string(raggi[k]) + " m ";
		//Creo il TH1F e mi posiziono nella Pad desiderata
		TH1F* eta = new TH1F(tmp.c_str(), tmp1.c_str(), 100, 0.73, 0.93); 
		eta -> StatOverflows ( "kTRUE" );	c3 -> cd(k + 1);	
		//Riempio l'istogramma	
		for(int i=0; i<nsim; i++){
		esperimento.Misura();
		esperimento.Analizza();
		eta -> Fill(esperimento.GetEtaM());
		}
		//Disegno
		eta -> Draw();
	}
}




//Simulazione: errore solo sul tempo
void Simulazioni_ErroreSulTempo(Viscosita& esperimento, int nsim, const vector<double>& raggi) {
	string tmp, tmp1;

		//Eseguo le due simulazioni con solo errore sul tempo - stessa canvas e due pad differenti
	TCanvas* c4 = new TCanvas("c4", "Incertezza solo sul tempo");
	c4 -> Divide(2, 1); 
	//Pongo a zero i due errori "non desiderati"
	esperimento.SetErrPos(0); esperimento.SetErrTmp(0.01); esperimento.SetErrRag(0);
		for(int k=0; k<2; k++){
		//Setto il raggio della sfera di cui simulerò il moto
		esperimento.SetRaggioR(raggi[k]);
		//Titoli per il TH1F
		tmp = "eta" + to_string(k+1) + ": sigmaT";
		tmp1 = "Coefficiente di Viscosità: raggio sfera " + to_string(raggi[k]) + " m ";
		//Creo il TH1F e mi posiziono nella Pad desiderata
		TH1F* eta = new TH1F(tmp.c_str(), tmp1.c_str(), 100, 0.73, 0.93);
		eta -> StatOverflows ( "kTRUE" );	c4 -> cd(k + 1);	
		//Riempio l'istogramma	
		for(int i=0; i<nsim; i++){
		esperimento.Misura();
		esperimento.Analizza();
		eta -> Fill(esperimento.GetEtaM());
		}
		//Disegno
		eta -> Draw();
	}

}




#endif //__Grafici_h__