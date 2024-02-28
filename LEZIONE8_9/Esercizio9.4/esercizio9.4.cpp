#include "EquazioniDifferenziali.h"
#include "FunzioniVettoriali.h"
#include "funzioni.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv){

	if(argc != 3) {
		cout << "Funzionamento programma: " << argv[0] << " <frequenza forzante> <numero step>" << endl;
		return -1;
	}

	double tmax =25;
	//Valori inseriti da riga di comando
  double omega = atof(argv[1]); int nstep = atoi(argv[2]);

	//Titolo primo grafico
	string tmp = "Forzante: " + to_string(omega) + " rad/s; Tempo (s) ; Ampiezza (m)";

	TApplication myApp("myApp", 0, 0);
	//Creo i grafici
	TGraph grafico; grafico.SetTitle(tmp.c_str());
	TGraph risonanza; risonanza.SetTitle("Curva di risonanza; forzante (rad/s); Ampiezza (m)");
	
	//Dichiaro le variabili necessarie
	OscillatoreSmorzatoForzato test(10, 1./30., omega); RungeKutta4 lavora;
	vector<double> stato {0, 0};  double t = 0; double h = tmax/nstep;

	grafico.SetPoint(0, t, stato[0]); 

	//Evolvo il sistema con la frequenza forzante passata da terminale	
	for(int i=1; i<=nstep; i++) {
		stato = lavora.Passo(t, stato, h, test);
		t += h;
		grafico.SetPoint(i, t, stato[0]);
	}
	

	/******************************************
	*     CURVA DI RISONANZA OSCILLATORE      *
	******************************************/	
	double appo; 

	for(int i=0; i<=40; i++){
		appo = Ampiezza_sol(lavora, test, i);
		//Riempio il grafico per creare la curva di risonanza
		risonanza.SetPoint(i, test.GetOmega(), abs(appo));
		cout << fixed;
		cout << "Ampiezza con forzante " << setprecision(2) << test.GetOmega() << " radianti: " << fabs(appo) << endl;
		
	}
	
	//Disegno i grafici
	TCanvas *c1 = new TCanvas("c1", "Moto armonico forzato" );
	grafico.Draw("ALP");

	TCanvas *c2 = new TCanvas("c2", "Risonanza" );
	risonanza.Draw("*ALP");
	myApp.Run();

return 0;
}