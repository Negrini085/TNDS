#ifndef __funzioni_h__
#define __funzioni_h__

#include "EquazioniDifferenziali.h"
#include "FunzioniVettoriali.h"
#include "OperazioniVector.h"

#include <iostream>
#include <cmath>

#define USE_MATH_NDEFINES

using namespace std;

double Ampiezza_sol(RungeKutta4& lavora, OscillatoreSmorzatoForzato& f, int j) {
	//Imposto passo h di lavoro
	double tmax = 10/f.GetGamma(); double h  = tmax/30000.; 
	//Stato iniziale
	vector<double> stato {0, 0}; vector<double> old_stato; double t=0;

	//Cambio il valore della forzante
	f.SetOmega(f.GetOmega0() - (20 - j)*0.05);
		
	//Evolvo il sistema fino a quando giungo a tmax
	for(int i = 0; i<30000; i++){ stato = lavora.Passo(t, stato, h, f); t += h;	}

	double v = stato[1]; double pos1, pos2;

	//Ricerco primo punto di inversione moto
	do {
		old_stato = stato;
		stato = lavora.Passo(t, stato, h, f);
	}while(stato[1] * v > 0);
	pos1 = fabs((stato[0] + old_stato[0]))/2.;

	//Ricerco secondo punto di inversione moto
	v = stato[1];
	do {
		old_stato = stato;
		stato = lavora.Passo(t, stato, h, f);
	}while(stato[1] * v > 0);
	pos2 = fabs((stato[0] + old_stato[0]))/2.;


return abs(pos2 + pos1)/2.;
}


#endif //__funzioni_h__