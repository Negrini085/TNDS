#include "PuntoMateriale.h"
#include <iostream>
#define USE_MATH_NDEFINES
#include <cmath>

using namespace std;

//Costruttore che inizializza a 0 tutte le variabili
PuntoMateriale::PuntoMateriale() : Posizione(), Particella(){}

//Costruttore che prende in ingresso posizione, massa e carica della sorgente
PuntoMateriale::PuntoMateriale(const Posizione& Pos, double massa, double carica) : Particella(massa, carica), Posizione(Pos){}

//Costruttore che prende in ingresso le tre coordinate, massa e carica
PuntoMateriale::PuntoMateriale(double x, double y, double z, double massa, double carica) : Posizione(x,y,z), Particella(massa, carica){};

//Copy constructor
PuntoMateriale::PuntoMateriale(const PuntoMateriale& DaCopiare): Posizione(DaCopiare), Particella(DaCopiare){};

//Metodo che permette di stampare un punto materiale
void PuntoMateriale::StampaPM(){
	cout << "Il punto materiale in posizione: (" << m_x << ", " << m_y << ", " << m_z << ") ha massa: " << m_massa << " e carica " << m_carica << "." << endl;
}

//Metodo per calcolo campo elettrico in posizione r
CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& punto) const{
	Posizione gen(m_x, m_y, m_z);
	double dist = gen.Distanza(punto);
	double mod = m_carica/(4*M_PI*(8.85418781762E-12)*pow(dist, 3));
	double Ex = mod*(punto.GetX() - m_x);
	double Ey = mod*(punto.GetY() - m_y);
	double Ez = mod*(punto.GetZ() - m_z);
	CampoVettoriale el(punto, Ex, Ey, Ez);

return el;
}