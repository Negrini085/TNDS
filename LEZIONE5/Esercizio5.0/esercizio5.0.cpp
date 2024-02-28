#include "posizione.h"

#include <iostream>
#include <cstdlib>

using namespace std;

//Input sono le coordinate cartesiane di un punto nello spazio

int main(int argc, char** argv) {

  // Controlla gli argomenti
  if ( argc!=4 ) {
    cout << "Utilizzo: " << argv[0] << " <x> <y> <z>" << endl;
    return -1;
  }

  double x = atof(argv[1]);
  double y = atof(argv[2]);
  double z = atof(argv[3]);

  // Crea un oggetto posizione ed accede ai vari metodi

  Posizione P(x,y,z);

  cout << "Coordinate cartesiane: " 
       << P.GetX() << ", " << P.GetY() << ", " << P.GetZ() << endl;
  cout << "Coordinate cilindriche: " 
       << P.GetRho() << ", " << P.GetPhi() << ", " << P.GetZ() << endl;
  cout << "Coordinate sferiche: " 
       << P.GetR() << ", " << P.GetPhi() << ", " << P.GetTheta() << endl;

  return 0;
}