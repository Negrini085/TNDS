#ifndef __Integrale_h__
#define __Integrale_h__

#include "Funzioni.h"

#include <iostream>
#include <cmath>

using namespace std;

//Classe virtuale
class Integratore {
	public:
	//Costruttore di default
	Integratore() { 
		m_somma = 0; m_segno = 0;
		m_a = 0; m_b = 0; m_h = 0;
	}
	//Costruttore  - in ingresso estremi integrazione
	Integratore(double a, double b) {
		m_somma = 0; m_segno = 0;
		m_a = a; m_b = b; m_h = 0;
	}
	//Distruttore
	~Integratore() {;}

	//Metodi Set/Get per m_a
	double GetA() const { return m_a; }
	void SetA(double tmp) { m_a = tmp; }
	//Metodi Set/Get per m_b
	double GetB() const { return m_b; }
	void SetB(double tmp) { m_b = tmp; }
	//Metodi Get segno
	double GetSgn() const { return m_segno; }
	//Metodo Geth
	double Geth() const { return m_h; }

	//Metodo Integra
	virtual double Integra(unsigned int nstep, const FunzioneBase& f) = 0;

	protected:
	double m_somma, m_segno, m_a, m_b, m_h;
};



//Classe Midpoint
class Midpoint : public Integratore {
	public:
	//Costruttore di default
	Midpoint() : Integratore() {;}
	//Costruttore - in ingresso estremi integrazione
	Midpoint(double a, double b) : Integratore(a, b) {;}
	//Distruttore
	~Midpoint() {;}

	//Implementazione metodo Integra
	double Integra(unsigned int nstep, const FunzioneBase& f) override {
		//Controllo <"verso" di integrazione
		if(m_b > m_a) { m_segno = 1; }
		else{ m_segno = -1; }

		//Azzero somma e valuto passo integrazione
		m_somma = 0; m_h = fabs(m_b - m_a)/static_cast<double>(nstep);

		for(int i=0; i<nstep; i++) { m_somma += f.Eval(min(m_a, m_b) + (i + 0.5)*m_h); }
		
	return m_somma * m_h * m_segno;
	}
};

#endif //__Integrale_h__



/*******************************************
*     ALTRA POSSIBILE IMPLEMENTAZIONE      *
*******************************************/
/*#ifndef __Integrale_h__ 
#define __Integrale_h__

#include "Funzioni.h"

#include <iostream>
#include<cmath>

#define USE_MATH_NDEFINES
using namespace std;

class Integratore {
	public:
	//Costruttore default
	Integratore() : m_a{}, m_b{}, m_segno{} {;}

	//Metodi Get per data-membri
	double GetA() const { return m_a; }
	double GetB() const { return m_b; }
	double GetSgn() const { return m_segno; }

	//Metodo integra
	double Integra(double a, double b, unsigned int nstep, const FunzioneBase& f) { 
		ControlloIntervallo(a, b);
		return Calcola(nstep, f);
	}

	private:
	//Metodo per controllare intervallo
	void ControlloIntervallo(double a, double b) {
		if(b > a) { m_a = a; m_b = b; m_segno = 1; }
		else{m_a = b; m_b = a; m_segno = -1; }
	}

	//Metodo di calcolo dell'Integrale 
	virtual double Calcola(unsigned int nstep, const FunzioneBase& f) = 0;


	double m_a, m_b, m_segno;
};



//Classe Midpoint
class Midpoint : public Integratore {
	public:
	//Costruttore
	Midpoint() : Integratore() {;}

	private:
	//Implementazione metodo di calcolo
	double Calcola(unsigned int nstep, const FunzioneBase& f) override {

		double somma = 0; 
		double h = fabs(GetB() - GetA())/static_cast<double>(nstep);

		for(int i=0; i<nstep; i++) { somma += f.Eval(GetA() + (i + 0.5)* h); }
		
	return somma * h * GetSgn();
	}

};

#endif __Integrale_h__*/






/*******************************************
*     ALTRA POSSIBILE IMPLEMENTAZIONE      *
*******************************************/
/*#ifndef __Integrale_h__
#define __Integrale_h__

#include "Funzioni.h"

#include <iostream>

using namespace std;



//Classe astratta
class Integratore{
	public:
	//Costruttore di default
	Integratore() { m_h = 0; m_somma = 0; }
	//Distruttore
	~Integratore() {;}

	//Metodo integra - virtuale puro
	virtual double Integra(double a, double b, unsigned int nstep, FunzioneBase& f) = 0;

	//Metodo Get per il passo
	double GetH() { return m_h; }

	protected:
	double m_h, m_somma;
};



//Classe Midpoint
class Midpoint : public Integratore {
	public:
	//Costruttore di default
	Midpoint() : Integratore() {;}
	//Distruttore
	~Midpoint() {;}

	//Implementazione metodo Integra
	double Integra(double a, double b, unsigned int nstep, FunzioneBase& f) override {
		double segno = 0;
		//Controllo intervallo integrazione
		if(b > a) { segno = 1; }
		else{ segno = a; a = b; b = segno; segno = -1; }

		//Calcolo il passo - azzero somma
		m_somma = 0;
		m_h = fabs(b - a)/static_cast<double>(nstep);

		//Calcolo la somma opportuna
		for(int i=0; i<nstep; i++) {
			m_somma += f.Eval(a + (i + 0.5)*m_h);
		}

	return m_somma * m_h * segno;
	}
};

#endif //__Integrale_h__ */
