/*
 * stack_t.h
 *
 *  Created on: 5 de mar. de 2016
 *      Author: Andrea Pérez Quintana.
 *	 	E-mail: alu0100843101@ull.edu.es
 */

#ifndef STACK_T_H_
#define STACK_T_H_

#include "lista_t.h"

template <class TDATO>
class stack_item_t: public lista_item_t {

	private:
		TDATO dato_;

	public:
		stack_item_t(TDATO dato):
		    lista_item_t(),
		    dato_(dato)
		{}

		TDATO get_dato(void)
		{
		    return dato_;
		}

		virtual ~stack_item_t(void)
		{}
	};


template <class TDATO>
class stack_t: public lista_t
{
    public:

        stack_t(void):
            lista_t ()
            {}

        virtual ~stack_t(void)
        {}

        bool empty(void)
        {
            return (lista_t::empty());
        }

        void push(TDATO dato)
        {
            push_back(new stack_item_t<TDATO>(dato));
        }

        TDATO pop(void)
        {
            stack_item_t<TDATO>* aux = (stack_item_t<TDATO>*)(pop_back());

            TDATO dat = aux->get_dato();
			delete aux;

			return dat;
        }
};

#endif /* STACK_T_H_ */
