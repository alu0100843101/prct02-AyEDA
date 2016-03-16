#include "racional_t.h"

int main(void)
{

    racional_t numero2(78, 156);

	racional_t numero3(124, 254);
	cout << numero3 << " - " << numero2 << " = ";
	numero3 = numero3 - numero2;
	numero3.toStream(cout);
	cout << endl << endl;
	
	cout << numero2 << " * " << numero3 << " = ";
	numero2 = numero2 * numero3;
	numero2.toStream(cout);	
		cout << endl << endl;
	

}