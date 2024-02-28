#ifndef __EquazioniDifferenziali_h__
#define __EquazioniDifferenziali_h__

#include "FunzioniVettoriali.h"
#include "OperazioniVector.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class DifferenzialeBase{
	public:
	//Costruttore
	DifferenzialeBase() {;}
	//Distruttore
	~DifferenzialeBase() {;}

	//Metodo Passo virtuale
	virtual vector<double> Passo(double t, const vector<double>& x, double h, FunzioneVettorialeBase& f) const =  0;

};

class Eulero : public DifferenzialeBase{
	public:
	//Costruttore
	Eulero() : DifferenzialeBase() {;}
	//Distruttore
	~Eulero() {;}

	//Implementazione metodo passo
	vector<double> Passo(double t, const vector<double>& x , double h, FunzioneVettorialeBase& f) const override {
		return x + (f.Eval(t, x))*h;
	}
};

#endif //__EquazioniDifferenziali_h__