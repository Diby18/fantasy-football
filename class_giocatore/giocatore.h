#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <ctype.h>
#include "../class_person/persona.h"

class Giocatore: public Persona
{
    char ruolo;
    const std::string *proprietario;

    public:
        Giocatore();
        Giocatore(const std::string, const unsigned short,const char);
        
        Giocatore(const Giocatore&);
        Persona* clona() const;

        ~Giocatore();

        char getRuolo() const;
        const std::string& getProprietario() const;

        void eseguiOperazione(Persona*);

        operator std::string() const;
        bool operator==(const Giocatore&) const;

        friend std::ostream& operator<<(std::ostream&,const Giocatore&);
        friend std::istream& operator>>(std::istream&, Giocatore&);
};


#endif