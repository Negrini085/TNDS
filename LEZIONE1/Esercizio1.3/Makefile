esercizio1.3: esercizio1.3.o funzioni.o
	g++ esercizio1.3.o funzioni.o -o esercizio1.3

esercizio1.3.o: esercizio1.3.cpp funzioni.h
	g++ -c esercizio1.3.cpp -o esercizio1.3.o

funzioni.o: funzioni.cpp funzioni.h
	g++ -c funzioni.cpp -o funzioni.o

clean:
	rm esercizio1.3
	rm *.o