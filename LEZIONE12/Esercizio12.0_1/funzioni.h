#ifndef __funzioni_h__
#define __funzioni_h__

#include "GenRandom.h"
#include "prisma.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void Genera_Afile(int nmis, EsperimentoPrisma& esp){
	 ofstream fileout1, fileout2, fileout3, fileout4;
	
	//Apro i 4 stream a file
	fileout1.open("CoefficientiA_B.dat");
	fileout2.open("IndiciRifrazione.dat");
	fileout3.open("DeviazioneMinima.dat");
	fileout4.open("Angoli.dat");

	//Controllo
	if((!fileout1) || (!fileout2) || (!fileout3) || (!fileout4)) {
		cout << "Problemi in apertura file output: esco!!" << endl;
		exit(-2);
	}

	//Genero valori - stampo a file
	for(int i=0; i<nmis; i++) {
		esp.Misura(); esp.Analizza();
		fileout1 << esp.GetA_mis() << " " << esp.GetB_mis() << endl;
		fileout2 << esp.GetN1_mis() << " " << esp.GetN2_mis() << endl;
		fileout3 << esp.Getdm1_mis() << " " << esp.Getdm2_mis() << endl;
		fileout4 << esp.Getth0_mis() << " " << esp.Getth1_mis() << " " << esp.Getth2_mis() << endl;
	}

fileout1.close(); fileout2.close(); fileout3.close(); fileout4.close();
}



//Funzione per scegliere il nome del grafico
void Nome_grafico(int j, string& tmp, string& tmp1, string& tmp2) {

		if(j == 0) {
			tmp = "Distribuzione coefficiente A";
			tmp1 = "Distribuzione coefficiente B";
			tmp2 = "Correlazione AB";
		}

		else if(j == 1){
			tmp = "Distribuzione indice di rifrazione n1";
			tmp1 = "Distribuzione indice di rifrazione n2";
			tmp2 = "Correlazione indici di rifrazione";
		}

		else if(j == 2) {
			tmp = "Distribuzione angolo dm1";
			tmp1 = "Distribuzione angolo dm2";
			tmp2 = "Correlazione angoli dm1 - dm2";
		}

}



//Funzione per scegliere gli estremi del grafico
vector<double> Parametri_grafico(int j, EsperimentoPrisma& esp) {
	vector<double> parametri;

	if(j == 0) {
		parametri.push_back( esp.GetA_real() );
		parametri.push_back( esp.GetB_real() );
		parametri.push_back(0.001);
		parametri.push_back(3 * pow(10, -16));		
	}

	else if(j == 1) {
		parametri.push_back( esp.GetN1_real() );
		parametri.push_back( esp.GetN2_real() );
		parametri.push_back(0.0003);
		parametri.push_back(0.0003);
	}

	else if(j == 2) {
		parametri.push_back( esp.Getdm1_real() );
		parametri.push_back( esp.Getdm2_real() );
		parametri.push_back(0.0003);
		parametri.push_back(0.0003);
	}

return parametri;
}




#endif //__funzioni_h__