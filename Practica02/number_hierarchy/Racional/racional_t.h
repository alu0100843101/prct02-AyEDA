#include "entero_t.h"

class racional_t:public numero_t {

private:
  entero_t numerador;
  entero_t denominador;
 
public:
  
   racional_t(ENTERO num, ENTERO den);//constructor de asignación
 
  ~racional_t(void);//destructor
  
  ENTERO get_numerador(void) const;
  ENTERO get_denominador(void) const;
  void set_numerador(ENTERO num);
  void set_denominador(ENTERO num);
  
  
  ENTERO mcd(ENTERO e1, ENTERO e2);
  ENTERO mcm(ENTERO e1, ENTERO e2);
  void modificar(ENTERO num, ENTERO den);
 
  
   void sumar(racional_t rac);
	void restar(racional_t rac);
	void multiplicar(racional_t rac);
	void dividir(racional_t rac);
	
	bool menor_que(racional_t rac);
	bool mayor_que(racional_t rac);
	bool igual_que(racional_t rac);
	bool mayorigual_que(racional_t rac);
	bool menorigual_que(racional_t rac);
	bool distinto_que(racional_t rac);
  
  //HERENCIA DE LA CLASE numero
  virtual ostream& toStream(ostream& sout) const;  
  virtual istream& fromStream(istream& sin);
  
  //SOBRECARGA DE OPERADORES
  racional_t& operator=(const racional_t&);
 
  
  //aritméticos
  friend racional_t operator+(const racional_t&, const racional_t&);
  friend racional_t operator-(const racional_t&, const racional_t&);
  friend racional_t operator*(const racional_t&, const racional_t&);
  friend racional_t operator/(const racional_t&, const racional_t&);
  
  //comparación
  friend bool operator==(const racional_t&, const racional_t&);
  friend bool operator!=(const racional_t&, const racional_t&);
  friend bool operator<(const racional_t&, const racional_t&);
  friend bool operator>(const racional_t&, const racional_t&);
  friend bool operator<=(const racional_t&, const racional_t&);
  friend bool operator>=(const racional_t&, const racional_t&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const racional_t&);
  friend istream& operator>>(istream&, const racional_t&);
  
};