LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio9.1: esercizio9.1.cpp FunzioniVettoriali.h EquazioniDifferenziali.h OperazioniVector.h
	g++ esercizio9.1.cpp -o esercizio9.1 ${INCS} ${LIBS}

clean:
	rm esercizio9.1