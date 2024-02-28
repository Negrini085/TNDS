#include "classi.h"

#include <iostream> 
#include <cmath>

using namespace std;

int main() {

  Particella *a   = new Particella(1.,1.6E-19);
  Elettrone *e    = new Elettrone();
  
  // Metodi della classe base
  cout << "Particella " << a->GetMassa() << "," << a->GetCarica() << endl;
  a->StampaMC(); 

  // Metodi della classe derivata
  cout << "Elettrone " << e->GetMassa() << "," << e->GetCarica() << endl;
  e->StampaE(); 

  Particella b(*a) ;  // costruisco una Particella a partire da una Particella
  Particella d(*e);   // costruisco una Particella a partire da un Elettrone
  //Elettrone f(d);    // costruisco un Elettrone a partire da una Particella 

  return 0;

}


