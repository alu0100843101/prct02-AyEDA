#include "../numero_t.h"

typedef int ENTERO;

class entero_t:public numero_t {

private:
  
  ENTERO numero;
     
public:
  
  entero_t(void);//constructor por defecto
  entero_t(ENTERO n);//constructor de asignación
 
  ~entero_t(void);//destructor
  
  ENTERO get_numero(void) const;
  void modificar(ENTERO n);
  
  //Funciones virtuales heredadas de numero_t
  virtual ostream& toStream(ostream& sout) const; 
  virtual istream& fromStream(istream& sin);
  
  
    void sumar(ENTERO n);
	void restar(ENTERO n);
	void multiplicar(ENTERO n);
	void dividir(ENTERO n);
	
	bool menor_que(ENTERO n);
	bool mayor_que(ENTERO n);
	bool igual_que(ENTERO n);
	bool mayorigual_que(ENTERO n);
	bool menorigual_que(ENTERO n);
	bool distinto_que(ENTERO n);
  
  //SOBRECARGA DE OPERADORES
  void operator=(entero_t); //Sobrecarga del operador '=' para asignar valor al nº natural
  void operator=(ENTERO);   //Sobrecarga del operador '=' para asignar valor al nº natural
  
  //ARITMÉTICOS
  friend entero_t operator+(const entero_t&, const entero_t&);
  friend entero_t operator-(const entero_t&, const entero_t&);
  friend entero_t operator*(const entero_t&, const entero_t&);
  friend entero_t operator/(const entero_t&, const entero_t&);
  
  //COMPARACIÓN
  friend bool operator==(const entero_t&, const entero_t&);
  friend bool operator!=(const entero_t&, const entero_t&);
  friend bool operator<(const entero_t&, const entero_t&);
  friend bool operator>(const entero_t&, const entero_t&);
  friend bool operator<=(const entero_t&, const entero_t&);
  friend bool operator>=(const entero_t&, const entero_t&);
  
  //E/S
  friend ostream& operator<<(ostream&, const entero_t&);
  friend istream& operator>>(istream&, const entero_t&);
  
};