#include "complejo_t.h"

//int main(int argc, char **argv)
int main(void)
{
	complejo_t a(1,2),b(2,3),c(3,4),d(5,6); 

	/*Mostrar Complejos*/
	cout << endl;
	a.toStream(cout);
	cout << endl;
	b.toStream(cout);
	cout << endl;
	c.toStream(cout);
	cout << endl;
	d.toStream(cout);
	cout << endl << endl;

	cout << "Parte real      : "<< a.get_r()<< std::endl;
	cout << "Parte imaginaria: "<< a.get_i()<< std::endl;
	cout << "Módulo          : "<< a.get_m()<< std::endl;
	cout << endl << endl;

	// Modificar valores
	cout << "Modificar número: ";
	a.toStream(cout); 
	a.set_r(5);
	cout << " a ";
	a.toStream(cout); 
	cout << endl << endl;

	//Suma
	cout << "Suma            : "; 
	c.toStream(cout); 
	cout << " + ";
	a.toStream(cout); 
	cout << " = ";
	c.sumar(a);
	c.toStream(cout);
	cout << endl << endl;

	//Producto
	cout << "Multiplicación  : "; 
	d.toStream(cout); 
	cout << " * ";
	a.toStream(cout); 
	cout << " = ";
	d.multiplicar(a);
	d.toStream(cout);
	cout << endl << endl;
	
	//División
	cout << "División	: "; 
	b.toStream(cout); 
	cout << " / ";
	a.toStream(cout); 
	cout << " = ";
	b.dividir(a);
	b.toStream(cout);
	cout << endl << endl;
	
	//sobrecarga suma
	complejo_t x;
	complejo_t y(1,2);
	complejo_t z(3,4);
	
	x = y + z;
	
	//sobrecarga de la salida
	cout << "Número complejo 'x': " << x << endl << endl;

}
