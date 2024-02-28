#ifndef __FunzioniScalari_h__
#define __FunzioniScalari_h__

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class FunzScalareBase {	
	public:
	virtual double Eval(const vector<double>& pos) const = 0;
};

class Integranda : public FunzScalareBase {
	public:
	//Costruttore di default
	Integranda() {;}
	//Metodo Eval
	double Eval(const vector<double>& pos) const override {
		return (5/pow(pos[0], 2)) * cos(4 * pos[1]) * sin(7 * pos[0]) + 10;
	}
};


#endif //__FunzioniScalari_h__