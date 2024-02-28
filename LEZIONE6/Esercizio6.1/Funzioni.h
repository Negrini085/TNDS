#ifndef __Funzioni_h__
#define __Funzioni_h__

#include <iostream>
#include <cmath>

using namespace std;


//Classe astratta - metodo Eval virtuale puro
class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;
  virtual ~FunzioneBase() {;};

};




//Classe parabola - eredita da classe astratta
class Parabola : public FunzioneBase {

public:

	//Costruttore di default
  Parabola () {m_a=0.; m_b=0.; m_c=0.;}
	//Costruttore che accetta in ingresso i 3 parametri
  Parabola (double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
	//Distruttore
  ~Parabola () {}

	//Metodi Set/Get per i vari parametri
	void SetA (double a) {m_a=a;}
  double GetA () const {return m_a;}
  void SetB (double b) {m_b=b;}
  double GetB () const {return m_b;}
  void SetC (double c) {m_c=c;};
  double GetC () const {return m_c;}

	//Metodo Eval
  double Eval (double x) const override {return m_a*x*x + m_b*x + m_c;}


private:
  double m_a, m_b, m_c;
};

#endif // __Funzioni_h__