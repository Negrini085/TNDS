esercizio1.2: esercizio1.2.o funzioni.o
	g++ esercizio1.2.o funzioni.o -o esercizio1.2

esercizio1.2.o: esercizio1.2.cpp funzioni.h
	g++ -c esercizio1.2.cpp -o esercizio1.2.o

funzioni.o: funzioni.cpp funzioni.h
	g++ -c funzioni.cpp -o funzioni.o

clean:
	rm esercizio1.2
	rm *.o