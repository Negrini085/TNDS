#ifndef __IntegraliMontecarlo_h__
#define __IntegraliMontecarlo_h__

#include "GenRandom.h"
#include "Funzioni.h"

#include <iostream>

using namespace std;


class MonteCarlo {

	public:
	//Costruttore di default
	MonteCarlo() : genera(1) {;}
	//Distruttore
	~MonteCarlo() {;}


	//Metodo Hit_or_Miss
	double HM(double xmin, double xmax, unsigned int npunti, FunzioneBase& f, double fmax) {
		//Contatore per le hit e contenitore per numeri estratti casualmente
		unsigned int n_hit = 0;  double x, y; double segno;

		//Valuto il "verso" di integrazione
		if(xmax > xmin) { segno = 1; }
		else{ segno = xmin; xmin = xmax; xmax = segno; segno = -1; }
		//Scambio fra di loro estremi (per avere generazione numeri corretta) e annoto segno negativo
	
		//Determino il numero delle hit
		for(int i=0; i < npunti; i++) {
			//Estraggo due numeri generati uniformemente
				x = genera.Unif(xmin, xmax);
				y = genera.Unif(0, fmax);
			if(y <= f.Eval(x)){n_hit++;}	
		}

		//Ritorno il valore dell'integrale
		return segno * fabs(xmin - xmax) * fmax * static_cast<double>(n_hit)/static_cast<double>(npunti);
	}


	//Metodo della media
	double MED(double xmin, double xmax, unsigned int npunti, FunzioneBase& f) {
		//Contenitore per la media
		double somma = 0; double segno;

		//Valuto il "verso" di integrazione
		if(xmax > xmin) { segno = 1; }
		else{ segno = xmin; xmax = xmin; xmin = segno; segno = -1; }

		//Proseguo con la valutazione tante volte quanto richiesto
		for(int i=0; i < npunti; i++) {
			somma = somma * static_cast<double>(i)/static_cast<double>(i+1) + f.Eval(genera.Unif(xmin, xmax))/static_cast<double>(i+1);
		}

	return segno * somma * (xmax - xmin);
	}
	

	protected:
	GenRandom genera; 
};

#endif //__IntegraliMontecarlo_h__