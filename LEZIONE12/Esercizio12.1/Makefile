LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio12.0: esercizio12.1.cpp Viscosità.h GenRandom.h Grafici.h
	g++ esercizio12.1.cpp -o esercizio12.1 ${INCS} ${LIBS}

clean:
	rm esercizio12.1