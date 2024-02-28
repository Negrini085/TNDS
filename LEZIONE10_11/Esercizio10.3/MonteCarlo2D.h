#ifndef __MonteCarlo2D_h__
#define __MonteCarlo2D_h__

#include "FunzioniScalari.h"
#include "GenRandom.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MonteCarlo2D {
	public:
	//Costruttore di default
	MonteCarlo2D() : genera(1) { n_limite = 0; }
	//Costruttore che accetta in ingresso parametri
	MonteCarlo2D(unsigned int lim) : n_limite(lim), genera(1) {;}

	//Metodi Get/Set per numero di punti
	unsigned int GetN() { return n_limite; }
	void SetN(unsigned int tmp) { n_limite = tmp; }

	//Metodo della media
	double MED(FunzScalareBase& f, const vector<double>& xlim, const vector<double>& ylim) {
		double appo = 0;

		if(n_limite == 0) {
			cout << "Tentativo di calcolare l'integrale senza neanche un punto: esco!!!" << endl;
			exit(-5);
		}

		for(int i=0; i<n_limite; i++) {
			vector<double> pos;
			pos.push_back(genera.Unif(xlim[0], xlim[1]));
			pos.push_back(genera.Unif(ylim[0], ylim[1]));
			appo = appo * static_cast<double>(i)/static_cast<double>(i + 1) + f.Eval(pos)/static_cast<double>(i + 1);
		}

		return appo * (xlim[1] - xlim[0]) * (ylim[1] - ylim[0]);
	}


	//Metodo HitMiss
	double HM(FunzScalareBase& f, const vector<double>& xlim, const vector<double>& ylim, double fmax) { 
		int nhit = 0; double x, y, z;

		if(n_limite == 0) {
			cout << "Tentativo di calcolare l'integrale senza neanche un punto: esco!!!" << endl;
			exit(-5);
		}
		
		for(int i=0; i<n_limite; i++){
			vector<double> pos; 
			pos.push_back(genera.Unif(xlim[0], xlim[1]));
			pos.push_back(genera.Unif(ylim[0], ylim[1]));
			z = genera.Unif(0, fmax);
			if(z < f.Eval(pos))	{ nhit++; }	
		}

		return fmax * (xlim[1] - xlim[0]) * (ylim[1] - ylim[0]) * nhit/n_limite;
	}
	

	private:
	//Data membri privati sono numero di "punti"
	unsigned int n_limite; GenRandom genera;
	
};

#endif //__MonteCarlo2D_h__