#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

double* CaricaDaFile(char*, int);
void Stampa(const char*, double*, int);
double CalcoloMedia(double*, int);
double CalcoloVarianza(double*, int);
double CalcoloMediana(double*, int);
void selection_sort(double*, int);


int main(int argc, char** argv){

	if(argc<4){//errore in utilizzo del programma
    cout<<"Uso del programma:" << argv[0] << " <n_data> <filename input> <filename output>" << endl;
    return -1;
  }

  int ndati=atoi(argv[1]);
  double* dati = CaricaDaFile(argv[2], ndati);
	
	cout << endl << endl;
  cout << "La media dei dati selezionati è: " << CalcoloMedia(dati, ndati) << "." << endl;
  cout << "La varianza dei dati selezionati è: " << CalcoloVarianza(dati, ndati) << "." << endl;
	selection_sort(dati, ndati);
	cout  << "La mediana dei dati selezionati è: " << CalcoloMediana(dati, ndati) << "." << endl << endl << endl; 
	cout << "I dati sono stati ordinati in ordine crescente e riportati nel file: "  << argv[3] << endl;
	cout << endl << endl;
	Stampa(argv[3], dati, ndati);

	delete[] dati;
  return 0;
}

double* CaricaDaFile(char* nome, int dim){
  ifstream filein;
  double* dati = new double[dim];

  filein.open(nome);
  for(int i=0; i<dim; i++){
    filein >> dati[i];
    if(filein.eof()){
      cout << "Il file in questione non contiene un numero così elevato di dati." << endl; delete[] dati;
      exit(-2);
    }
  }
  filein.close();

  return dati;
}

void Stampa(const char* nome, double* dati, int dim){
	ofstream fileout;

	fileout.open(nome);
	fileout << "Il contenuto del vettore è il seguente: " << endl;
	for(int i=0; i<dim; i++){ fileout << dati[i] << endl; }
	fileout.close();

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

//Codici di errore
//-1   errore in utilizzo del programma (dati in entrata mancanti/errati)
//-2   richiesta di un numero troppo elevato di dati