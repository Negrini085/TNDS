#include "Posizione.h"

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

//Copy constructor
Posizione::Posizione(const Posizione& Pos){
	m_x = Pos.GetX();
	m_y = Pos.GetY();
	m_z = Pos.GetZ();
}

//Metodo per ottenere la coordinata cartesiana x della posizione
double Posizione::GetX() const{
	return m_x;
}

//Metodo per ottenere la coordinata cartesiana y della posizione
double Posizione::GetY() const{
	return m_y;
}

//Metodo per ottenere la coordinata cartesiana z della posizione
double Posizione::GetZ() const{
	return m_z;
}

//Metodo per modificare la coordinata cartesiana x della posizione
void Posizione::SetX(double candidato){
	m_x = candidato;
}

//Metodo per modificare la coordinata cartesiana y della posizione
void Posizione::SetY(double candidato){
	m_y = candidato;
}

//Metodo per modificare la coordinata cartesiana z della posizione
void Posizione::SetZ(double candidato){
	m_z = candidato;
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
double Posizione::Distanza(const Posizione& riferimento) const{
	return sqrt(pow((m_x-riferimento.GetX()), 2) + pow((m_y-riferimento.GetY()), 2) + pow((m_z-riferimento.GetZ()), 2) );
}

//Overloading operatore somma
Posizione Posizione::operator+(const Posizione& DaSommare) const{
	Posizione somma(DaSommare);
	somma.SetX(somma.GetX() + m_x);
	somma.SetY(somma.GetY() + m_y);
	somma.SetZ(somma.GetZ() + m_z);

return somma;
}

//Metodo che consente la stampa di una posizione
void Posizione::StampaP() const{
	cout << "(x,y,z) = (" << m_x << "," << m_y << "," << m_z << ")." << endl;
};
		