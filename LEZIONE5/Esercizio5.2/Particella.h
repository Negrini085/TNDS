#ifndef __Particella_h__
#define __Particella_h__

#include <iostream>

using namespace std;

class Particella{
	public:
		//Metodo che permette di ottenere il valore della massa
		double GetMassa() const;
		//Metodo che permette di ottenere il valore della carica
		double GetCarica() const;
		//Metodo che permette di stampare i valori di massa e carica
		void StampaMC() const;
		//Costruttore che accetta in ingresso massa e carica
		Particella(double, double);
		//Costruttore che inizializza a zero entrambi i campi
		Particella();
		//Copy constructor
		Particella(const Particella&);
		//Metodo per modificare la massa
		void SetMassa(double);
		//Metodo per modificare la carica
		void SetCarica(double);
		

	protected:
		double m_massa, m_carica;
};

#endif //__Particella_h__