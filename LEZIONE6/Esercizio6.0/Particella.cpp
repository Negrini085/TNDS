#include "Particella.h"
#include <iostream>

using namespace std;

/********************************
*    METODI CLASSE PARTICELLA   *
********************************/

//Metodo che permette di ottenere il valore della massa
double Particella::GetMassa() const{
	return m_massa;
}
//Metodo che permette di ottenere il valore della carica
double Particella::GetCarica() const{
	return m_carica;
}
//Metodo che permette di stampare i valori di massa e carica
void Particella::Stampa() const{
	cout << "Valore massa particella: " << m_massa << endl;
	cout << "Valore carica particella: " << m_carica << endl;
}
//Costruttore che accetta in ingresso massa e carica
Particella::Particella(double massa, double carica){
	m_massa = massa;
	m_carica = carica;
}
//Metodo che permette di modificare la massa di una Particella
void Particella::NewMassa(double nMassa){
	m_massa = nMassa;
}
//Metodo che permette di modificare la carica di una particella
void Particella::NewCarica(double nCarica){
	m_carica = nCarica;
}




/********************************
*    METODI CLASSE ELETTRONE    *
********************************/

//Costruttore
Elettrone::Elettrone(): Particella(9.1093837015E-31 , -1.602176634E-19){};

//Metodo per stampare massa e carica
void Elettrone::Stampa() const {
	cout << "La massa dell'elettrone è: " << m_massa << endl;
	cout << "La carica dell'elettrone è: " << m_carica << endl;
}