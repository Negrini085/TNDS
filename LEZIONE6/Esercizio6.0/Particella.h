#ifndef __particella_h__
#define __particella_h__

#include <iostream>
#include <cmath>

using namespace std;

//Classe Particella
class Particella{
	public:
		//Metodo che permette di ottenere il valore della massa
		double GetMassa() const;
		//Metodo che permette di ottenere il valore della carica
		double GetCarica() const;
		//Metodo che permette di stampare i valori di massa e carica
		virtual void Stampa() const;
		//Costruttore che accetta in ingresso massa e carica
		Particella(double, double);
		//Metodo per modificare la massa
		void NewMassa(double);
		//Metodo per modificare la carica
		void NewCarica(double);
		

	protected:
		double m_massa, m_carica;
};


//Classe Elettrone
class Elettrone : public Particella{
	public:
	//Costruttore
	Elettrone();
	//Metodo che permette di stampare elettrone
	virtual void Stampa() const;
};

#endif //__Vettore_h__