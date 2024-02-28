#include "funzioni.h"
#include "prisma.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

	if(argc != 2) {	
		cout << "Funzionamento programma: " << argv[0] << " <numero pseudo-misure> " << endl;
	return -1;
	}

	EsperimentoPrisma esp;
	vector<double> risultati; int nmis = atoi(argv[1]);

	TApplication myApp("myApp", 0, 0);

	//Genero i valori misurati
	Genera(risultati, nmis, esp);

	//Grafico per theta misurati
	Theta_Mis(risultati, nmis, esp);

	//Grafico per altre cose
	Mis_Correlazioni(risultati, nmis, esp);

	myApp.Run();
return 0;
}
