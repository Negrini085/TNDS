esercizio5.1: esercizio5.1.o classi.o
	g++ esercizio5.1.o classi.o -o esercizio5.1

esercizio5.1.o: esercizio5.1.cpp classi.h
	g++ -c esercizio5.1.cpp -o esercizio5.1.o

classi.o: classi.cpp classi.h
	g++ -c classi.cpp -o classi.o

clean:
	rm *.o
	rm esercizio5.1