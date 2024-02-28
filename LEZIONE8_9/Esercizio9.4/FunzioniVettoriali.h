#ifndef __FunzioniVettoriali_h__
#define __FunzioniVettoriali_h__

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

	protected:
	double m_omega0;
};


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

	protected:
	double m_lungh;
};


class OscillatoreSmorzato : public FunzioneVettorialeBase {

	public:
	//Costruttore di default
	OscillatoreSmorzato() { m_omega0 = 0; m_gamma = 0;}
	//Costruttore che accetta in ingresso omega0 e gamma
	OscillatoreSmorzato(double omega0, double gamma) { m_omega0 = omega0; m_gamma = gamma;}

	//Metodo per conoscere m_omega0
	double GetOmega0() const { return m_omega0; }
	//Metodo per modificare m_omega0
	void SetOmega(double tmp) { m_omega0 = tmp; }
	//Metodo per conoscere gamma
	double GetGamma() const { return m_gamma; }
	//Metodo per modificare gamma
	void SetGamma(double tmp) { m_gamma = tmp; }


	//Overloading metodo Eval Funzione Vettoriale
	virtual vector<double> Eval(double t, const vector<double>& x) const override {
		vector<double> derivate;
		for(int i = 0; i < x.size()/2; i++) { derivate.push_back(x[i+x.size()/2]);}
		for(int i = 0; i < x.size()/2; i++) {derivate.push_back(-m_gamma*x[i+x.size()/2] - pow(m_omega0, 2)*x[i]);}

		return derivate;
	}

	protected:
	double m_omega0, m_gamma;
};


class OscillatoreSmorzatoForzato : public OscillatoreSmorzato {
	
	public: 
	//Costruttore di default
	OscillatoreSmorzatoForzato() : OscillatoreSmorzato() { m_omega = 0;}
	//Costruttore che accetta in ingresso omega0, gamma e omega
	OscillatoreSmorzatoForzato(double omega0, double gamma, double omega) : OscillatoreSmorzato(omega0, gamma) {m_omega = omega;}

	//Metodo per conoscere omega
	double GetOmega() { return m_omega; }
	//Metodo per modificare omega
	void SetOmega(double tmp) { m_omega = tmp; }

	//Implementazione metodo Eval
	virtual vector<double> Eval(double t, const vector<double>& x) const override {
		vector<double> derivate;

		for(int i=0; i<x.size()/2; i++) { derivate.push_back(x[i + x.size()/2]); }
		for(int i=0; i<x.size()/2; i++) {derivate.push_back(-m_gamma*x[i+x.size()/2] - pow(m_omega0, 2)*x[i] + sin(m_omega*t));}

	return derivate;
	}

	protected:
	double m_omega;	
};



#endif