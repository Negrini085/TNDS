#ifndef __FunzioneBase_h__
#define __FunzioneBase_h__

#include <iostream>
#include <cmath>

#define USE_MATH_NDEFINES

using namespace std;

class FunzioneBase {

  public:

  virtual double Eval (double) const = 0;
  virtual ~FunzioneBase() {;};

};


class Parabola : public FunzioneBase {

public:

  Parabola () {m_a=0.; m_b=0.; m_c=0.;}
  Parabola (double a, double b, double c) {m_a=a; m_b=b; m_c=c;}
  ~Parabola () {}
  double Eval (double x) const override {return m_a*x*x + m_b*x + m_c;}
  void SetA (double a) {m_a=a;}
  double GetA () const {return m_a;}
  void SetB (double b) {m_b=b;}
  double GetB () const {return m_b;}
  void SetC (double c) {m_c=c;};
  double GetC () const {return m_c;}

private:

  double m_a, m_b, m_c;

};


class Segno : public FunzioneBase{

	public:
	double Eval(double x) const override {
		if(x>0) return 1;
		else if(x<0) return -1;
		else if(x==0) return 0;
	 };
	~Segno () {};
	

};

#endif //__FunzioneBase_h__
