#include "PuntoMateriale.h"
#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES
#define eps0 8.854187E-12
#define G_univ 6.67E-11
using namespace std;

//Costruttore che inizializza a 0 tutte le variabili
PuntoMateriale::PuntoMateriale() : Posizione(), Particella(){}

//Costruttore che prende in ingresso posizione, massa e carica della sorgente
PuntoMateriale::PuntoMateriale(const Posizione& Pos, double massa, double carica) : Particella(massa, carica), Posizione(Pos){;}

//Costruttore che prende in ingresso le tre coordinate, massa e carica
PuntoMateriale::PuntoMateriale(double x, double y, double z, double massa, double carica) : Posizione(x,y,z), Particella(massa, carica){;}

//Copy constructor
PuntoMateriale::PuntoMateriale(const PuntoMateriale& DaCopiare): Posizione(DaCopiare), Particella(DaCopiare){;}

//Metodo che permette di stampare un punto materiale
void PuntoMateriale::StampaPM(){
	cout << "Il punto materiale in posizione: (" << m_x << ", " << m_y << ", " << m_z << ") ha massa: " << m_massa << " e carica " << m_carica << "." << endl;
}

//Metodo per calcolo campo elettrico in posizione r
CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& punto){

	double dist = Distanza(punto);
	double mod = m_carica/(4 * M_PI * eps0 * pow(dist, 3));

	double Ex = mod*(punto.GetX() - m_x);
	double Ey = mod*(punto.GetY() - m_y);
	double Ez = mod*(punto.GetZ() - m_z);
	CampoVettoriale el(punto, Ex, Ey, Ez);

return el;
}

//Metodo per calcolare campo gravitazionale in posizione r
CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& punto){
	double dist = Distanza(punto);
	double mod = G_univ * m_massa/pow(dist, 2);

	double Gx = -mod*(punto.GetX() - m_x);
	double Gy = -mod*(punto.GetY() - m_y);
	double Gz = -mod*(punto.GetZ() - m_z);
	CampoVettoriale grav(punto, Gx, Gy, Gz);

return grav;
};
