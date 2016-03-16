#include "real_t.h"

class complejo_t:public numero_t {

private:
  real_t r_;
  real_t i_;
  real_t m_;//módulo
     
public:
  
  complejo_t(void);//constructor por defecto
  complejo_t(REAL re, REAL im);//constructor de asignación
 
  ~complejo_t(void);//destructor
  
  
  void set_r(REAL r);
  void set_i(REAL i);
  REAL get_r(void) const;
  REAL get_i(void) const;
  REAL get_m(void) const;
  
  // Operaciones y comparaciones
	void sumar(complejo_t c1);
	void restar(complejo_t c1);
	void multiplicar(complejo_t c1);
	void dividir(complejo_t c1);
	
	bool menor_que(complejo_t c1);
	bool mayor_que(complejo_t c1);
	bool igual_que(complejo_t c1);
	bool mayorigual_que(complejo_t c1);
	bool menorigual_que(complejo_t c1);
	bool distinto_que(complejo_t c1);
 
  virtual ostream& toStream(ostream& sout) const;  
  virtual istream& fromStream(istream& sin);
  
  //SOBRECARGA DE OPERADORES
  complejo_t& operator=(const complejo_t&);
  
  
  //aritméticos
  friend complejo_t operator+(const complejo_t&, const complejo_t&);
  friend complejo_t operator-(const complejo_t&, const complejo_t&);
  friend complejo_t operator*(const complejo_t&, const complejo_t&);
  friend complejo_t operator/(const complejo_t&, const complejo_t&);
  
  //comparación
  friend bool operator==(const complejo_t&, const complejo_t&);
  friend bool operator!=(const complejo_t&, const complejo_t&);
  friend bool operator<(const complejo_t&, const complejo_t&);
  friend bool operator>(const complejo_t&, const complejo_t&);
  friend bool operator<=(const complejo_t&, const complejo_t&);
  friend bool operator>=(const complejo_t&, const complejo_t&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const complejo_t&);
  friend istream& operator>>(istream&, const complejo_t&);
  
};