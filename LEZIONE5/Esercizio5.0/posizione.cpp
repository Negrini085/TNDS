#include "posizione.h"

//Costruttore di Default
Posizione::Posizione(){
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

//Costruttore con le 3 coordinate come argomenti in ingresso
Posizione::Posizione(double x, double y, double z){
	m_x = x;
	m_y = y;
	m_z = z;
}

//Metodo per ottenere la coordinata cartesiana x
double Posizione::GetX() const{
	return m_x;
}

//Metodo per ottenere la coordinata cartesiana y
double Posizione::GetY() const{
	return m_y;
}

//Metodo per ottenere la coordinata cartesiana z
double Posizione::GetZ() const{
	return m_z;
}

//Metodo che restituisce il raggio
double Posizione::GetR() const{
	return sqrt(pow(m_x, 2)+pow(m_y, 2)+pow(m_z, 2));
}

//Metodo che restituisce l'angolo Phi delle coordinate sferiche
double Posizione::GetPhi() const{
	return atan2(m_y, m_x);
}

//Metodo che restituisce l'angolo Theta delle coordinate cilindriche
double Posizione::GetTheta() const{
	return acos(m_z/GetR());
}

//Metodo che restituisce il valore della proiezione di R sul piano xy (raggio del SR cilindrico)
double Posizione::GetRho() const{
	return sqrt(pow(m_x, 2)+pow(m_y, 2));
}

//Metodo che restituisce la distanza da un altro punto
double Posizione::Distanza(const Posizione& riferimento) const {
	return sqrt(pow((m_x-riferimento.GetX()), 2) + pow((m_y-riferimento.GetY()), 2) + pow((m_z-riferimento.GetZ()), 2) );
}
