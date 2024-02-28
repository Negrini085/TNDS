#include <vector>
#include <iostream>

#include "OperazioniVector.h"

using namespace std;

int main() {

  vector<double> v1 { 3.,4.,6.} ;
  vector<double> v2 { 4.,5.,6.} ;

  double para = 2.;

	cout << "Primo vettore: ";
	for(int i=0; i<v1.size(); i++){
   cout << v1[i] << " ";
	}
	cout << endl;

	cout << "Secondo vettore: ";
	for(int i=0; i<v2.size(); i++){
   cout << v2[i] << " ";
	}
	cout << endl;

	vector <double> v3;
	v3 = v1 + v2;
	cout << "Somma fra i due vettori: ";
	for(int i=0; i<v2.size(); i++){
   cout << v3[i] << " ";
	}
	cout << endl;

	v3 = v1 - v2;
	cout << "Differenza v1 - v2: ";
		for(int i=0; i<v2.size(); i++){
   cout << v3[i] << " ";
	}
	cout << endl;

	v3 = para * v1;
	cout << "Prodotto di v1 per il parametro " << para << ": ";
		for(int i=0; i<v2.size(); i++){
   cout << v3[i] << " ";
	}
	cout << endl;

	v3 = v2 * para;
	cout << "Prodotto di v2 per il parametro " << para << ": ";
		for(int i=0; i<v2.size(); i++){
   cout << v3[i] << " ";
	}
	cout << endl;

	v1 += v2;
	cout << "Somma (memorizzazione in v1) " << para << ": ";
	for(int i=0; i<v2.size(); i++){
   cout << v1[i] << " ";
	}
	cout << endl;

	v2 /= 2.;
	cout << "Divisione per parametro intero " << para << ": ";
	for(int i=0; i<v1.size(); i++){
   cout << v2[i] << " ";
	}
	cout << endl;

	v2 *= 2.;
	cout << "Operatore *= " << para << ": ";
	for(int i=0; i<v1.size(); i++){
   cout << v2[i] << " ";
	}
	cout << endl;


return 0;
}