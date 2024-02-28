LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio9.2: esercizio9.2.cpp EquazioniDifferenziali.h FunzioniVettoriali.h OperazioniVector.h funzioni.h
	g++ esercizio9.2.cpp -o esercizio9.2 ${INCS} ${LIBS}

clean: 
	rm esercizio9.2 