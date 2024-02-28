#ifndef __Vettore_h__
#define __Vettore_h__

#include <iostream>
#define NDEBUG
#include <assert.h>

using namespace std;

template <typename T> class Vettore {
                          
 public:
		//Costruttore di default (nessun argomento)
		Vettore(){
			m_N = 0;
			m_v = nullptr;
		}
		//Costruttore  - fornita dim desiderata
		Vettore(unsigned int dim){
			m_N = dim;
			m_v = new T[dim];
		}
		//Distruttore
		~Vettore(){ delete[] m_v; }

		//Metodo che restitusce la dimensione del Vettore
		unsigned int GetN() const{	return m_N; }

		//Metodo GetComponent
		T GetComponent(unsigned int ind) const{
			assert((m_N > ind) && "Errore: indice inserito troppo grande!!");
			if(m_N > ind){ return m_v[ind]; }
			else{
				cout << "L'indice inserito è troppo grande: esco!!" << endl;
				exit(-2);
			}	
		}
		//Metodo SetComponent
		void SetComponent(unsigned int ind, T DaInserire){
			assert((m_N > ind) && "Errore: indice inserito troppo grande");
			if(m_N > ind){ m_v[ind] = DaInserire; }
			else{
				cout << "L'indice inserito è troppo grande: esco!!" << endl;
				exit(-2);
			}
		}


		//Copy constructor
		Vettore(const Vettore& V){
			m_N = V.GetN();
			m_v = new T[m_N];
			for(int i=0; i<m_N; i++){ m_v[i] = V.GetComponent(i); }
		}
		//Operatore di assegnazione
		Vettore& operator=(const Vettore& DaCopiare){
			m_N = DaCopiare.GetN();
			if(m_v){ delete[] m_v; }
			m_v = new T[m_N];
			for(int i=0; i<m_N; i++){ m_v[i] = DaCopiare.GetComponent(i); }
		return *this;
		}
		//Overloading operatore[]
		T& operator[](unsigned int ind){
			assert((m_N >ind) && "Errore: indice inserito troppo grande.");
			if(m_N>ind){ return m_v[ind]; }
			else{
				cout << "L'indice inserito è troppo grande: esco!!" << endl;
				exit(-2);
			}
			
		}
		//Metodo che scambia contenuti del Vettore
		void Scambia(unsigned int primo, unsigned int secondo){
			assert(((m_N>primo)&&(m_N>secondo)) && "Errore: almeno uno degli indici inseriti è troppo grande!!");
			T appo;
			if((m_N>primo) && (m_N>secondo)){
				appo = GetComponent(primo);
				SetComponent(primo, GetComponent(secondo));
				SetComponent(secondo, appo);
			}
			else{
				cout << "Almeno uno dei due indici è troppo grande: esco!!" << endl;
				exit(-2);
			}
		}

 private:
  
   unsigned int m_N;                        
   T* m_v;     
  
};

#endif // __Vettore_h__

