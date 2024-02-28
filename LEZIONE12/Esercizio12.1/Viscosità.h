#ifndef __Viscosita_h__
#define __Viscosita_h__

#include "GenRandom.h"

#include <iostream>
#include <cmath>

using namespace std;

class Viscosita {
	public:
	//Costruttore 
	Viscosita(double R) : m_eta_real(0.83), m_dens_all(2700), m_dens_gl(1250), m_accg(9.81), m_raggio_real(R), m_pos1_real(0.2), m_pos2_real(0.8), m_raggio_err(0.0001), m_tempo_err(0.01), m_pos_err(0.001), genera(1) {
		//Inizializzo i valori misurati a zero
		m_eta_mis = 0; m_tempo_mis = 0; m_raggio_mis = 0; m_pos1_mis = 0; m_pos2_mis = 0;

		//Calcolo l'intervallo di tempo "Reale"
		double sep = m_pos2_real - m_pos1_real;
		m_tempo_real = (9 * sep * m_eta_real)/(2 * pow(m_raggio_real, 2) * (m_dens_all - m_dens_gl) * m_accg);
		
	}


	//Metodi Get/Set per m_eta_real
	double GetEtaR() { return m_eta_real; }
	void SetEtaR(double tmp) { m_eta_real = tmp; }
	//Metodi Get/Set m_raggio_real
	double GetRaggioR() { return m_raggio_real; }
	void SetRaggioR(double tmp) {
		double sep = m_pos2_real - m_pos1_real;
		m_raggio_real = tmp;
		m_tempo_real = (9 * sep * m_eta_real)/(2 * pow(m_raggio_real, 2) * (m_dens_all - m_dens_gl) * m_accg);
	}
	//Metodo Get per m_eta_mis
	double GetEtaM() { return m_eta_mis; }
	//Metodo Get m_raggio_mis
	double GetRaggioM() { return m_raggio_mis; }
	//Metodo Get m_tempo_mis
	double GetTempoM() { return m_tempo_mis; }
	//Metodi Get/Set errore posizione
	double GetErrPos() { return m_pos_err; }
	void SetErrPos(double tmp) { m_pos_err = tmp; }
	//Metodi Get/Set errore raggio
	double GetErrRag() { return m_raggio_err; }
	void SetErrRag(double tmp) { m_raggio_err = tmp; }
	//Metodi Get/Set errore tempo
	double GetErrTmp() { return m_tempo_err; }
	void SetErrTmp(double tmp) { m_tempo_err = tmp; }



	//Metodo Misura (vado a generare valori di raggio, tempo e distanza)
	void Misura() {
		m_pos1_mis = genera.GaussBM(m_pos1_real, m_pos_err);
		m_pos2_mis = genera.GaussBM(m_pos2_real, m_pos_err);
		m_tempo_mis = genera.GaussBM(m_tempo_real, m_tempo_err);
		m_raggio_mis = genera.GaussBM(m_raggio_real, m_raggio_err);
	}	

	//Metodo per ottenere un valore di eta misurato
	void Analizza() {
		if(m_tempo_mis == 0) { cout << "Tempo misurato pari a zero: esco!!!" << endl; exit(-2); }

		double sep, vel; 
		sep = m_pos2_mis - m_pos1_mis; vel = sep/m_tempo_mis;
		m_eta_mis = (2 * pow(m_raggio_mis, 2) * (m_dens_all - m_dens_gl) * m_accg)/(9 * vel);
	}

	private:
	GenRandom genera;
	double m_eta_mis, m_eta_real;
	double m_pos1_real, m_pos2_real;
	double m_pos1_mis, m_pos2_mis;
	double m_tempo_mis, m_tempo_real;
	double m_raggio_mis, m_raggio_real;
	double m_tempo_err, m_raggio_err, m_pos_err;
	double m_dens_all, m_dens_gl, m_accg;
	};

#endif //__Viscosità_h__