#include "real_t.h"

real_t::real_t(void):
    numero(0)
{}

real_t::real_t(REAL n):
    numero(n)
{}


real_t::~real_t(void){}

REAL real_t::get_numero(void) const
{
  return numero;
}

void real_t::sumar(const REAL n) 
	{ 
		numero=numero+n; 
	}
	
	void real_t::restar(const REAL n) 
	{ 
		numero=numero-n; 
	}
	
	void real_t::multiplicar(const REAL n) 
	{ 
		numero=(numero*n); 
	}
	
	void real_t::dividir(const REAL n) 
	{ 
		try
		{
			if(n == 0)
			{
				throw("Error en la división, división entre 0: se cancela la división");
			}
			numero=(numero/n); 
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			numero=numero;
		}
	}
	
	//Comparaciones (se usa una precisión Épsilon de 1E-4)
	
	bool real_t::menor_que(const REAL n) 
	{ 
		return (numero<(n-1E-4));
	}
	
	bool real_t::mayor_que(const REAL n) 
	{ 
		return (not(numero<(n-1E-4)));
	}
	
	bool real_t::igual_que(const REAL n) 
	{ 
		return (fabs(numero-n)<1E-4);
	}
	
	bool real_t::distinto_que(const REAL n) 
	{ 
		return (not(fabs(numero-n)<1E-4));
	}
	
	bool real_t::mayorigual_que(const REAL n) 
	{ 
		return (igual_que(n) || mayor_que(n)); 
	}
	
	bool real_t::menorigual_que(const REAL n) 
	{ 
		return (igual_que(n) || menor_que(n)); 
	}

void real_t::operator=(const real_t& a)
{
    this->numero = a.get_numero();
}

void real_t::operator=(const REAL n)
{
  this->numero = n;
}

ostream& real_t::toStream(ostream& sout) const
{
  sout << numero;
  
  return sout;
}

istream& real_t::fromStream(istream& sin)
{
  sin >> numero;
  
  return sin;
}

//*************************SOBRECARGA DE OPERADORES "AMIGOS*******************************
//Aritméticos
real_t operator+(const real_t& a, const real_t& b)
{
  return real_t(a.get_numero() + b.get_numero());
}

real_t operator-(const real_t& a, const real_t& b)
{ 
      return real_t(a.get_numero() - b.get_numero());
}

real_t operator*(const real_t& a, const real_t& b)
{
  return real_t(a.get_numero() * b.get_numero());
}

real_t operator/(const real_t& a, const real_t& b)
{
  try {
    if(!b.get_numero()) throw 1;
    
    return real_t(a.get_numero()/b.get_numero());
    } 
  catch(int a)
  {
    cout << "***ERROR*** [División por cero]\nEl resultado se igualará a 0 pero correctamente tiende a infinito." << endl;
    return 000;
  }
}

//comparación
bool operator==(const real_t& a, const real_t& b)
{
  return(fabs(a.get_numero()-b.get_numero()) < EPSILON ? true:false);
}

bool operator!=(const real_t& a, const real_t& b)
{
  return(a==b ? false:true);
}

bool operator<(const real_t& a, const real_t& b)
{
  return((a.get_numero()-b.get_numero()) < -EPSILON ? true:false);
}

bool operator>(const real_t& a, const real_t& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const real_t& a, const real_t& b)
{
  return(a>b ? false:true);
}

bool operator>=(const real_t& a, const real_t& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const real_t& a)
{
  os << a.get_numero();
  return os;
}

istream& operator>>(istream& is, real_t& a)
{
  float n;
  is >> n;
  a = real_t(n);
  return is;
}