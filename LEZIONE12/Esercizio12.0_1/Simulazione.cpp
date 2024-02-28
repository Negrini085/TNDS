/**************************************************
*     PROGRAMMA PER GENERARE LE PSEUDO-MISURE     *
**************************************************/
#include "GenRandom.h"
#include "funzioni.h"
#include "prisma.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

	if(argc != 2) { 
		cout << "Funzionamento programma: " << argv[0] << " <numero di pseudo-misure desiderate> " << endl;
		return -1;
	}

	int nmis = atoi(argv[1]); EsperimentoPrisma esp;

	cout << "Genero le pseudo-misure" << endl;
	Genera_Afile(nmis, esp);
	cout << "Pseudo-misure generate: eseguire 'Grafici' per visualizzare la distribuzione delle stesse " << endl;	

return 0;
}

