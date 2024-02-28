#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char** argv){
  ifstream filein; ofstream fileout;
  double appo=0; double media=0; double stddev=0;
  int ndat; int ind;

  if(argc<4){
    cout<<"Uso del programma:" << argv[0] << " <n_data> <filename input> <filename output>" << endl;
    return -1;
  }
  ndat = atoi(argv[1]);
  double* data = new double[ndat];

  filein.open(argv[2]);
  if(!filein){
    cout << "File non trovato!... esco!" << endl; return -2;
  }

	//Riempio l'array di dati
  for(int i=0; i<ndat; i++){
    filein >> data[i];
    if(filein.eof()){
      cout << "Il file contiene meno dati di quelli richiesti." << endl; delete[] data;
      return -3;
    }
  }
  cout << endl << "Dati caricati." << endl; filein.close();

  for(int i=0; i<ndat; i++){ appo = appo + data[i]; }
  media = appo/ndat;
  for(int i=0; i<ndat; i++){
    appo = data[i] - media; stddev = stddev + pow(appo, 2);
  }
  stddev = stddev/(ndat-1);
  cout << "Media dei dati selezionati: " << media << "." << endl;
  cout << "Varianza dei dati selezionati: " << stddev << "." << endl << endl;

  double* copy = new double[ndat];
  for(int i=0; i<ndat; i++){ copy[i] = data[i]; }
  for(int i=0; i<ndat; i++){
    appo=copy[i];
    ind = i;
    for(int k=i; k<ndat; k++){
      if(copy[k]<appo){
        appo = copy[k];
        ind = k;
      }
    }
    copy[ind] = copy[i];
    copy[i] = appo;
  }
  cout << "Vettore riordinato!!" << endl;
  if(ndat%2==0){
    cout << "Mediana dei dati selezionati: " << (copy[ndat/2-1]+copy[ndat/2])/2 << "." << endl;
  }
  else{
    cout << "Mediana dei dati selezionati: " << copy[(ndat-1)/2] << "." << endl;
  }

  cout << "I dati riordinati verranno stampati su: " << argv[3] << endl;

  fileout.open(argv[3]);
  fileout << "I dati riorganizzati sono:" << endl;
  for(int i=0; i<ndat; i++){ fileout << copy[i] << endl;}
  fileout.close();

  delete[] data;
  delete[] copy;
  return 0;
}