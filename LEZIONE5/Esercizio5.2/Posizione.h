#ifndef __Posizione_h__
#define __Posizione_h__

#include <iostream>
#include <cmath>

using namespace std;

//Classe posizione
class Posizione{
	public:
		//Costruttore di default(nessun argomento)
		Posizione();
		//Costruttore con le 3 coordinate come argomenti in ingresso
		Posizione(double, double, double);
		//Copy constructor
		Posizione(const Posizione&);

		//Metodo per ottenere la coordinata cartesiana x della posizione
		double GetX() const;
		//Metodo per ottenere la coordinata cartesiana y della posizione
		double GetY() const;
		//Metodo per ottenere la coordinata cartesiana z della posizione
		double GetZ() const;
		//Metodo per modificare la coordinata cartesiana x della posizione
		void SetX(double);
		//Metodo per modificare la coordinata cartesiana y della posizione
		void SetY(double);
		//Metodo per modificare la coordinata cartesiana z della posizione
		void SetZ(double);
		//Metodo che restituisce il raggio
		double GetR() const;
		//Metodo che restituisce l'angolo Phi delle coordinate sferiche
		double GetPhi() const;
		//Metodo che restituisce l'angolo Theta delle coordinate cilindriche
		double GetTheta() const;
		//Metodo che restituisce il raggio delle coordinate cilindriche
		double GetRho() const;
		//Metodo che restituisce la distanza da un altro punto
		double Distanza(const Posizione&) const;

		//Overloading operatore +
		Posizione operator+(const Posizione& DaSommare) const;


	protected:
		double m_x, m_y, m_z;
};


#endif //__Posizione_h__