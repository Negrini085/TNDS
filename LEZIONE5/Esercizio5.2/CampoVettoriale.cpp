#include "CampoVettoriale.h"
#include <iostream>

using namespace std;



/*******************************************
*       METODI CLASSE CAMPO VETTORIALE     *
********************************************/

//Costruttore per creare un vettore nullo nella posizione specificata
CampoVettoriale::CampoVettoriale(const Posizione& punto) : Posizione(punto){
	m_Fx = 0;
	m_Fy = 0;
	m_Fz = 0;
}
//Costruttore che nella posizione specificata crea un vettore con componenti passate
CampoVettoriale::CampoVettoriale(const Posizione& punto, double cmpx, double cmpy, double cmpz) : Posizione(punto){
	m_Fx = cmpx;
	m_Fy = cmpy;
	m_Fz = cmpz;
}
//Costruttore che accetta in ingresso 6 double (3 coordinate della posizione, 3 del campo)
CampoVettoriale::CampoVettoriale(double posx, double posy, double posz, double cmpx, double cmpy, double cmpz){
	m_x = posx;
	m_y = posy;
	m_z = posz;
	m_Fx = cmpx;
	m_Fy = cmpy;
	m_Fz = cmpz;
}
//Copy constructor
CampoVettoriale::CampoVettoriale(const CampoVettoriale& DaCopiare){
	m_x = DaCopiare.GetX();
	m_y = DaCopiare.GetY();
	m_z = DaCopiare.GetZ();
	m_Fx = DaCopiare.GetFx();
	m_Fy = DaCopiare.GetFy();
	m_Fz = DaCopiare.GetFz();
}


//Metodo per accedere alla componente Fx del CampoVettoriale
double CampoVettoriale::GetFx() const{
	return m_Fx;
}
//Metodo per accedere alla componente Fy del CampoVettoriale
double CampoVettoriale::GetFy() const{
	return m_Fy;
}
//Metodo per accedere alla componente Fz del CampoVettoriale
double CampoVettoriale::GetFz() const{
	return m_Fz;
}
//Metodo per modificare la componente Fx del CampoVettoriale
void CampoVettoriale::SetFx(double valore){
	m_Fx = valore;
}
//Metodo per modificare la componente Fy del CampoVettoriale
void CampoVettoriale::SetFy(double valore){
	m_Fy = valore;
}
//Metodo per modificare la componente Fz del CampoVettoriale
void CampoVettoriale::SetFz(double valore){
	m_Fz = valore;
}


//Metodo che restituisce il modulo del vettore
double CampoVettoriale::Modulo() const{
	return sqrt(pow(m_Fx, 2) + pow(m_Fy, 2) + pow(m_Fz, 2));
}
//Metodo per stampare un CampoVettoriale
void CampoVettoriale::StampaCV() const{
	cout << "Il vettore in posizione: (x,y,z) = (" << m_x << ", " << m_y << ", " << m_z << ") è il seguente: (Fx, Fy, Fz) = (" << m_Fx << ", " << m_Fy << ", " << m_Fz << ")." << endl;	
}


//Overloading operator+
CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale& DaSommare) const{
	CampoVettoriale somma(DaSommare);
	somma.SetFx(somma.GetFx() + m_Fx);
	somma.SetFy(somma.GetFy() + m_Fy);
	somma.SetFz(somma.GetFz() + m_Fz);

return somma;
}
//Overloading operator+=
CampoVettoriale& CampoVettoriale::operator+=(const CampoVettoriale& DaSommare){
	m_Fx += DaSommare.GetFx();
	m_Fy += DaSommare.GetFy();
	m_Fz += DaSommare.GetFz();

return *this;
}

