#ifndef GIOCATORE_H
#define GIOCATORE_H

#include "../class_person/persona.h"

class Giocatore: public Persona
{
    char ruolo;

    public:
        Giocatore();
        Giocatore(const std::string, const unsigned short,const char);
        std::ostream& getInfo(std::ostream&) const;

        operator std::string() const;

        friend std::ostream& operator<<(std::ostream&,const Giocatore&);
};


#endif