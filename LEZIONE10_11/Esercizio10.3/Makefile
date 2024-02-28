LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: Grafici CalcoloIntegrali

#Programma per visualizzare i Grafici
Grafici: Grafici.cpp FunzioniScalari.h GenRandom.h MonteCarlo2D.h
		g++ Grafici.cpp -o Grafici ${INCS} ${LIBS}

#Programma per calcolare gli integrali
CalcoloIntegrali: CalcoloIntegrali.cpp FunzioniScalari.h GenRandom.h MonteCarlo2D.h
	g++ CalcoloIntegrali.cpp -o CalcoloIntegrali

clean:
	rm Grafici
	rm CalcoloIntegrali
	rm *dat