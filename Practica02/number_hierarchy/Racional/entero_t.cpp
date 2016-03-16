#include "entero_t.h"

entero_t::entero_t(void):	
    numero(0)
{}

entero_t::entero_t(ENTERO n):
    numero(n)
{}


entero_t::~entero_t(void){}			

int entero_t::get_numero(void) const
{
  return numero;
}

void entero_t::modificar(const ENTERO n) 
{
  numero = n;
}

void entero_t::operator=(entero_t a)
{
  this->numero = a.get_numero();
}

void entero_t::operator=(ENTERO n)
{
  this->numero = n;
}

ostream& entero_t::toStream(ostream& sout) const
{
  sout << numero;
  
  return sout;
}

istream& entero_t::fromStream(istream& sin)
{
    	
		cout << "NÚMERO ENTERO:" << endl << endl;	
		sin >> numero;	
	
		return sin;
}


void entero_t::sumar(const ENTERO n) 
{ 
		numero=numero+n; 
}
	
void entero_t::restar(const ENTERO n) 
{ 
	numero=numero-n; 
}
	
void entero_t::multiplicar(const ENTERO n) 
{ 
	numero=(numero*n); 
}
	
void entero_t::dividir(const ENTERO n) 
{ 
	try
	{
	    if(n == 0)
		{
			throw("Error en la división, división entre 0: se cancela la división");
		}
			numero=(numero/n); 
	}catch(const char* msg){
		cerr << msg << endl;
		numero=numero;
	}
}

bool entero_t::menor_que(const ENTERO n) 
{ 
    return (numero<n);
}
	
bool entero_t::mayor_que(const ENTERO n) 
{ 
    return (numero>n);
}
	
bool entero_t::igual_que(const ENTERO n) 
{ 
    return (numero==n);
}
	
bool entero_t::distinto_que(const ENTERO n) 
{ 
    return (numero!=n);
}

bool entero_t::mayorigual_que(const ENTERO n) 
{ 
    return (igual_que(n) || mayor_que(n)); 
}
	
bool entero_t::menorigual_que(const ENTERO n) 
{ 
    return (igual_que(n) || menor_que(n)); 
}


//******************************SOBRECARGA DE OPERADORES "AMIGOS"***********************************************
//Aritméticos

entero_t operator+(const entero_t& a, const entero_t& b)
{
  return entero_t(a.get_numero() + b.get_numero());
}

entero_t operator-(const entero_t& a, const entero_t& b)
{
      return entero_t(a.get_numero() - b.get_numero());
}

entero_t operator*(const entero_t& a, const entero_t& b)
{
  return entero_t(a.get_numero() * b.get_numero());
}

entero_t operator/(const entero_t& a, const entero_t& b)
{
  try {
    if(!b.get_numero()) throw b;
    
    return entero_t(a.get_numero()/b.get_numero());
    } 
  catch(...)
  {
    cout << "***ERROR*** [División por cero]\nEl resultado se igualará a 0 pero correctamente tiende a infinito." << endl;
    return 000;
  }
}

//comparación
bool operator==(const entero_t& a, const entero_t& b)
{
  return(a.get_numero()==b.get_numero() ? true:false);
}

bool operator!=(const entero_t& a, const entero_t& b)
{
  return(a==b ? false:true);
}

bool operator<(const entero_t& a, const entero_t& b)
{
  return(a.get_numero()<b.get_numero() ? true:false);
}

bool operator>(const entero_t& a, const entero_t& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const entero_t& a, const entero_t& b)
{
  return(a>b ? false:true);
}

bool operator>=(const entero_t& a, const entero_t& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const entero_t& a)
{
  os << a.get_numero();
  return os;
}

istream& operator>>(istream& is, entero_t& a)
{
  int n;
  is >> n;
  a = entero_t(n);
  return is;
}
