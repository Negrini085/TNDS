#include "Vettore.h"

#define NDEBUG
#include <iostream>
#include <assert.h>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;




//Funzione che permette di "leggere" i contenuti di un file e memorizzarli in un Vettore di tipo T
template <typename T> Vettore<T> Read(char* nome, unsigned int ndati){
	Vettore<T> V(ndati);
	ifstream filein(nome);
	
	assert((filein) && "Errore: il file di input non esiste.");
	if(!filein){
		cout << "Il file di input non esiste: esco!!" << endl; exit(-3);
		}

		T appo = 0;
		for(int i=0; i<ndati; i++){
			filein >> V[i];
			assert((!filein.eof()) && "Errore: fine del file raggiunta!!");
			if(filein.eof()){
				cout << "Fine del file raggiunta: esco!!" << endl;
				filein.close(); exit(-4);
			}
		}
		
	filein.close();

return V;
};




//Funzione che permette di stampare il contenuto di un Vettore a file (richiede specificazione nome)
template <typename T> void Stampa(char* nome, const Vettore<T>& contenitore){
	ofstream fileout(nome); int dim = contenitore.GetN();
	assert((fileout) && "Errore: mancata apertura del file di output");

	if(!fileout) {
		cout << "Errore in apertura del file di output: esco!!" << endl; exit(-5);
		}
	
	fileout << "Contenuto del vettore: " << endl;
	for(int i=0; i<dim; i++){
			fileout << setw(10) << contenitore.GetComponent(i) << endl;
	  }
	
	fileout.close();
}




//Funzione che permette di stampare a video il contenuto di un vettore
template <typename T> void Stampa(const Vettore<T>& contenitore){
	int dim = contenitore.GetN();

	cout << "Contenuto del vettore: " << endl;
	for(int i=0; i<dim; i++){
		cout << setw(10) << contenitore.GetComponent(i) << endl;
	}
}




//Funzione che permette di calcolare la media degli elementi contenuti in un Vettore
template <typename T> double CalcoloMedia(const Vettore<T>& contenitore){
	double appo = 0;
	int dim = contenitore.GetN();

	for(int i=0; i<dim; i++){
		appo = appo * static_cast<double>(i)/static_cast<double>(i+1) + contenitore.GetComponent(i)/static_cast<double>(i+1);
	}

return appo;
}




//Funzione che permette di calcolare la varianza degli elementi contenuti in un Vettore
template <typename T> double CalcoloVarianza(Vettore<T>& contenitore){
	int dim = contenitore.GetN();
	double med, med_prec; med = 0;
	double ris = 0;

	for(int i=0; i<dim; i++) {
		med_prec = med;
		med = static_cast<double>(i)/static_cast<double>(i+1)*med + contenitore[i]/static_cast<double>(i+1);
		ris = 1./static_cast<double>(i+1) * (i * ris + contenitore[i] * contenitore[i] + static_cast<double>(i) * med_prec * med_prec) - med * med;
	}

return ris;
}




//Funzione che riordina gli elementi di un Vettore in ordine crescente (SelectionSort)
template <typename T> void SelectionSort(Vettore<T>& DaOrdinare){
	T min = 0;
	int ind = 0;
	int dim = DaOrdinare.GetN();

	for(int i=0; i<dim; i++){
		min = DaOrdinare[i];
		ind = i;
		for(int j=i; j<dim; j++){
			if(DaOrdinare[j]<min){
				min = DaOrdinare[j];
				ind = j;
			}
		}
		DaOrdinare.Scambia(ind, i);
	}
	
}




//Funzione che permette di calcolare la mediana degli elementi contenuti in un vettore
template <typename T> double CalcoloMediana(Vettore<T> contenitore){
	T min = 0;
	int ind = 0;
	int dim = contenitore.GetN();

	SelectionSort(contenitore); 
	if(dim%2==0){
		return (double)(contenitore[(dim/2)-1]+contenitore[dim/2])/2;
	}
	else{
		return contenitore[(dim-1)/2];
	}
}