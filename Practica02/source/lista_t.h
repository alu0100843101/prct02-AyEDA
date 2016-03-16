/*
 * lista_t.h
 *
 *  Created on: 5 de mar. de 2016
 *      Author: Andrea PÈrez Quintana.
 *	 	E-mail: alu0100843101@ull.edu.es
 */

#ifndef LISTA_T_H_
#define LISTA_T_H_

#include "lista_item_t.h"

class lista_t
{
    private:

        lista_item_t* inicio_;
        lista_item_t* fin_;

        int size_;

    public:

        lista_t(void);
        lista_t(const lista_t& lista);
        ~lista_t(void);

        int get_size(void);
        void clear(void); // Borra el s√≥lo el nodo y no borra el dato
        void clean(void); // Borra el nodo y el dato
        bool empty(void);

        void push_back(lista_item_t* nodo);
        lista_item_t* pop_back(void);
        lista_item_t* pop_front(void);

        void write(ostream& os);

};

#endif /* LISTA_T_H_ */
