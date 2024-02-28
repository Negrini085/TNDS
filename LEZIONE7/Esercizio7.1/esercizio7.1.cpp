#include "Integrale.h"
#include "Funzioni.h"

#include <iostream>
#include <iomanip>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

using namespace std;

int main(int argc, char** argv){
	
	if(argc != 2){
		cout << "Funzionamento programma: " << argv[0] << " <nstep iniziali>" << endl;
		return -1;
	}

	int nstep = atof(argv[1]);
	double tval = 2;
	double appo=0;
	Seno test;

	Simpson cal(0, M_PI);

	TApplication myApp("myApp",0,0);
	TCanvas c1; c1.SetLogy(); c1.SetLogx();
  TGraph err;

	//Calcolo l'integrale con il numero di step inserito da terminale
	appo = cal.Integra(nstep, test);
	cout << scientific;
	cout << "Il valore dell'integrale è: " << setprecision(ceil(-log10(appo-tval))) << appo << endl;
	cout << "L'errore commesso é: "<< setprecision(0) << abs(tval - appo) << " con " << nstep << " passi." << endl << endl << endl;
	cout << "Andamento dell'errore in funzione del numero di step effettuati: " << endl;

	//Valuto l'andamento dell'errore
	nstep = 10;
	for(int i=1; i<=15; i++){
		appo = cal.Integra(nstep, test);
		cout << "Passi:" << setw(7) << nstep << "   Integrale: "  << setw(25) << setprecision(ceil(-log10(abs((appo-tval))))) << appo << "    Errore: " << setw(6) << setprecision(0) << abs(appo-tval) << endl;
		err.SetPoint(i-1, cal.Geth(), abs(appo-tval));
		nstep *= 2;
	}

	err.SetTitle("Andamento errore: metodo di Simpson; Dimensione singolo intervallo; Errore");
  err.GetXaxis()->CenterTitle(true);
  err.GetYaxis()->CenterTitle(true);
	

	err.Draw("AL*");
	myApp.Run();
	return 0;
}