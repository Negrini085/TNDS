LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: Grafici CalcoloIntegrali

#Programma per visualizzare i grafici
Grafici: Grafici.cpp Funzioni.h GenRandom.h IntegraliMontecarlo.h
	g++ $< -o $@ ${INCS} ${LIBS}
	
#Programma per calcolare i valori
CalcoloIntegrali: CalcoloIntegrali.cpp Funzioni.h GenRandom.h IntegraliMontecarlo.h
	g++ $< -o $@




clean:
	rm CalcoloIntegrali
	rm Grafici
	rm *dat