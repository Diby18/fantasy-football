#ifndef GIOCATORE_H
#define GIOCATORE_H

#include "../class_person/persona.h"

class Giocatore: public Persona
{
    const char ruolo;
    const Persona *proprietario;

    public:
        Giocatore(const std::string, const unsigned short,const char);
        void eseguiOperazione(Persona*);

        operator std::string() const;

        friend std::ostream& operator<<(std::ostream&,const Giocatore&);
};


#endif