#include "funzioni.h"





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





void Stampa(const char* nome, double* dati, int dim){
	ofstream fileout;

	fileout.open(nome);
	fileout << "I dati riordinati sono i seguenti: " << endl;
	for(int i=0; i<dim; i++){
		fileout << dati[i] << endl;
	}

}





double CalcoloMedia(double* dati, int dim){
  double appo=0;

	if(dim == 0) { return appo; }
  
	for(int i=0; i<dim; i++){ 
		appo = static_cast<double>(i)/static_cast<double>(i+1)*appo + dati[i]/static_cast<double>(i+1);
		}

  return appo;
}





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





double CalcoloMediana(double* dati, int dim){

	if(dim%2==0){
		return (dati[dim/2-1]+dati[dim/2])/2;
	}
	else{
		return (dati[(dim-1)/2]);
	}

}





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





double* Copia(double* DaCopiare, int dim) {
	double* copia = new double[dim];

	for(int i=0; i<dim; i++) { copia[i] = DaCopiare[i]; }

return copia;
}