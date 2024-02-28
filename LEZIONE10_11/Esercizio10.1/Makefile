LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio10.1: esercizio10.1.cpp GenRandom.h Grafici.h
	g++ esercizio10.1.cpp -o esercizio10.1 ${INCS} ${LIBS}

clean:
	rm esercizio10.1