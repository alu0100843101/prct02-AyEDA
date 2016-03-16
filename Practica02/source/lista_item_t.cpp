/*
 * lista_item_t.cpp
 *
 *  Created on: 5 de mar. de 2016
 *      Author: Andrea Pérez Quintana.
 *	 	E-mail: alu0100843101@ull.edu.es
 */

#include "lista_item_t.h"

lista_item_t::lista_item_t():
    next_(NULL),
    prev_(NULL)
{}

lista_item_t::lista_item_t(lista_item_t* prev, lista_item_t* next):
    next_(next),
    prev_(prev)
{}

lista_item_t::~lista_item_t(void)
{
    prev_ = NULL;
    next_ = NULL;
}
