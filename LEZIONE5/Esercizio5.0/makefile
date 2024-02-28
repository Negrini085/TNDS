esercizio5.0: esercizio5.0.o posizione.o posizione.h
	g++ esercizio5.0.o posizione.o -o esercizio5.0

esercizio5.0.o: esercizio5.0.cpp posizione.h
	g++ -c esercizio5.0.cpp -o esercizio5.0.o

posizione.o: posizione.cpp posizione.h
	g++ -c posizione.cpp -o posizione.o

clean:
	rm *.o
	rm esercizio5.0
