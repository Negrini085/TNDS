#include <iostream>
#include "Vettore.h"
#include <iomanip>
#include <cmath>
#include <cstdlib>

#define NDEBUG 

#include <assert.h>

using namespace std;

//Costruttore di default
Vettore::Vettore(){
    m_N = 0;
    m_v = NULL;
}


//Costruttore - crea un vettore di grandezza dim, elementi inzializzati a zero
Vettore::Vettore(unsigned int dim){
    m_N = dim;
    m_v = new double[dim];
    for(int i=0; i<dim; i++){
        m_v[i] = 0;
    }
}

//Distruttore
Vettore::~Vettore(){
	delete[] m_v;
}

//Metodo SetComponent
void Vettore::SetComponent(unsigned int ind, double val){
	assert((m_N > ind) && "Errore: l'indice selezionato è troppo grande.");
	if(ind<m_N){
    m_v[ind] = val;
  } 
	else{
		cout << "Errore: indice " << ind << ", dimensione: " << m_N << "." << endl;
		exit(-1);
	}
}

//Metodo GetComponent
double Vettore::GetComponent(unsigned int ind) const {
	assert((m_N > ind) && "Errore: l'indice selezionato è troppo grande.");
	if(ind<m_N){
    return m_v[ind];
  } 
	else{
		cout << "Errore: indice " << ind << ", dimensione: " << m_N << "." << endl;
		exit(-1);
	}
}

//Metodo per scambiare i contenuti di due caselle di memoria del Vettore
void Vettore::Scambia(unsigned int uno, unsigned int due){
	double appo = 0;
	appo = GetComponent(uno);
	SetComponent(uno, GetComponent(due));
	SetComponent(due, appo);
}

//Overloading operator[]
double& Vettore::operator[](unsigned int ind){
	assert((m_N > ind) && "Errore: l'indice è troppo grande");
	if(m_N > ind){
		return m_v[ind];
	}
	else{
		cerr << "Errore: l'indice è troppo grande." << endl;
		exit(-1);
	}
}

//Operatore di assegnazione
Vettore& Vettore::operator=(const Vettore &v){
	m_N = v.GetN();
	if(m_v){
		delete[] m_v;
	}
	m_v = new double[m_N];
	for(int i=0; i<m_N; i++){
		m_v[i] = v.GetComponent(i);
	}
return* this;
}

//Copy contructor
Vettore::Vettore(const Vettore& V){
	m_N = V.GetN();
	m_v = new double[m_N];
	for(int i=0; i<m_N; i++){
		m_v[i] = V.GetComponent(i);
	}
}
