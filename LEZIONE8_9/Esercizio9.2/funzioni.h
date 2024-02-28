#ifndef __funzioni_h__
#define __funzioni_h__

#include "EquazioniDifferenziali.h"
#include "FunzioniVettoriali.h"
#include "OperazioniVector.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


//Funzione che evolve con eulero e RungeKutta4 due condizioni iniziali analoghe fino a un certo tempo tmax
void Confronto_Metodi(double tmax, int nstep, FunzioneVettorialeBase& f, Eulero& eul, RungeKutta4& kutta4){
	
	//Stati iniziali identici per due metodi - Eulero e RungeKutta4
	vector<double> x1 { 0, 1 }; vector<double> x2 { 0, 1};

	//Calcolo passo e inizializzo variabile tempo a zero
	double h = tmax/static_cast<double>(nstep); double t=0; 

	//Creo la canvas 
	TCanvas *c = new TCanvas("c", "Grafici posizione in funzione del tempo");
	//Tgraph per grafici
	TGraph* eul_pos = new TGraph(); TGraph* rung_pos = new TGraph();
	eul_pos -> SetTitle("Metodi di Eulero e Runge-Kutta; Tempo (s); Posizione (m)");

	//Inserisco i primi 2 punti
	eul_pos -> SetPoint(0, t, x1[0]);
	rung_pos -> SetPoint(0, t, x2[0]);

	
	//Evolvo come necessario il sistema
	for(int i = 1; i<=nstep; i++) {
		x1 = eul.Passo(t, x1, h, f);
		x2 = kutta4.Passo(t, x2, h, f);
		t+= h;
		//Riempio i TGraph
		eul_pos -> SetPoint(i, t, x1[0]);
		rung_pos -> SetPoint(i, t, x2[0]);
	}
	x1 = eul.Passo(t, x1, tmax - t, f);
	x2 = kutta4.Passo(t, x2, tmax - t, f);

	cout << endl << "Al tempo: " << tmax << " l'errore commesso con metodo RungeKutta4 è: " << fabs(x2[0] - sin(tmax)) << endl;
	cout << "Al tempo: " << tmax << " l'errore commesso con metodo di Eulero è: " << fabs(x1[0] - sin(tmax)) << endl << endl;

	eul_pos -> SetMarkerColor(6); eul_pos -> SetLineColor(6);	eul_pos -> Draw("ALP");
	rung_pos -> SetMarkerColor(7); rung_pos -> SetLineColor(7); rung_pos -> Draw("sameLP");

	//Creo la legenda
	TLegend* legenda = new TLegend(0.1, 0.7, 0.48, 0.9);
	legenda -> SetHeader("Legenda", "C");
	legenda -> AddEntry(eul_pos, "Metodo di Eulero", "l");
	legenda -> AddEntry(rung_pos, "Metodo Runge-Kutta: ordine 4", "l");
	legenda -> Draw("same");

}



//Funzione per ottenere errori commessi a passi diversi
vector<double> errori(double tmax, FunzioneVettorialeBase& f, Eulero& eul, RungeKutta4& kutta4){
	cout << "Calcolo andamento errori metodi di Runge-Kutta ordine 4 e di Eulero" << endl;

	//Memorizzazione errori - tempo iniziale - primo passo
	vector<double> err; double t = 0; double h = 0.1;

	for(int j=0; j<10; j++){
	//Stati iniziali identici per due metodi - Eulero e RungeKutta4
	vector<double> x1 { 0, 1}; vector<double> x2 {0, 1};

	//Calcolo nstep
	int nstep = static_cast<int>(tmax/h);

	//Evolvo come necessario il sistema
	for(int i = 0; i<nstep; i++) {
		x1 = eul.Passo(t, x1, h, f);
		x2 = kutta4.Passo(t, x2, h, f);
		t+= h;
	}
	x1 = eul.Passo(t, x1, tmax - t, f);
	x2 = kutta4.Passo(t, x2, tmax - t, f);

	cout << scientific;
	cout << setprecision(4) << "Passo: " << h;
	cout << "   Errore metodo Eulero: " << fabs(x1[0] - sin(tmax));
	cout << "   Errore metodo Runge Kutta4: " << fabs(x2[0] - sin(tmax)) << endl;
	//Memorizzo errori
	err.push_back(fabs(x1[0] - sin(tmax)));
	err.push_back(fabs(x2[0] - sin(tmax)));
	
	t = 0; //Riporto a zero il tempo
	h = h/2;//Cambio la precisione di lavoro

	}

return err;
}




//Funzione che consente la visualizzazione dell'andamento dell'errore
void Visualizza_Andamento_Errore(const vector<double>& err, double tmax) {

	//Primo passo con cui lavorato
	double h = 0.1;

	TCanvas* c2 = new TCanvas("c2", "Andamento errori"); c2 -> SetLogx(); c2 -> SetLogy();
	TGraph* eul_err = new TGraph(); TGraph* rung_err = new TGraph();

	rung_err -> SetTitle("Andamento errori: metodi di RungeKutta ordine 4 ed Eulero; Passo; Errore");

	for(int i=0; i<err.size()/2; i++){
		eul_err -> SetPoint(i, h, err[2 * i]); 
		rung_err -> SetPoint(i, h, err[2 * i + 1]); 
		h = h/2;
	}

	//Disegno i grafici
	rung_err -> SetMarkerColor(6); rung_err -> SetLineColor(6); 
	rung_err -> GetYaxis() -> SetRangeUser(1E-11, 20); rung_err -> Draw("ALP*");
	eul_err -> SetMarkerColor(7); eul_err -> SetLineColor(7);  eul_err -> Draw("sameLP*");

	//Creo la legenda
	TLegend* legenda = new TLegend(0.1, 0.8, 0.48, 0.9);
	legenda -> SetHeader("Legenda", "C");
	legenda -> AddEntry(eul_err, "Metodo di Eulero","l");
	legenda -> AddEntry(rung_err, "Metodo di Runge-Kutta: ordine 4", "l");
	legenda -> Draw();

}
#endif //__funzioni_h__