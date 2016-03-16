#include "../numero_t.h"

#define EPSILON 0.000000001

typedef float REAL;

class real_t:public numero_t {

private:
  
  REAL numero;
     
public:
  
  real_t(void);//constructor por defecto
  real_t(REAL n);//constructor de asignación
  
 
  ~real_t(void);//destructor
  
  REAL get_numero(void) const;
  
  void sumar(REAL n);
	void restar(REAL n);
	void multiplicar(REAL n);
	void dividir(REAL n);
	
	bool menor_que(REAL n);
	bool mayor_que(REAL n);
	bool igual_que(REAL n);
	bool mayorigual_que(REAL n);
	bool menorigual_que(REAL n);
	bool distinto_que(REAL n);
  
  virtual ostream& toStream(ostream& sout) const;  // Escribe un Numero al flujo sout
  virtual istream& fromStream(istream& sin);// Lee un Numero desde flujo sin
  
  //SOBRECARGA DE OPERADORES
  void operator=(const real_t&);
  void operator=(const REAL);
  
  //aritméticos
  friend real_t operator+(const real_t&, const real_t&);
  friend real_t operator-(const real_t&, const real_t&);
  friend real_t operator*(const real_t&, const real_t&);
  friend real_t operator/(const real_t&, const real_t&);
  
  //comparación
  friend bool operator==(const real_t&, const real_t&);
  friend bool operator!=(const real_t&, const real_t&);
  friend bool operator<(const real_t&, const real_t&);
  friend bool operator>(const real_t&, const real_t&);
  friend bool operator<=(const real_t&, const real_t&);
  friend bool operator>=(const real_t&, const real_t&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const real_t&);
  friend istream& operator>>(istream&, const real_t&);
  
};
