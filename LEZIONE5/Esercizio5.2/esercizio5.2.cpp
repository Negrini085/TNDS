#include <iostream>
#include <cmath>


#include "CampoVettoriale.h"
#include "PuntoMateriale.h"
#include "Particella.h"
#include "Posizione.h"

using namespace std;

int main(){
	Posizione punto(1,1,1);
	Posizione gen(0,0,0);
	PuntoMateriale Part(gen,0,-1);
	CampoVettoriale Elettrico = Part.CampoElettrico(punto);
	Elettrico.StampaCV();

	return 0;
}