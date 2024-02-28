#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vettore{

public:
//Costruttori (default e con intero)
  Vettore();
  Vettore(unsigned int N);
//Distruttore
	~Vettore();
//Dimensione della classe e funzionalità per lettura/scrittura elementi
  unsigned int GetN() const {return m_N;}
  void SetComponent(unsigned int, double);
  double GetComponent(unsigned int) const;
//Metodo scambia 
	void Scambia(unsigned int, unsigned int);
//Definizione di operazioni e processi per effettuare uguaglianze/operazioni fra vettori
	double& operator[](unsigned int);
	Vettore& operator=(const Vettore&);
	Vettore(const Vettore&);

private:
  unsigned int m_N;
  double* m_v;
};

#endif // __Vettore_h__

