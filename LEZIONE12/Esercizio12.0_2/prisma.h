#ifndef __prisma_h__
#define __prisma_h__

#include "GenRandom.h"

#include <iostream>
#include <cmath>


#define USE_MATH_NDEFINES
using namespace std;

class EsperimentoPrisma {

	public:
	//Costruttore di default
	EsperimentoPrisma() : m_lambda1(579.1E-9), m_lambda2(404.7E-9), m_alpha(M_PI/3.), m_A_in(2.7), m_B_in(6000E-18), genera(1), m_sigma(0.3E-3) {
		
		//Calcolo gli indici di rifrazione
		m_n1_in = sqrt(m_A_in + m_B_in/pow(m_lambda1, 2));
		m_n2_in = sqrt(m_A_in + m_B_in/pow(m_lambda2, 2));

		//Calcolo gli angoli di deviazione minima relativi
		m_dm1_in = 2 * asin(m_n1_in * sin(m_alpha/2.)) - m_alpha;
		m_dm2_in = 2 * asin(m_n2_in * sin(m_alpha/2.)) - m_alpha;

		//Calcolo i due angoli teta1 e teta2
		m_th0_in = M_PI;
		m_th1_in = m_th0_in + m_dm1_in;
		m_th2_in = m_th0_in + m_dm2_in;
		}

	//Metodo di misura
	void Misura() {
		m_th0_mis = genera.GaussBM(m_th0_in, m_sigma);
		m_th1_mis = genera.GaussBM(m_th1_in, m_sigma);
		m_th2_mis = genera.GaussBM(m_th2_in, m_sigma);
	}

	//Metodo di analisi
	void Analizza() {
		//Determino i delta
		m_dm1_mis = m_th1_mis - m_th0_mis;
		m_dm2_mis = m_th2_mis - m_th0_mis;

		//Calcolo gli indici di rifrazione
		m_n1_mis = sin((m_dm1_mis + m_alpha)/2)/sin(m_alpha/2);
		m_n2_mis = sin((m_dm2_mis + m_alpha)/2)/sin(m_alpha/2);

		//Determino i parametri della relazione di Cauchy
		m_A_mis = (pow(m_n2_mis * m_lambda2, 2) - pow(m_n1_mis * m_lambda1, 2))/(pow(m_lambda2, 2) - pow(m_lambda1, 2)); 
		m_B_mis = (pow(m_n2_mis, 2) - pow(m_n1_mis, 2))/(pow(1./m_lambda2, 2) - pow(1./m_lambda1, 2)); 
	}

	//Metodi Get valori misurati
	double GetA_mis() const { return m_A_mis; }
	double GetB_mis() const { return m_B_mis; }
	double GetN1_mis() const { return m_n1_mis; }
	double GetN2_mis() const { return m_n2_mis; }
	double Getdm1_mis() const { return m_dm1_mis; }
	double Getdm2_mis() const { return m_dm2_mis; }
	double Getth0_mis() const { return m_th0_mis; }
	double Getth1_mis() const { return m_th1_mis; }
	double Getth2_mis() const { return m_th2_mis; }


	//Metodo Get valori reali
	double GetA_real() { return m_A_in; }
	double GetB_real() { return m_B_in; }
	double Getdm1_real() { return m_dm1_in; }
	double Getdm2_real() { return m_dm2_in; }
	double GetN1_real() { return m_n1_in; }
	double GetN2_real() { return m_n2_in; }
	double Getth0_real() { return m_th0_in; }
	double Getth1_real() { return m_th1_in; }
	double Getth2_real() { return m_th2_in; }
	double GetSigma() { return m_sigma; }

	private:
	//Lungezze d'onda
	double m_lambda1, m_lambda2, m_alpha, m_sigma;
	//Generatore
	GenRandom genera;
	//Data membri di input e misurati
	double m_A_in, m_A_mis;
	double m_B_in, m_B_mis;
	double m_n1_in, m_n1_mis;
	double m_n2_in, m_n2_mis;
	double m_dm1_in, m_dm1_mis;
	double m_dm2_in, m_dm2_mis;
	double m_th0_in, m_th0_mis;
	double m_th1_in, m_th1_mis;
	double m_th2_in, m_th2_mis;
};




#endif //__prisma_h__