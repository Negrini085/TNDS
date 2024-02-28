#ifndef __CampoVettoriale_h__
#define __CampoVettoriale_h__

#include "Posizione.h"

#include <iostream>
#include <cmath>

using namespace std;

//Classe campo vettoriale
class CampoVettoriale : public Posizione{
	public:
	//Costruttore per creare un vettore nullo nella posizione specificata
	CampoVettoriale(const Posizione&);
	//Costruttore che nella posizione specificata crea un vettore con componenti passate
	CampoVettoriale(const Posizione&, double, double, double);
	//Costruttore che accetta in ingresso 6 double (3 coordinate della posizione, 3 del campo)
	CampoVettoriale(double, double, double, double, double, double);
	//Copy constructor
	CampoVettoriale(const CampoVettoriale&);

	//Metodo per accedere alla componente Fx del CampoVettoriale
	double GetFx() const;
	//Metodo per accedere alla componente Fy del CampoVettoriale
	double GetFy() const;
	//Metodo per accedere alla componente Fz del CampoVettoriale
	double GetFz() const;
	//Metodo per modificare la componente Fx del CampoVettoriale
	void SetFx(double);
	//Metodo per modificare la componente Fy del CampoVettoriale
	void SetFy(double);
	//Metodo per modificare la componente Fz del CampoVettoriale
	void SetFz(double);

	//Metodo che restituisce il modulo del vettore
	double Modulo() const;
	//Metodo per stampare un CampoVettoriale
	void StampaCV() const;
	
	//Overloading operator+
	CampoVettoriale operator+(const CampoVettoriale&) const;
	//Overloading operator+=
	CampoVettoriale& operator+=(const CampoVettoriale&);


	private:
	double m_Fx, m_Fy, m_Fz;
};

#endif