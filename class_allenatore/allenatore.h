#ifndef ALLENATORE_H
#define ALLENATORE_H

#include <list>
#include "../class_person/persona.h"

class Allenatore: public Persona
{
    std::list<Persona*> listaGiocatori; 

    public:
        Allenatore(const std::string, const unsigned short);
        void operazione(const Persona*); //acquisto di un giocatore
        void getInfo(std::ostream&) const;

        friend std::ostream& operator<<(std::ostream&, const Allenatore&);
};


#endif