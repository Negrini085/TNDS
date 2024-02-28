esercizio2.1: esercizio2.1.o funzioni.o Vettore.o
	g++ esercizio2.1.o funzioni.o Vettore.o -o esercizio2.1

esercizio2.1.o: esercizio2.1.cpp funzioni.h Vettore.h
	g++ -c esercizio2.1.cpp -o esercizio2.1.o

funzioni.o: funzioni.cpp funzioni.h Vettore.h
	g++ -c funzioni.cpp -o funzioni.o

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

clean:
	rm *.o
	rm esercizio2.1