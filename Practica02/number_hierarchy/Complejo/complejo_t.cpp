#include "complejo_t.h"

complejo_t::complejo_t(void):
    r_(),
    i_(),
    m_()
{}

complejo_t::complejo_t(REAL re, REAL im):
    r_(re),
    i_(im)
{
  m_ = r_*r_+i_*i_;
}

complejo_t::~complejo_t(void){}

void complejo_t::set_r(REAL r)
{
	r_=r;
}

void complejo_t::set_i(REAL i)
{
	i_=i;
}

REAL complejo_t::get_r(void) const
{
  return r_.get_numero();
}

REAL complejo_t::get_i(void) const
{
  return i_.get_numero();
}

REAL complejo_t::get_m(void) const
{
  return sqrt(r_.get_numero()*r_.get_numero()+i_.get_numero()*i_.get_numero());	
}

//Operaciones aritméticas

void complejo_t::sumar(complejo_t c1) 
{ 
	this->set_r(this->get_r()+c1.get_r());
	this->set_i(this->get_i()+c1.get_i());
}
	
void complejo_t::restar(complejo_t c1) 
{ 
	this->set_r(this->get_r()-c1.get_r());
	this->set_i(this->get_i()-c1.get_i());
}
	
void complejo_t::multiplicar(complejo_t c1) 
{ 
	this->set_r(this->get_r()*c1.get_r()- this->get_i()*c1.get_i());
	this->set_i(this->get_r()*c1.get_i()+ c1.get_r()*this->get_i());
}
	
void complejo_t::dividir(complejo_t c1) 
{ 
	this->set_r((this->get_r()*(c1.get_r()) + this->get_i()*(c1.get_i()))/(this->get_i()*this->get_i()+c1.get_i()*c1.get_i()));
	this->set_i((this->get_i()*c1.get_r()-this->get_r()*c1.get_i())/(c1.get_r()*c1.get_r()+c1.get_i()*c1.get_i()));	
}

//

//Comparaciones

bool complejo_t::menor_que(complejo_t c1) 
{ 
	return (get_m()<c1.get_m());
}
	
bool complejo_t::mayor_que(complejo_t c1) 
{ 
	return (not(get_m()<c1.get_m()));
}
	
bool complejo_t::igual_que(complejo_t c1) 
{ 
	return (r_.igual_que(c1.get_r()) && i_.igual_que(c1.get_i()));
}
	
bool complejo_t::distinto_que(complejo_t c1) 
{ 
	return (not(r_.igual_que(c1.get_r()) && i_.igual_que(c1.get_i())));
}
	
bool complejo_t::mayorigual_que(complejo_t c1) 
{ 
	return (igual_que(c1) || mayor_que(c1)); 
}
	
bool complejo_t::menorigual_que(complejo_t c1) 
{ 
	return (igual_que(c1) || menor_que(c1)); 
}	

complejo_t& complejo_t::operator=(const complejo_t& a)
{
  i_ = a.get_i();
  r_ = a.get_r();
  
  return *this;
}


ostream& complejo_t::toStream(ostream& sout) const
{
  r_.toStream(cout);
  i_.toStream(cout << "+");
  cout << "i";
  return sout;
}

istream& complejo_t::fromStream(istream& sin)
{
  string a;
  sin >> a;
  
  size_t found = a.find("+");
  
  string b,c;
  b.resize(found);
  c.resize((a.size() - found)-2);
  for(unsigned int k=0;k<found;k++) {
  
   b[k] = a[k];
  }
  for(unsigned int j=0;j<c.size();j++) {
  
    c[j] = a[j+1+found];
  }
  
  r_ = atof(b.c_str());
  i_ = atof(c.c_str());
  
  return sin;
}


//----------------------------OPERADORES SOBRECARGADOS AMIGOS----------------------------------------

//Aritméticos
complejo_t operator+(const complejo_t& a, const complejo_t& b)
{
  return complejo_t(a.get_r() + b.get_r(), a.get_i() + b.get_i());
}

complejo_t operator-(const complejo_t& a, const complejo_t& b)
{ 
  return complejo_t(a.get_r() - b.get_r(), a.get_i() - b.get_i());
}

complejo_t operator*(const complejo_t& a, const complejo_t& b)
{
  return complejo_t((a.get_r() * b.get_r()) - (a.get_i() * a.get_i()), a.get_r()*b.get_i() + a.get_i()*b.get_r());//(a + bi) * (c + di) = (ac − bd) + (ad + bc)i
}

complejo_t operator/(const complejo_t& a, const complejo_t& b)
{
  return complejo_t((a.get_r()*b.get_r() + a.get_i()*b.get_i())/(b.get_r()*b.get_r()+b.get_i()*b.get_i()), (a.get_i()*b.get_r()-a.get_r()*b.get_i())/(b.get_r()*b.get_r()+b.get_i()*b.get_i()));
}

//comparación
bool operator==(const complejo_t& a, const complejo_t& b)
{
  //return(fabs(((a.get_m()-b.get_m()).get_numero())) < EPSILON ? true:false);
}

bool operator!=(const complejo_t& a, const complejo_t& b)
{
  return(a==b ? false:true);
}

bool operator<(const complejo_t& a, const complejo_t& b)
{
  return((a.get_m()-b.get_m()) < -EPSILON ? true:false);
}

bool operator>(const complejo_t& a, const complejo_t& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const complejo_t& a, const complejo_t& b)
{
  return(a>b ? false:true);
}

bool operator>=(const complejo_t& a, const complejo_t& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const complejo_t& a)
{
  os << "[" << a.get_r() << "+" << a.get_i() << "i]";
  return os;
}

istream& operator>>(istream& is, complejo_t& a)
{
  float re, im;
  cout << "Parte real:";
  is >> re;
  
  cout << "Parte imaginaria:";
  is >> im;
  cout << endl;
  
  a = complejo_t(re, im);
  return is;
}



