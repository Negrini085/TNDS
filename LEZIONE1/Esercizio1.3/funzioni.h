#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double* CaricaDaFile(char*, int);
void Stampa(char*, double*, int);
void Stampa(double*, int);
double CalcoloMedia(double*, int);
double CalcoloVarianza(double*, int);
double CalcoloMediana(double*, int);
void selection_sort(double*, int);
double* Copia(double*, int);