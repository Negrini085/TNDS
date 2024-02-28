esercizio5.2: esercizio5.2.o CampoVettoriale.o PuntoMateriale.o Particella.o  Posizione.o
	g++ esercizio5.2.o CampoVettoriale.o PuntoMateriale.o Particella.o Posizione.o -o esercizio5.2

CampoVettoriale.o: CampoVettoriale.cpp CampoVettoriale.h Posizione.h
	g++ -c CampoVettoriale.cpp -o CampoVettoriale.o

PuntoMateriale.o: PuntoMateriale.cpp PuntoMateriale.h Particella.h Posizione.h
	g++ -c PuntoMateriale.cpp -o PuntoMateriale.o

Particella.o: Particella.cpp Particella.h 
	g++ -c Particella.cpp -o Particella.o

Posizione.o: Posizione.cpp Posizione.h
	g++ -c Posizione.cpp -o Posizione.o


clean:
	rm *.o
	rm esercizio5.2