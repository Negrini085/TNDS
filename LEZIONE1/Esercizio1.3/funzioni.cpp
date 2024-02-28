#include "funzioni.h"




//Funzione per caricare dati da file in un array di double
double* CaricaDaFile(char* nome, int dim){
  ifstream filein;
  double* dati = new double[dim];

  filein.open(nome);
  for(int i=0; i<dim; i++){
    filein >> dati[i];
    if(filein.eof()){
      cout << "Il file in questione non contiene un numero così elevato di dati." << endl;
			delete[] dati;
      exit(-2);
    }
  }
  filein.close();

  return dati;
}




//Funzione per stampare a file i dati contenuti in un array di double
void Stampa(char* nome, double* dati, int dim){
	ofstream fileout;

	fileout.open(nome);
	fileout << "I dati riordinati sono i seguenti: " << endl;
	for(int i=0; i<dim; i++){
		fileout << dati[i] << endl;
	}

}




//Funzione per stampare a video i dati contenuti in un array di double
void Stampa(double* dati, int dim){
	for(int i=0; i<dim; i++){
		cout << dati[i] << endl;
	}
}




//Funzione per calcolare la media di un set di dati double
double CalcoloMedia(double* dati, int dim){
  double appo=0;

	if(dim == 0) { return appo; }
  
	for(int i=0; i<dim; i++){ 
		appo = static_cast<double>(i)/static_cast<double>(i+1)*appo + dati[i]/static_cast<double>(i+1);
		}

  return appo;
}




//Funzione per calcolare la varianza di un set di dati double
double CalcoloVarianza(double* dati, int dim){
	double ris = 0;

	if(dim == 0) { return ris; }
	double med, med_prec;

	for(int i=0; i<dim; i++) {
		med_prec = med;
		med = static_cast<double>(i)/static_cast<double>(i+1)*med + dati[i]/static_cast<double>(i+1);
		ris = 1./static_cast<double>(i+1) * (i * ris + dati[i] * dati[i] + static_cast<double>(i) * med_prec * med_prec) - med * med;
	}

	return ris;
}




//Funzione per calcolare la mediana di un set di dati double
double CalcoloMediana(double* dati, int dim){

	if(dim%2==0){
		return (dati[dim/2-1]+dati[dim/2])/2;
	}
	else{
		return (dati[(dim-1)/2]);
	}

}




//Algoritmo selection sort per riordinare i dati
void selection_sort(double* daordinare, int dim){
	double min=0;
	int ind=0;
	for(int i=0; i<dim; i++){
		ind = i;
    min = daordinare[i];
		for(int k=i; k<dim; k++){
			if(daordinare[k]<min){
				min = daordinare[k];
				ind = k;
			}
		}
		daordinare[ind] = daordinare[i];
		daordinare[i] = min;
	}
}





//Funzione che consente di copiare il contenuto di un array
double* Copia(double* DaCopiare, int dim) {
	double* copia = new double[dim];

	for(int i=0; i<dim; i++) { copia[i] = DaCopiare[i]; }

return copia;
}