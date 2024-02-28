#ifndef __classi_h__
#define __classi_h__

#include <iostream>

using namespace std;

//Classe Particella
class Particella{
	public:
		//Costruttore che accetta in ingresso massa e carica
		Particella(double massa, double carica);
		//CopyConstructor
		Particella(const Particella&);
		//Distruttore
		~Particella();
		
		//Metodo che permette di ottenere il valore della massa
		double GetMassa() const;
		//Metodo che permette di ottenere il valore della carica
		double GetCarica() const;
		//Metodo che permette di stampare i valori di massa e carica
		void StampaMC() const;

		//Metodo per modificare la massa
		void NewMassa(double);
		//Metodo per modificare la carica
		void NewCarica(double);
		

	protected:
		double m_massa, m_carica;
};




//Classe elettrone
class Elettrone : public Particella{
	public:
	//Costruttore
	Elettrone();
	//Distruttore
	~Elettrone();


	//Metodo che permette di stampare elettrone
	void StampaE() const;
};


#endif //__classi_h__