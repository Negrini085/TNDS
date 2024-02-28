#ifndef __Funzioni_h__
#define __Funzioni_h__

#include <iostream>
#include <cmath>

#define USE_MATH_NDEFINES
using namespace std;

//Classe madre virtuale pura
class FunzioneBase {

	public:
	virtual double Eval(double x) const = 0;
	virtual ~FunzioneBase() {;} ;

};



//Classe Parabola
class Parabola : public FunzioneBase {
	
	public:
	//Costruttore di default
	Parabola() { m_a = 0; m_b = 0; m_c = 0; }
	//Costruttore che accetta in ingresso i tre parametri
	Parabola(double a, double b, double c) { m_a = a; m_b = b; m_c = c; }
	//Metodi Get/Set per m_a
	double GetA() { return m_a; }
	void SetA(double tmp) { m_a = tmp; }
	//Metodi Get/Set per m_b
	double GetB() { return m_b; }
	void SetB(double tmp) { m_b = tmp; }
	//Metodi Get/Set per m_c
	double GetC() { return m_c; }
	void SetC(double tmp) { m_c = tmp; }


	double Eval(double x) const override { return m_a * pow(x, 2) + m_b * x + m_c; }
	~Parabola() override {;}

	protected:
	double m_a, m_b, m_c;
};



//Classe Seno
class Seno : public FunzioneBase {

	public:
	//Costruttore di default
	Seno() { m_a = 0; }
	//Costruttore che accetta in ingresso il parametro
	Seno(double tmp) { m_a = tmp; }
	//Metodi Get/Set per m_a
	double GetA() { return m_a; }
	void SetA(double tmp) { m_a = tmp; }

	double Eval(double x) const override { return sin(m_a * x); }
	~Seno() override {;}

	protected:
	double m_a;
};



//Classe Esponenziale
class Esponenziale : public FunzioneBase {

	public:
	//Costruttore di default
	Esponenziale() { m_a = 0; }
	//Costruttore che accetta in ingresso il parametro
	Esponenziale(double tmp) { m_a = tmp; }

	//Metodi Get/Set per m_a
	double GetA() { return m_a; }
	void SetA(double tmp) { m_a = tmp; }

	double Eval(double x) const override { return exp(m_a*x); }
	~Esponenziale() override {;}

	protected:
	double m_a;
};



//Classe Coseno
class Coseno : public FunzioneBase {

	public:
	//Costruttore di default
	Coseno() { m_a = 0; }
	//Costruttore che accetta in ingresso il parametro
	Coseno(double tmp) { m_a = tmp; }

	//Metodi Get/Set per m_a
	double GetA() { return m_a; }
	void SetA(double tmp) { m_a = tmp; }

	double Eval(double x) const override { return cos(m_a * x); }
	~Coseno() override {;}

	protected:
	double m_a;
};


#endif //__Funzioni_h__