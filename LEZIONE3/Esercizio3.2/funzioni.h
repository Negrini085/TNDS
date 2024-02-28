#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream> 
#include <vector>
#include <cmath>

#define NDEBUG
#include <assert.h>

using namespace std;




//Funzione che "legge" tutto il contenuto di un file e che memorizza in un vector la totalità degli elementi.
template <typename T> vector<T> LeggiTutto(char* nome){
	T appo = 0;
	ifstream filein(nome);
	vector<T> DaCaricare;

	if(!filein){
		cerr << "File di input non trovato: esco!!" << endl;
		exit(-3);
	}
	while(filein >> appo){ DaCaricare.push_back(appo);}
	filein.close();

return DaCaricare;
}




//Funzione che stampa a file (specificarne il nome!) il contenuto di un vector
template <typename T> void Stampa( const vector<T>& contenitore, const char* nome){
ofstream fileout(nome);
	int dim = contenitore.size();

	assert((fileout) && "Errore: mancata apertura/creazione del file di output");
	if(!fileout){
		cerr << "Errore in apertura/creazione del file di output: esco!!" << endl;
		exit(-2);
	}

	if(dim == 0) { fileout << "Il vettore è vuoto" << endl;}
	else{ fileout << "Il contenuto del vettore è: " << endl;}

	for(int i=0; i<dim; i++){ fileout << setw(10) << contenitore[i] << endl; }
	cout << endl << "I dati sono stati stampati sul file: " << nome << endl;
	fileout.close();

}




//Funzione che permette di stampare a video il contenuto di un vettore
template <typename T> void Stampa(const vector<T>& contenitore){
	int dim = contenitore.size();

	if(dim == 0) { cout << "Il vector è vuoto!" << endl; }
	else{ cout << "Il contenuto del vettore è: " << endl; }
	
	for(int i=0; i<dim; i++){ cout << setw(10) << contenitore[i] << endl; }
}




//Funzione che consente di inserire in un vector un numero specificato di dati
//presenti in un file (specificarne il nome)
template <typename T> vector<T> Leggi(char* nome, unsigned int ndati){
	vector<T> V;
	ifstream filein(nome);
	
	assert((filein) && "Errore: il file di input non esiste.");

	if(!filein){
		cerr << "Il file di input non esiste: esco!!" << endl;
		exit(-3);
	}


	T appo = 0;
	while((filein >> appo) && (V.size()<ndati)){
		V.push_back(appo);
	}
	if(V.size() < ndati){
		cout << "Il file non contiene un numero così elevato di dati. Sul vector sono stati caricati tutti i dati presenti sul file." << endl;
	}

	filein.close();
return V;
};




//Funzione che permette di calcolare la media degli elementi contenuti in un vector
template <typename T> double CalcoloMedia(const vector<T>& contenitore){
	double appo = 0;
	int dim = contenitore.size();

	for(int i=0; i<dim; i++){
		appo = appo * static_cast<double>(i)/static_cast<double>(i+1) + contenitore[i]/static_cast<double>(i+1);
	}

return appo;
}




//Funzione che permette di calcolare la varianza degli elementi contenuti in un vector
template <typename T> double CalcoloVarianza(const vector<T>& contenitore){
	int dim = contenitore.size();
	double med, med_prec; med = 0;
	double ris = 0;

	for(int i=0; i<dim; i++) {
		med_prec = med;
		med = static_cast<double>(i)/static_cast<double>(i+1)*med + contenitore[i]/static_cast<double>(i+1);
		ris = 1./static_cast<double>(i+1) * (i * ris + contenitore[i] * contenitore[i] + static_cast<double>(i) * med_prec * med_prec) - med * med;
	}

return ris;
}




//Funzione che permette di calcolare la mediana degli elementi contenuti in un vector
template <typename T> double CalcoloMediana(vector<T> contenitore){
	T min = 0;
	int ind = 0;
	int dim = contenitore.size();

	sort(contenitore.begin(), contenitore.end());
	if(dim%2==0){
		return (double)(contenitore[(dim/2)-1]+contenitore[dim/2])/2;
	}
	else{
		return contenitore[(dim-1)/2];
	}
}
