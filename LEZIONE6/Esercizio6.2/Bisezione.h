#ifndef __Bisezione_h__
#define __Bisezione_h__

#include "FunzioneBase.h"
#include "Solutore.h"

#include <iostream>
#include <cmath>

using namespace std;

class Bisezione : public Solutore{
	public:
	//Costruttore di default
	Bisezione() : Solutore() {;}
	//Costruttore - in ingresso precisione desiderata e numero massimo iterazioni
	Bisezione(double prec, int n_max) : Solutore(prec, n_max) {;}
	//Costruttore - in ingresso precisione, numero massimo iterazioni e estremi dell' intervallo
	Bisezione(double inizio, double fine, double prec, int n_max) : Solutore(inizio, fine, prec, n_max) {;}
	//Distruttore
	~Bisezione() {;}

	//Metodo per la ricerca degli zeri
	double CercaZeri(double a, double b, const FunzioneBase& f) override {
		//Effettuo un controllo su come sono stati inseriti gli estremi (e nel caso aggiusto)
		if(a>b){
			m_b = a;
			m_a = b;
		}
		else{
			m_a = a;
			m_b = b;
		}
		//Semi - ampiezza dell'intervallo considerato
		double tmp = (m_b - m_a)/2;
		cout << m_a << " " << m_b << endl;
		
		//Determino quale sia il segno del prodotto fra i valori assunti dalla funzione agli estremi dell'intervallo
		Segno test;
		double val1 = f.Eval(m_a); double val2 = f.Eval(m_b);
		double appo = test.Eval(val1)*test.Eval(val2);

		//Caso 1: appo è maggiore di 0
		if(appo > 0) { 
			cout << "Intervallo inserito non valido: funzione ha lo stesso segno ai bordi!!" << endl;
			exit(-2);
		}

		//Caso 2: appo è identicamente nullo
		else if(appo == 0){

			if(val1==0){ return m_a; }
			else{ return m_b; }

		}

		//Caso 3: appo è minore di zero
		else if(appo < 0) {

			//Sono arrivato alla precisione desiderata??
			if(tmp <= m_precisione){
				return (m_a + (m_b-m_a)/2);
			}
			
			//Ho raggiunto il numero massimo di iterazioni previsto??
			else if(n_it==n_maxit-1){ 
				m_precisione = tmp;
				return (m_a + (m_b-m_a)/2); 
			}

			double c = m_a + tmp;
			double val3 = f.Eval(c);

			//Primo dei due semi-intervalli è quello buono
			if((test.Eval(val1)*test.Eval(val3))<0){
				n_it = n_it + 1;
				CercaZeri(m_a, c, f);
			}

			//Funzione si annulla ad un estremo del primo semi-intervallo
			else if((test.Eval(val1)*test.Eval(val3))==0){
				if(f.Eval(m_a)==0) { return m_a; } 
				else return c;
			}

			//Secondo dei due semi-intervalli è quello buono
			else if((test.Eval(val3)*test.Eval(val2))<0){
				n_it=n_it + 1;
				CercaZeri(c, m_b, f);
			}

			//Funzione si annulla ad un estremo del secondo semi-intervallo
			else if((test.Eval(val3)*test.Eval(val2))==0){
				if(val3==0) return c;
				else return m_b;
			}
		}
		
		}

	
};

#endif //__Bisezione_h__

