#include "EquazioniDifferenziali.h"
#include "FunzioneVettoriale.h"
#include "OperazioniVector.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

#include <iostream>

using namespace std;

int main(){

	double h{0.01}, v{}, t{};
	Pendolo test(1); RungeKutta4 lavora;
	

	TApplication myApp("myApp", 0, 0); 
	TCanvas *c = new TCanvas("c", "Periodo di oscillazione in funzione dell'ampiezza"); 
	
	TGraph periodo; periodo.SetTitle("Soluzione; Ampiezza (rad) ; Periodo (s)");
  periodo.GetXaxis()->CenterTitle(true); periodo.GetYaxis()->CenterTitle(true);

	//Calcolo il periodo per 30 ampiezze differenti	
	for(int i=1; i<=30; i++){
		
		vector<double> stato {0.1*i , 0};
		t = 0;

		while(stato[1] <= 0) {
			v = stato[1];
			stato = lavora.Passo(t, stato, h, test);
			t += h;
		}

		t = t - stato[1]*h/(stato[1] - v);

		cout << "Ampiezza: " << 0.1*i << " Periodo: " << 2*t << endl;
		periodo.SetPoint(i-1, 0.1 * i, 2*t);

	}
	
	periodo.Draw("ALP*");
	myApp.Run();

return 0;
}