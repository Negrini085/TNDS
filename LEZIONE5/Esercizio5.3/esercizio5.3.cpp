#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#include "CampoVettoriale.h"
#include "PuntoMateriale.h"
#include "Particella.h"
#include "Posizione.h"

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

using namespace std;

int main(int argc, char**argv){

	TApplication app("Applicazione",0,0);

	PuntoMateriale protone(0,0,5E-11,1.67262E-27, 1.60217E-19);
	PuntoMateriale elettrone(0,0,-5E-11, 9.10938E-31,-1.60217E-19);
	CampoVettoriale Risultante;

	if(argc != 4){
		cout << "Funzionamento programma: " << argv[0] << " <coordinata x> <coordinata y> <coordinata z> " << endl;
		return -1;
	}

	//Calcolo il campo nella posizione passata da terminale e lo stampo
	Posizione DaTerminale(atof(argv[1]), atof(argv[2]), atof(argv[3]));
	Risultante = protone.CampoElettrico(DaTerminale) + elettrone.CampoElettrico(DaTerminale);
	cout << endl; Risultante.StampaCV(); cout << endl;

	TGraph field; Posizione P;
	double E1 = 0;
	double E2 = 0;

	//Calcolo i valori di campo generati dal dipolo fra 100 e 1000 volte la separazione dello stesso
	for(int k=100; k<=1000; k++){
		P.SetZ(k*1E-10);

		CampoVettoriale E = protone.CampoElettrico(P) + elettrone.CampoElettrico(P);

		if(k==100){ E1 = E.Modulo(); }
		else if(k==1000){ E2 = E.Modulo();}

		field.SetPoint(k-100, k*(1E-10), E.Modulo());
	}

	cout << "Il campo va come x^a con a=" << log(E1/E2)/log(0.1) << endl;

	field.SetTitle("Andamento Campo; Posizione(micrometri); Campo Elettrico(N/C)");
  field.GetXaxis()->CenterTitle(true);
  field.GetYaxis()->CenterTitle(true);


	field.Draw("ALP");
	app.Run();

return 0;
}

