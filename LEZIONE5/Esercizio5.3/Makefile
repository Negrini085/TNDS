LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio5.3: esercizio5.3.o CampoVettoriale.o PuntoMateriale.o Particella.o Posizione.o 
	g++ esercizio5.3.o CampoVettoriale.o PuntoMateriale.o Particella.o Posizione.o -o esercizio5.3 ${LIBS}

esercizio5.3.o: esercizio5.3.cpp CampoVettoriale.h PuntoMateriale.h Particella.h Posizione.h
	g++ -c esercizio5.3.cpp -o esercizio5.3.o ${INCS} 

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
	rm esercizio5.3