#ifndef ALLENATORE_H
#define ALLENATORE_H

#include <list>
#include "../class_person/persona.h"

class Allenatore: public Persona
{
    std::list<Persona*> listaGiocatori; 

    protected:
        std::ostream& getInfo(std::ostream &) const;

    public:
        Allenatore(const std::string, const unsigned short);
        void operazione(const Persona&);

        friend std::ostream& operator<<(std::ostream&, const Allenatore&);
};


#endif