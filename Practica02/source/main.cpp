/*
 * main.cpp
 *
 *  Created on: 7 de mar. de 2016
 *      Author: Andrea P�rez Quintana.
 *	 	E-mail: alu0100843101@ull.edu.es
 */

#include "stack_t.h"
//#include "../number_hierarchy/Complejo/complejo_t.h"
//#include "../number_hierarchy/Racional/racional_t.h"

#define MAX 10

template<class T> 
T calculadora(istream& expresion){
	
	stack_t<T> pila;
	T caracter;
	T caracter_2;
	
	while (expresion.peek()!=-1)
	{
		if (expresion.peek()>=48 && expresion.peek()<=57) //ASCII --> Si es un número.
		{
			expresion >> caracter;
			pila.push(caracter);
		}
		
		else //Sino es un caracter. 
		{
			//ASCII --> 32: espacio, 42: *, 43: +, 45: -, 47: /.
			if (expresion.peek()==32 && (expresion.peek()!=42 && expresion.peek()!=43 && expresion.peek()!=45 && expresion.peek()!=47))
				expresion.ignore();
			else
			{
				if (expresion.peek()==42)
				{
					caracter_2 = pila.pop();
					caracter = pila.pop()*caracter_2;
					pila.push(caracter);
					expresion.ignore();
				}
				if (expresion.peek()==43){
					caracter_2 = pila.pop();
					caracter = pila.pop()+caracter_2;
					pila.push(caracter);
					expresion.ignore();
				}
				if (expresion.peek()==45)
				{
					caracter_2 = pila.pop();
					caracter = pila.pop()-caracter_2;
					pila.push(caracter);
					expresion.ignore();
				}
				if (expresion.peek()==47)
				{
					caracter_2 = pila.pop();
					caracter = pila.pop()/caracter_2;
					pila.push(caracter);
					expresion.ignore();
				}
			} //else
		} //else
	} //while
	
	return pila.pop();	
}

int main(void) {
    
    int op = 1;
	stringstream s1;
	string s2;
	
//	while(op!=0)
//	{
		cout << endl;
		cout << endl;
		
		cout << "********************************************" << endl;
		cout << "** CALCULADORA EN NOTACION POLACA INVERSA **" << endl;
		cout << "********************************************" << endl;
		cout << endl;
		cout << endl;

		cout << "********************************************" << endl;
		cout << "**** Seleccione el tipo de dato a usar: ****" << endl;
		cout << "********************************************" << endl;
		cout << "**** 0. Ninguno, deseo salir. **************" << endl;
		cout << "**** 1. Entero. ****************************" << endl;
		cout << "**** 2. Real. ******************************" << endl;
		//cout << "**** 3. Racional. **************************" << endl;
		//cout << "**** 4. Complejo. **************************" << endl;
		cout << "********************************************" << endl;
		cout << endl;
		cout << ">>  ";
		cin >> op;
		cout << endl;
		cout << endl;
		
		if(op!=0)
		{
			cout << "********************************************" << endl;
			cout << "******** Introduzca una operacion: *********" << endl;
			cout << "********************************************" << endl;
			cout << endl;
			cout << ">>  ";
			cin.ignore();
			getline (cin, s2);
			cout << endl;
			cout << endl;
		}
		
		switch (op)
		{
			case 0: 
			{
				cout << "******** Espero que vuelva pronto. *********" << endl;
				op = 0;
			}
			break;
			case 1: 
			{
				s1 << s2;
				cout << "******** Solución de su operacion: *********" << endl;
				cout << "******   ";
				cout << calculadora<int>(s1);
				cout << "   ******" << endl;
				cout << "********************************************" << endl;
			}
			break;
			case 2: 
			{
				s1 << s2;
				cout << "******** Solución de su operacion: *********" << endl;
				cout << "******   ";
				cout << calculadora<float>(s1);
				cout << "   ******" << endl;
				cout << "********************************************" << endl;
			}
			break;/*
			case 3: 
			{
				s1 << s2;
				cout << "******** Solución de su operacion: *********" << endl;
				cout << "******   ";
				cout << calculadora<racional_t>(s1);
				cout << "   ******" << endl;
				cout << "********************************************" << endl;
			}
			break;
			case 4: 
			{
				s1 << s2;
				cout << "******** Solución de su operacion: *********" << endl;
				cout << "******   ";
				cout << calculadora<complejo_t>(s1);
				cout << "   ******" << endl;
				cout << "********************************************" << endl;
			}
			break;*/
			default:
				cout << "********* ERROR, OPCION NO VALIDA. *********" << endl;
			break;
			}
//	}
}
