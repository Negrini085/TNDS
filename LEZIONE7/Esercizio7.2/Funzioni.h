#ifndef __Funzioni_h__
#define __Funzioni_h__

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define USE_MATH_NDEFINES
using namespace std;



//Classe astratta
class FunzioneBase {
  public:
  virtual double Eval (double) const = 0;
};



//Classe Parabola
class Parabola : public FunzioneBase {

public:
	//Costruttore di default
  Parabola () {m_a=0.; m_b=0.; m_c=0.;}
	//costruttore con in ingresso 3 parametri
  Parabola (double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
	//Distruttore
  ~Parabola() {;}

	//Implementazione metodo Eval
  double Eval (double x) const override {return m_a*x*x + m_b*x + m_c;}

	//Metodi Set/Get per m_a
  void SetA (double a) {m_a=a;}
  double GetA () const {return m_a;}
	//Metodi Set/Get per m_b
  void SetB (double b) {m_b=b;}
  double GetB () const {return m_b;}
	//Metodi Set/Get per m_c
  void SetC (double c) {m_c=c;}
  double GetC () const {return m_c;}

protected:
  double m_a, m_b, m_c;
};



//Classe Seno
class Seno : public FunzioneBase{
public:
	//Costruttore di default
	Seno() { m_A = 0; m_b = 0; }
	//Costruttore con in ingresso due parametri
	Seno(double A, double b) { m_A = A; m_b = b; }
	//Distruttore
	~Seno() {;}

	//Implementazione metodo Eval
	double Eval(double x) const override { return m_A * sin(m_b * x); }

	//Metodi Set/Get per ampiezza
	double GetA() { return m_A; }
	void SetA(double tmp) { m_A = tmp; }
	//Metodi Set/Get per m_b
	double GetB() { return m_b; }
	void SetB(double tmp) { m_b = tmp; }
	
protected:
	double m_A, m_b;
};



//Classe Segno
class Segno : public FunzioneBase{

	public:
	//Costruttore di default
	Segno() {;}
	//Distruttore
	~Segno() {;}

	//Implementazione metodo Eval
	double Eval(double x) const override {
		if(x>0) return 1;
		else if(x<0) return -1;
		else if(x==0) return 0;
	 }

};

#endif //__Funzioni_h__