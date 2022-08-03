#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <ctype.h>
#include <vector>
#include "../class_person/persona.h"

class Giocatore: public Persona
{
    char ruolo;
    const std::string *proprietario;

    public:
        Giocatore();
        Giocatore(const std::string, const unsigned short,const char);
        Giocatore(const Giocatore&);
        ~Giocatore();
        
        Persona* clona() const;

        char getRuolo() const;
        const std::string& getProprietario() const;

        operator std::string() const;
        bool operator==(const Giocatore&) const;

        void eseguiOperazione(Persona*);

        friend std::ostream& operator<<(std::ostream&,const Giocatore&);
        friend std::istream& operator>>(std::istream&, Giocatore&);
        friend void caricaDatiGiocatore(const std::vector<std::string>&, Giocatore*);
};


#endif