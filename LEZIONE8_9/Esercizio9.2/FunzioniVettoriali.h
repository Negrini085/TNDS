#ifndef __FunzioneVettoriale_h__
#define __FunzioneVettoriale_h__

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class FunzioneVettorialeBase{

	public:
	virtual vector<double> Eval(double t, const vector<double>& x) const = 0;

};

class OscillatoreArmonico : public FunzioneVettorialeBase{

	public:
	//Costruttore che accetta valore della pulsazione
	OscillatoreArmonico(double tmp) { m_omega0 = tmp; }

	//Implementazione Eval Funzione Vettoriale
	 vector<double> Eval(double t, const vector<double>& x) const override {
		vector<double> derivate;

		for(int i=0; i<x.size()/2; i++) { derivate.push_back(x[i+x.size()/2]); }
		for(int i=0; i<x.size()/2; i++) { derivate.push_back(-pow(m_omega0, 2)*x[i]);}
	
	return derivate;
	}

	private:
	double m_omega0;
};


#endif //__FunzioneVettoriale_h__




