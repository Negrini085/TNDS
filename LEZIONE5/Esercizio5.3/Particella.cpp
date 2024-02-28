#include "Particella.h"
#include <iostream>

using namespace std;

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
//Costruttore che accetta in ingresso massa e carica
Particella::Particella(double massa, double carica){
	m_massa = massa;
	m_carica = carica;
}
//Costruttore che inizializza a zero entrambi i campi
Particella::Particella(){
	m_massa = 0;
	m_carica = 0;
}
//Copy constructor
Particella::Particella(const Particella& DaCopiare){
	m_massa = DaCopiare.GetMassa();
	m_carica = DaCopiare.GetCarica();
};
//Metodo che permette di modificare la massa di una Particella
void Particella::SetMassa(double nMassa){
	m_massa = nMassa;
}
//Metodo che permette di modificare la carica di una particella
void Particella::SetCarica(double nCarica){
	m_carica = nCarica;
}

