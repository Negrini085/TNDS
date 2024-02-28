#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__

#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"
#include <iostream>

using namespace std;

class PuntoMateriale : public Particella, Posizione{
	public:
	//Costruttore che inizializza a 0 tutte le variabili
	PuntoMateriale();
	//Costruttore che prende in ingresso posizione, massa e carica della sorgente
	PuntoMateriale(const Posizione&, double, double);
	//Costruttore che prende in ingresso le tre coordinate, massa e carica
	PuntoMateriale(double, double, double, double, double);
	//Copy constructor
	PuntoMateriale(const PuntoMateriale&);


	//Metodo che permette di stampare un punto materiale
	void StampaPM();
	//Metodo per calcolare campo elettrico in posizione r
	CampoVettoriale CampoElettrico(const Posizione&);
	//Metodo per calcolare campo gravitazionale in posizione r
	CampoVettoriale CampoGravitazionale(const Posizione&);	
};


#endif //__PuntoMateriale_h__