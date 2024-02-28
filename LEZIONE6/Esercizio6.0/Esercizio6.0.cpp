#include "Particella.h"

#include <iostream>
#include <cmath>

using namespace std;

int main (){

  Particella *a = new Particella(1.,2.);
  Elettrone  *e = new Elettrone();
  Particella *b = new Elettrone(); // puntatore a Particella punta a un Elettrone

  a->Stampa(); // Meteodo Print di Particella
  e->Stampa(); // Meteodo Print di Elettrone
  b->Stampa(); // ???

  delete a;
  delete e;
  delete b;

  return 0;
}