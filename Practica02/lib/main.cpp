/*
 * main.cpp
 *
 *  Created on: 6 de mar. de 2016
 *      Author: Andrea P�rez Quintana.
 *	 	E-mail: alu0100843101@ull.edu.es
 */

#include "../lib/common.h"
#include "calculadora_t.h"

int main()
{
	int op = 1;
	string operacion;

	while(op!=0)
	{
		cout << "********************************************" << endl;
		cout << "** CALCULADORA EN NOTACION POLACA INVERSA **" << endl;
		cout << "********************************************" << endl;
		cout << endl;
		cout << endl;
/*
		cout << "********************************************" << endl;
		cout << "**** Seleccione el tipo de dato a usar: ****" << endl;
		cout << "********************************************" << endl;
		cout << "**** 0. Ninguno, deseo salir. **************" << endl;
		cout << "**** 1. Entero. ****************************" << endl;
		cout << "**** 2. Real. ******************************" << endl;
		cout << "**** 3. Racional. **************************" << endl;
		cout << "**** 4. Complejo. **************************" << endl;
		cout << "********************************************" << endl;
		cout << endl;
		cout << ">>  ";
		cin >> op;
		cout << endl;
		cout << endl;
*/
		cout << "¿DESEA SALIR? (0. SI, 1. NO)" << endl;
		cout << ">>  ";
		cin  >> op;
		
		if(op!=0)
				{
					cout << "********************************************" << endl;
					cout << "******** Introduzca una operacion: *********" << endl;
					cout << "********************************************" << endl;
					cout << endl;
					cout << ">>  ";
					cin.ignore();
					getline (cin,operacion);
					cout << endl;
					cout << endl;
				}

		calculadora_t<int> ();
	//	calc.calcula(operacion);
		
		/*
		switch (op)
		{
		case 0: 
		{
				cout << "Espero que vuelva pronto." << endl;
				op = 0;
		}
		break;
		case 1: 
		{
				calculadora_t<int> calc;
				calc.calcula(operacion);
		}
		break;
		case 2: 
		{
				calculadora_t<float> calc2;
				calc2.calcula(operacion);
		}
		break;
		case 3: 
				calculadora_t<racional_t> calc3;
				calc3.calcula(operacion);
				break;
		case 4: 
				calculadora_t<complejo_t> calc4;
				calc4.calcula(operacion);
				break;
		default: 
				cout << "Operacion no valida" << endl;
				break;
		}*/
	}
}

