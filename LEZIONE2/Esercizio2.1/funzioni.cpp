#include "funzioni.h"
#include "Vettore.h"




//Funzione che consente di leggere dati da file - immagazzinati in un Vettore
Vettore Read(char* nome, int dim){
	ifstream file_in;
	file_in.open(nome);
	double appo;

	Vettore dati(dim);
	for(int i=0; i<dim; i++){
		file_in >> dati[i];
	}
	file_in.close();
 return dati;
}




//Funzione che stampa a file il contenuto di un Vettore
void Stampa(char* nome, Vettore& contenitore){
	double appo=0;
	int dim = contenitore.GetN();

	if(dim == 0) { cout << "Il vettore è vuoto!" << endl;}

	ofstream fileout; fileout.open(nome);
	fileout << "Il contenuto del vettore è: " << endl;
	for(int i=0; i<dim; i++){ fileout << contenitore.GetComponent(i) << endl; }
	fileout.close();

}




//Funzione che stampa a video il contenuto di un Vettore
void Stampa(Vettore& contenitore){
	int dim = contenitore.GetN();

	if(dim == 0) { cout << "Il vettore è vuoto!" << endl;}

	cout << "Il contenuto del vettore è: " << endl;
	for(int i=0; i<dim; i++){ cout << contenitore.GetComponent(i) << endl; }
}




//Funzione che calcola la media degli elementi di un Vettore
double CalcoloMedia(Vettore& contenitore){
	double appo = 0;
	int dim = contenitore.GetN();

	for(int i=0; i<dim; i++){ 
	appo = static_cast<double>(i)/static_cast<double>(i+1)*appo + contenitore[i]/static_cast<double>(i+1);
	}

return appo;
}




//Funzione che calcola la varianza degli elementi di un Vettore
double CalcoloVarianza(Vettore& contenitore){
	double ris = 0; int dim = contenitore.GetN();
	double med, med_prec;

	for(int i=0; i<dim; i++) {
		med_prec = med;
		med = static_cast<double>(i)/static_cast<double>(i+1)*med + contenitore[i]/static_cast<double>(i+1);
		ris = 1./static_cast<double>(i+1) * (i * ris + contenitore[i] * contenitore[i] + static_cast<double>(i) * med_prec * med_prec) - med * med;
	}

return ris;
}




//Metodo per calcolare la mediana
double CalcoloMediana(Vettore contenitore){
	int dim = contenitore.GetN();

	//Riordino il vettore
	selection_sort(contenitore);

	if(dim%2==0){
		return (contenitore[(dim/2)-1]+contenitore[dim/2])/2;
	}
	else{
		return contenitore[(dim-1)/2];
	}
}




//Funzione per riordinare il contenuto di un vettore
void selection_sort(Vettore& contenitore) {
	int ind; double min; int dim = contenitore.GetN();
		for(int i=0; i<dim; i++){
		min = contenitore[i];
		ind = i;
		for(int j=i; j<dim; j++){
			if(contenitore[j]<min){
				min = contenitore[j];
				ind = j;
			}
		}
		contenitore[ind] = contenitore[i];
		contenitore[i] = min;
	}
}