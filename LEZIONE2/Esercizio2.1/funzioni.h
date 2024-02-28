#ifndef __funzioni__
#define __funzioni__

#include <iostream>
#include <fstream> 
#include "Vettore.h"

using namespace std;

Vettore Read(char*, int);
void Stampa(char*, Vettore&);
void Stampa(Vettore&);
double CalcoloMedia(Vettore&);
double CalcoloVarianza(Vettore&);
double CalcoloMediana(Vettore);
void selection_sort(Vettore&);

#endif
