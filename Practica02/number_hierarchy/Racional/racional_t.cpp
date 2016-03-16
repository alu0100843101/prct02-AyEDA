#include "racional_t.h"

racional_t::racional_t(ENTERO num, ENTERO den)
	{
		try
		{
			if(den == 0)
			{
				throw("Error. El denominador es 0.");
			}
			ENTERO aux = racional_t::mcd(num,den);
			numerador.modificar(num/aux);
			denominador.modificar(den/aux);
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			exit(1);
		}
	}


racional_t::~racional_t(void){}


ENTERO racional_t::mcd(ENTERO e1, ENTERO e2)
{
    if(e1==0) 
    	return e2;
	
	return mcd(e2%e1, e1);
}
	
ENTERO racional_t::mcm(ENTERO e1, ENTERO e2)
{
	return (e1/racional_t::mcd(e1, e2))*e2;
}

ENTERO racional_t::get_numerador(void) const
{
  return numerador.get_numero();
}

ENTERO racional_t::get_denominador(void) const
{
  return denominador.get_numero();
}

void racional_t::set_numerador(const ENTERO num) 
	{ 
		this->numerador=num;
	}
	
void racional_t::set_denominador(const ENTERO den) 
{ 
		try
		{
			if(den == 0)
			{
				throw("Error. El denominador indicado es 0.");
			}
			this->denominador=den;
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			this->denominador=this->get_denominador();
		}
}

void racional_t::modificar(const ENTERO num, const ENTERO den) 
	{ 
		try
		{
			if(den == 0)
			{
				throw("Error. El denominador indicado es 0.");
			}
			this->set_numerador(num);
			this->set_denominador(den);
		}
		catch(const char* msg)
		{
			cerr << msg << endl;
			this->set_numerador(this->get_numerador());
			this->set_denominador(this->get_denominador());
		}
}

void racional_t::sumar(racional_t rac) 
{ 
	ENTERO aux1 = mcm(this->get_denominador(), rac.get_denominador());		
	this->modificar((aux1/this->get_denominador())*this->get_numerador()+((aux1/rac.get_denominador())*rac.get_numerador()),aux1);				 
}
	
void racional_t::restar(racional_t rac) 
{ 
	ENTERO aux1 = racional_t::mcm(this->get_denominador(), rac.get_denominador());		
	this->modificar(((aux1/rac.get_denominador())*rac.get_numerador())-(aux1/this->get_denominador())*this->get_numerador(),aux1);	
}
	
void racional_t::multiplicar(racional_t rac) 
{ 
	this->set_numerador(this->get_numerador()*rac.get_numerador());
	this->set_denominador(this->get_denominador()*rac.get_denominador());
}
	
void racional_t::dividir(racional_t rac) 
{ 
	this->set_numerador(this->get_numerador()*rac.get_denominador());
	this->set_denominador(this->get_denominador()*rac.get_numerador());
}
	
//Comparaciones
	
bool racional_t::menor_que(racional_t rac) 
{ 
	return (this->get_denominador()>rac.get_denominador() || (this->get_denominador()==rac.get_denominador() && this->get_numerador()<rac.get_numerador()));
}
	
bool racional_t::mayor_que(racional_t rac) 
{ 
	return (not(menor_que(rac)));
}
	
bool racional_t::igual_que(racional_t rac) 
{ 
	return (this->get_denominador()==rac.get_denominador() && this->get_numerador()==rac.get_numerador());
}
	
bool racional_t::distinto_que(racional_t rac) 
{ 
	return (not(igual_que(rac)));
}
	
bool racional_t::mayorigual_que(racional_t rac) 
{ 
	return (igual_que(rac) || mayor_que(rac)); 
}
	
bool racional_t::menorigual_que(racional_t rac) 
{ 
	return (igual_que(rac) || menor_que(rac)); 
}

racional_t& racional_t::operator=(const racional_t& a)
{
	 this->set_numerador(a.get_numerador());
		this->set_denominador(a.get_denominador());
}

ostream& racional_t::toStream(ostream& sout) const
{
  	if(get_denominador() != 1)
		{
			sout << get_numerador() << "/" << get_denominador();		
		}
		else
		{
			sout << get_numerador();				
		}
		return sout;
}

istream& racional_t::fromStream(istream& sin)
{
 
		ENTERO aux1, aux2;
		cout << " NUMERADOR:" << endl << endl;	
		sin >> aux1;	
		cout << " DENOMINADOR:" << endl << endl;	
		sin >> aux2;
		this->modificar(aux1, aux2);	
		return sin;

}

//*************************SOBRECARGA DE OPERADORES "AMIGOS*******************************
//Aritméticos
racional_t operator+(const racional_t& a, const racional_t& b)
{  
  return racional_t(a.get_numerador()*b.get_denominador() + b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

racional_t operator-(const racional_t& a, const racional_t& b)
{ 
  return racional_t(a.get_numerador()*b.get_denominador() - b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

racional_t operator*(const racional_t& a, const racional_t& b)
{ 
  return racional_t(a.get_numerador()*b.get_numerador(),a.get_denominador()*b.get_denominador());
}

racional_t operator/(const racional_t& a, const racional_t& b)
{
 
  return racional_t(a.get_numerador()*b.get_denominador(),a.get_denominador()*b.get_numerador());
}

//comparación
bool operator==(const racional_t& a, const racional_t& b)
{
  if((a.get_numerador()==b.get_numerador())&&(a.get_denominador()==b.get_denominador())) {
    return true;
  } else {
    return false;
  }
}

bool operator!=(const racional_t& a, const racional_t& b)
{
  return(a==b ? false:true);
}

bool operator<(const racional_t& a, const racional_t& b)
{
  if(a.get_numerador()==b.get_denominador())
  {
    return(a.get_denominador()<b.get_denominador() ? false:true);
    
  } else {
    
      if((a.get_numerador()*b.get_denominador())<(b.get_numerador()*a.get_denominador())) {
	return true;
      } else {
	return false;
      }
  }
  
}

bool operator>(const racional_t& a, const racional_t& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const racional_t& a, const racional_t& b)
{
  return(a>b ? false:true);
}

bool operator>=(const racional_t& a, const racional_t& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const racional_t& a)
{
 		a.toStream(os);
 		return os;
}

istream& operator>>(istream& is, racional_t& a)
{
  a.fromStream(is);
  return is;
}