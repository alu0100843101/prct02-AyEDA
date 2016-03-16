/*
 * lista_item_t.h
 *
 *  Created on: 5 de mar. de 2016
 *      Author: Andrea P�rez Quintana.
 *	 	E-mail: alu0100843101@ull.edu.es
 */

#ifndef LISTA_ITEM_T_H_
#define LISTA_ITEM_T_H_

#include "../lib/common.h"

class lista_item_t {

    public:
        lista_item_t* next_;
        lista_item_t* prev_;

    public:

        lista_item_t();
        lista_item_t(lista_item_t* prev, lista_item_t* next);
        virtual ~lista_item_t(void);

        virtual void write(std::ostream& os) {};

        virtual lista_item_t* copy(void) {return NULL;}
        virtual void clean(void) {}
    };

#endif /* LISTA_ITEM_T_H_ */
