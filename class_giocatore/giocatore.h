#ifndef GIOCATORE_H
#define GIOCATORE_H

#include "../class_person/persona.h"

class Giocatore: public Persona
{
    public:
        Giocatore();
        Giocatore(const std::string, const unsigned short);
        std::ostream& getInfo(std::ostream&) const;

        friend std::ostream& operator<<(std::ostream&,const Giocatore&);
};


#endif