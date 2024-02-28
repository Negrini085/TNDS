#ifndef __posizione_h__
#define __posizione_h__

#include <iostream>
#include <cmath>

using namespace std;

class Posizione{
	public:
		Posizione();//Costruttore di default(nessun argomento)
		Posizione(double, double, double);//Costruttore con le 3 coordinate come argomenti in ingresso
		double GetX() const;//Metodo per ottenere la coordinata cartesiana x della posizione
		double GetY() const;//Metodo per ottenere la coordinata cartesiana y della posizione
		double GetZ() const;//Metodo per ottenere la coordinata cartesiana z della posizione
		double GetR() const;//Metodo che restituisce il raggio
		double GetPhi() const;//Metodo che restituisce l'angolo Phi delle coordinate sferiche
		double GetTheta() const;//Metodo che restituisce l'angolo Theta delle coordinate sferiche
		double GetRho() const;//Metodo che restituisce il valore del raggio delle coordinate cilindriche
		double Distanza(const Posizione&) const;//Metodo che restituisce la distanza da un altro punto

	private:
		double m_x, m_y, m_z;
};

#endif //__posizione_h__