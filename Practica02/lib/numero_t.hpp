#pragma once

#include "common.hpp"

class numero_t
{
    public:

	    //Escribe un Numero al flujo sout
	    virtual ostream& toStream(ostream& sout) const = 0;
	
	    //Lee un Numero desde flujo sin
	    virtual istream& fromStream(istream& sin) = 0;	
};