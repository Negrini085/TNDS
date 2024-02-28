esercizio2.0: esercizio2.0.o Vettore.o
	g++ esercizio2.0.o Vettore.o -o esercizio2.0

esercizio2.0.o: esercizio2.0.cpp Vettore.h
	g++ -c esercizio2.0.cpp -o esercizio2.0.o

Vettore.o: Vettore.cpp Vettore.h
	g++ -c Vettore.cpp -o Vettore.o

clean:
	rm *.o
	rm esercizio2.0