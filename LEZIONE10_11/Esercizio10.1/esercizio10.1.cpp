#include "GenRandom.h"
#include "Grafici.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TH1F.h"

using namespace std;

int main(int argc, char** argv){

	if(argc != 3) {
		cout << "Funzionamento programma: " << argv[0] << " <numero elementi serie di partenza> <numero di elementi consecutivi di cui fare la somma> - Esco!! " << endl;
		return -1;
	}

	vector<double> estratti; int nlim = atoi(argv[1]); 
	GenRandom genera(1); string tmp; int ndasom = atoi(argv[2]);
	if(nlim == 0) {cout << "Numeri da estrarre: " << nlim << " Esco!!" << endl; return -1; }
	
	TApplication myApp("myApp", 0, 0);
	//Istogrammi per la distribuzione uniforme e per la distribuzione delle somme - n dato in input
	TH1F* unif = new TH1F("unif", "Distribuzione uniforme", 100, 0, 1);
	tmp = "Distribuzione delle somme: " + to_string(ndasom) + " addendi";
	TH1F* somme = new TH1F("somme", tmp.c_str(), 100, 0, ndasom);
	//Estraggo i numeri casuali desiderati
	for(int i=0; i<nlim; i++) { estratti.push_back(genera.Unif(0,1)); unif -> Fill(estratti[i]);}

	
	//Numero di somme da fare
	int nsom = nlim/ndasom; double appo;
	//Effettuo le somme
	for(int i=0; i<nsom; i++){
		int k = i;
		do{ appo += estratti[k]; k++; }while(k < i + ndasom);
		somme -> Fill(appo); appo = 0;
	}

	//Disegno i grafici della distribuzione uniforme e di quella delle somme
	TCanvas* c1 = new TCanvas("c1", "Distribuzioni a confronto"); c1 -> Divide(2, 1);
	c1 -> cd(1); unif -> Draw(); c1 -> cd(2); somme -> Draw();
	

	cout << "La media della distribuzione uniforme è: " << unif -> GetMean() << " con varianza pari a: " << pow(unif -> GetStdDev(), 2) << "." << endl;
	cout << "La media della distribuzione delle somme a " << ndasom << " addendi è: " << somme -> GetMean() << " con varianza pari a: " << pow(somme -> GetStdDev(), 2) << "." << endl;



	//Numero di elementi adicenti che sommo
	vector<int> n_dasom {5, 10, 15, 20, 25, 30};
	//Contenitore delle varianze delle distribuzioni delle somme
	vector<double> var;

	//Grafico con 6 pad e distribuzione delle somme a N fissati - come scala la varianza??
	AndamentoDistribuzioneSomme(estratti, n_dasom, var);

	//Andamento della varianza al variare del numero di addendi considerati nelle somme
	if(var.size() != n_dasom.size()) {
		cout << "Varianza e numero di distribuzioni delle somme differente: esco!!" << endl;
		exit(-4);
		}

	cout << endl;
	for(int i=0; i<n_dasom.size(); i++) {
		cout << "La varianza della distribuzione delle somme a " << n_dasom[i] << " addendi è: " << var[i] << "." << endl;
	}

	ScaloVarianza(var, n_dasom);



	myApp.Run();

return 0;
}