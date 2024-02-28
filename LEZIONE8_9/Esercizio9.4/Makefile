LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio9.4: esercizio9.4.cpp FunzioniVettoriali.h EquazioniDifferenziali.h OperazioniVector.h funzioni.h
	g++ esercizio9.4.cpp -o esercizio9.4 ${INCS} ${LIBS}

clean:
	rm esercizio9.4
