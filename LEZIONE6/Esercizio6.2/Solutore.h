#ifndef __Solutore_h__
#define __Solutore_h__

#include "FunzioneBase.h"

class Solutore{
	public:
	//Costruttore senza alcun argomento
	Solutore();
	//Costruttore che accetta in ingresso la precisione con la quale si vuole conoscere il numero
	Solutore(double prec, int n_max);
	//Costruttore che accetta in ingresso precisione, numero massimo iterazioni e estremi dell' intervallo
	Solutore(double inizio, double fine, double prec, int n_max);
	//Distruttore
	~Solutore() {;}

	//Metodo per la ricerca degli zeri(by ref)
	virtual double CercaZeri(double a, double b, const FunzioneBase& f) = 0;

	//Metodo per la modifica della precisione
	void SetPrecision(double newprec);
	//Metodo per la modifica del numero massimo di iterazioni
	void SetNmax(double newnmax);

	//Metodo per ottenere la precisione
	double GetPrecision() const;
	//Metodo per ottenere il numero di iterazioni
	double GetNit() const;
	//Metodo per ottenere il numero massimo di iterazioni
	double GetNmaxit() const;
	//Metodo per ottenere l'estremo sinistro dell`intervallo
	double GetA() const;
	//Metodo per ottenere l'estremo destro dell`intervallo
	double GetB() const;	
	
	protected:
	double m_a, m_b;
	double m_precisione;
	int n_maxit, n_it;
};

#endif //__Solutore_h__
