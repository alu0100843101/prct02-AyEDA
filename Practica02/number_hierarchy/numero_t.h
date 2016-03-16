#include "../lib/common.h"

class numero_t {	
  public:

    virtual ostream& toStream(ostream& sout) const = 0; //Escribe un número al flujo
    virtual istream& fromStream(istream& sin) = 0;    //Lee un número desde el flujo    

};