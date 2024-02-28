#include "Solutore.h"
#include <iostream>

using namespace std;


//Costruttore di default
Solutore::Solutore(){
	m_a = 0; 
	m_b = 0;
	m_precisione = 0;
	n_maxit = 0;
	n_it = 0;
}

//Costruttore - in ingresso precisione desiderata e numero massimo iterazioni
Solutore::Solutore(double prec, int n_max){
	m_a = 0; 
	m_b = 0;
	m_precisione = prec;
	n_maxit = n_max;
	n_it = 0;
}

//Costruttore che accetta in ingresso precisione, numero massimo iterazioni e estremi dell' intervall
Solutore::Solutore(double inizio, double fine, double prec, int n_max){
	m_a = inizio; 
	m_b = fine;
	m_precisione = prec;
	n_maxit = n_max;
	n_it = 0;
}

//Metodo per la modifica della precisione
void Solutore::SetPrecision(double newprec){
	m_precisione = newprec;
}

//Metodo per la modifica del numero massimo di iterazioni
void Solutore::SetNmax(double newnmax){
	n_maxit = newnmax;
}

//Metodo per ottenere la precisione
double Solutore::GetPrecision() const{
	return m_precisione;
}

//Metodo per ottenere il numero di iterazioni
double Solutore::GetNit() const{
	return n_it;
}

//Metodo per ottenere il numero massimo di iterazioni
double Solutore::GetNmaxit() const{
	return n_maxit;
}

//Metodo per ottenere l'estremo sinistro dell`intervallo
double Solutore::GetA() const{
	return m_a;
}

//Metodo per ottenere l'estremo destro dell`intervallo
double Solutore::GetB() const{
	return m_b;
}
