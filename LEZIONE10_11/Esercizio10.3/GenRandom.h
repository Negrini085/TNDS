#ifndef __GenRandom_h__
#define __GenRandom_h__

#include <iostream>
#include <cmath>

#define USE_MATH_NDEFINES

using namespace std;

class GenRandom{

	public:
	//Costruttore di default
	GenRandom(unsigned int tmp){
		m_m = pow(2, 31); 
		m_a = 1664525;
		m_c = 1013904223;
		m_seme = tmp;
		m_seme_iniziale = tmp;
	}
	//Metodi Get/Set per m_a
	unsigned int GetA() { return m_a; }
	void SetA(unsigned int tmp) { m_a = tmp; }
	//Metodi Get/Set per m_c
	unsigned int GetC() { return m_c; }
	void SetC(unsigned int tmp) { m_c = tmp;}
	//Metodi Get/Set per m_m
	unsigned int GetM() { return m_m;}
	void SetM(unsigned int tmp) { m_m = tmp;}

	//Metodi Get/Set per m_seme
	unsigned int GetSeme() { return m_seme; }
	void SetSeme(unsigned int tmp) { m_seme = tmp; }
	//Metodo Get m_seme_iniziale
	unsigned int GetSemeIn() { return m_seme_iniziale; }

	


	//Metodo che genera un numero casuale uniforme fra 0 e 1
	double Rand() { 
		m_seme = (m_a*m_seme + m_c)%m_m;
		return (double)m_seme/m_m;
	}
	//Distribuzione uniforme
	double Unif(double x_min, double x_max){
		return x_min + (x_max - x_min)*Rand();
	}
	//Distribuzione esponenziale
	double Exp(double lambda) {
		double y = Rand();
		return -(1/lambda) * log(1 - y);
	}
	//Distribuzione gaussiana (metodo A/R)
	double GaussAR(double media, double sigma) {
		double xmin = media - 5*sigma;
		double xmax = media + 5*sigma;
		double gauss_max = 1/(sqrt(2*M_PI)*sigma);
		double y, x;

		
		do{
			x = Unif(xmin, xmax);
			y = Unif(0, gauss_max);
		}while(y > (1/(sqrt(2*M_PI)*sigma))*exp(-pow((x-media), 2)/(2*sigma*sigma)));

	return x;
	}
	//Distribuzione Gaussiana (Box - Muller)
	double GaussBM(double media, double sigma) {
		double a = Rand();
		double b = Rand();
		double x = sqrt(-2*log(1.-a))*cos(2.*M_PI*b);
		
		return media + sigma*x;  
	}
	//Distribuzione retta y=x
	double RettX(double media) {
		 double u = Rand();
	return pow(media, 1.5)*sqrt(2*u);
	}

	private:
	unsigned int m_m, m_a, m_c;
	unsigned int m_seme, m_seme_iniziale;
};


#endif //__GenRandom_h__