LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

esercizio6.2: esercizio6.2.o Solutore.o FunzioneBase.h Bisezione.h
	g++ esercizio6.2.o Solutore.o -o esercizio6.2 ${LIBS}

esercizio6.2.o: esercizio6.2.cpp Solutore.h FunzioneBase.h Bisezione.h 
	g++ -c esercizio6.2.cpp -o esercizio6.2.o ${INCS}

Solutore.o: Solutore.cpp Solutore.h FunzioneBase.h
	g++ -c Solutore.cpp -o Solutore.o

clean:
	rm *.o
	rm esercizio6.2