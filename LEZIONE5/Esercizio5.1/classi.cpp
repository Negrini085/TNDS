#include "classi.h"

#include <iostream>
#include <cmath>

using namespace std;





/*******************************************
*     IMPLEMENTAZIONE METODI PARTICELLA    *
*******************************************/

//Costruttore che accetta in ingresso massa e carica
Particella::Particella(double massa, double carica){
	m_carica = carica;
	m_massa = massa;
}
//CopyConstructor
Particella::Particella(const Particella& DaCopiare) {
	m_massa = DaCopiare.GetMassa();
	m_carica = DaCopiare.GetCarica();
}
//Distruttore
Particella::~Particella() { ; }

//Metodo che permette di ottenere il valore della massa
double Particella::GetMassa() const{
	return m_massa;
}
//Metodo che permette di ottenere il valore della carica
double Particella::GetCarica() const{
	return m_carica;
}
//Metodo che permette di stampare i valori di massa e carica
void Particella::StampaMC() const{
	cout << "Valore massa particella: " << m_massa << endl;
	cout << "Valore carica particella: " << m_carica << endl;
}
//Metodo che permette di modificare la massa di una Particella
void Particella::NewMassa(double nMassa){
	m_massa = nMassa;
}
//Metodo che permette di modificare la carica di una particella
void Particella::NewCarica(double nCarica){
	m_carica = nCarica;
}





/*******************************************
*     IMPLEMENTAZIONE METODI ELETTRONE     *
*******************************************/

//Costruttore
Elettrone::Elettrone(): Particella(9.1093837015E-31 , -1.602176634E-19){;}
//Distruttore
Elettrone::~Elettrone() { ; }

//Metodo per stampare masssa e carica
void Elettrone::StampaE() const {
	cout << "La massa dell'elettrone è: " << m_massa << endl;
	cout << "La carica dell'elettrone è: " << m_carica << endl;
}

