#ifndef __FunzioneVettoriale_h__
#define __FunzioneVettoriale_h__

#include <iostream>
#include <vector>
#include <cmath>

#define USE_MATH_NDEFINES
#define acc_g 9.81 // m/s^2

using namespace std;

class FunzioneVettorialeBase{

	public:
	virtual vector<double> Eval(double t, const vector<double>& x) const = 0;

};




/***********************************
*    CLASSE OSCILLATORE ARMONICO   *
***********************************/
class OscillatoreArmonico : public FunzioneVettorialeBase{

	public:
	//Costruttore che accetta valore della pulsazione
	OscillatoreArmonico(double tmp) { m_omega0 = tmp; }

	//Implementazione metodo Eval 
	virtual vector<double> Eval(double t, const vector<double>& x) const override {
		vector<double> derivate;

		for(int i=0; i<x.size()/2; i++) { derivate.push_back(x[i+x.size()/2]); }
		for(int i=0; i<x.size()/2; i++) { derivate.push_back(-pow(m_omega0, 2)*x[i]);}
	
	return derivate;
	}

	private:
	double m_omega0;
};




/****************************************
*            CLASSE PENDOLO             *
****************************************/
class Pendolo : public FunzioneVettorialeBase{
	public:
	//Costruttore che accetta in ingresso la lunghezza del Pendolo
	Pendolo(double tmp) { m_lungh = tmp;}

	//Implementazione metodo Eval
	virtual vector<double> Eval(double t, const vector<double>& x) const override {
		vector<double> derivate;
		double omega2 = acc_g/m_lungh;

		for(int i=0; i<x.size()/2; i++) {derivate.push_back(x[i + x.size()/2]);}
		for(int i=0; i<x.size()/2; i++) {derivate.push_back(-omega2*sin(x[i]));}
	
	return derivate;
	}

	private:
	double m_lungh;
};


#endif //__FunzioneVettoriale_h__




