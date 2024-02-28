#ifndef __Posizione_h__
#define __Posizione_h__

#include <iostream>
#include <cmath>

using namespace std;

class Posizione{
	public:
		Posizione();//Costruttore di default(nessun argomento)
		Posizione(double, double, double);//Costruttore con le 3 coordinate come argomenti in ingresso
		Posizione(const Posizione&);//Copy constructor
		double GetX() const;//Metodo per ottenere la coordinata cartesiana x della posizione
		double GetY() const;//Metodo per ottenere la coordinata cartesiana y della posizione
		double GetZ() const;//Metodo per ottenere la coordinata cartesiana z della posizione
		void SetX(double);//Metodo per modificare la coordinata cartesiana x della posizione
		void SetY(double);//Metodo per modificare la coordinata cartesiana y della posizione
		void SetZ(double);//Metodo per modificare la coordinata cartesiana z della posizione
		double GetR() const;//Metodo che restituisce il raggio
		double GetPhi() const;//Metodo che restituisce l'angolo Phi delle coordinate sferiche
		double GetTheta() const;//Metodo che restituisce l'angolo Theta delle coordinate cilindriche
		double GetRho() const;//Metodo che restituisce il valore della proiezione di R sul piano xy (raggio del SR cilindrico)
		double Distanza(const Posizione&) const;//Metodo che restituisce la distanza da un altro punto
		Posizione operator+(const Posizione&) const;//Overloading operatore somma
		void StampaP() const;
		//Metodo che consente la stampa di una posizione

	protected:
		double m_x, m_y, m_z;
};

#endif //__Posizione_h__