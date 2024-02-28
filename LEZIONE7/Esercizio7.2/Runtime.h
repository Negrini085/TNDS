#ifndef __Runtime_h__
#define __Runtime_h__

#include "Integrale.h"
#include "Funzioni.h"

#include <iostream>
#include <vector>
#include <cmath>

#define USE_MATH_NDEFINES

using namespace std;

vector<double> Determina_Integrale(FunzioneBase& f, Trapezi& calcola, double prec) {
	int nstep = 1; double I1, I2, err; vector<double> ris;

	I2 = calcola.Integra(nstep, f);
	do{
		I1 = I2;
		I2 = calcola.Integra(2*nstep, f);
		err = (double)4/3*abs(I2 - I1);
		nstep = 2*nstep;
	}while(err >= prec);

	ris.push_back(I2); ris.push_back(err); ris.push_back(nstep);

return ris;
}

#endif //__Runtime_h__