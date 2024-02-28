LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

compila: Simulazione Grafici

#Programma per generare pseudo-misure
Simulazione: Simulazione.cpp funzioni.h GenRandom.h prisma.h
	g++  Simulazione.cpp -o Simulazione

#Programma per grafici - analisi dati
Grafici: Grafici.cpp prisma.h GenRandom.h funzioni.h
	g++ Grafici.cpp -o Grafici ${INCS} ${LIBS}

clean:
	rm Simulazione
	rm Grafici
	rm *.dat