/*
 * lista_t.cpp
 *
 *  Created on: 5 de mar. de 2016
 *      Author: Andrea Pérez Quintana.
 *	 	E-mail: alu0100843101@ull.edu.es
 */

#include "lista_t.h"

lista_t::lista_t(void):
 	inicio_(NULL),
    fin_(NULL),
    size_(0)
{}

lista_t::lista_t(const lista_t& lista):
	inicio_(NULL),
    fin_(NULL),
    size_(0)
{}

lista_t::~lista_t(void)
{
	clear();

}

int lista_t::get_size(void)
{
	return size_;
}

void lista_t::clear(void)
{
	lista_item_t* aux = NULL;

	while (inicio_ != NULL)
	{
		aux = inicio_;
		inicio_ = inicio_->next_;

		if (aux)
		{
			aux->clean();
			delete aux;

		}
	}

	size_ = 0;
	inicio_ = NULL;
	fin_ = NULL;
}

void lista_t::clean(void) {

        lista_item_t* aux = NULL;

        while (inicio_ != NULL) {

            aux = inicio_;
            inicio_ = inicio_->next_;

			if (aux){
				aux->clean();
				delete aux;
			}
        }

        size_ = 0;
        inicio_ = NULL;
        fin_ = NULL;
    }

bool lista_t::empty(void)
{
	return (inicio_ == NULL);

}

void lista_t::push_back(lista_item_t* nodo)
{
	assert(nodo != NULL);
	if (!inicio_)
	{
		inicio_ = nodo;
		fin_ = inicio_;
     }else
     {
     	fin_->next_ = nodo;
     	nodo->prev_ = fin_;
     	fin_ = nodo;
     }
     size_++;
     }

lista_item_t* lista_t::pop_back(void)
{
	assert(fin_ != NULL);
	lista_item_t* aux = fin_;
	fin_ = fin_->prev_;

    if (fin_)
       fin_->next_ = NULL;
    else
    	inicio_ = NULL;

    size_--;

    return aux;
}


lista_item_t* lista_t::pop_front(void)
{
	assert(inicio_ != NULL);
	lista_item_t* aux = inicio_;
	inicio_ = inicio_->next_;

    if (inicio_)
         inicio_->prev_ = NULL;
   else
   		fin_ = NULL;

    size_--;

    return aux;
}

void lista_t::write(ostream& os)
{
	lista_item_t* aux = inicio_;

	while (aux != NULL)
    {
    	aux->write(os);
        aux = aux->next_;
    }
}


