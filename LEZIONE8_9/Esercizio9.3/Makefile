LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio9.3: esercizio9.3.cpp EquazioniDifferenziali.h OperazioniVector.h FunzioneVettoriale.h
	g++ esercizio9.3.cpp -o esercizio9.3 ${INCS} ${LIBS}

clean:
	rm esercizio9.3
