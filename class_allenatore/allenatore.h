#ifndef ALLENATORE_H
#define ALLENATORE_H

#include <vector>
#include "../class_person/persona.h"

class Allenatore: public Persona
{
    std::vector<Persona*> listaGiocatori;

    public:
        Allenatore(const std::string, const unsigned short);
        ~Allenatore();
        
        Persona* clona() const;

        unsigned short numeroAcquistati() const;

        const Persona* const operator[](const unsigned) const;

        void eseguiOperazione(Persona*); //acquisto di un giocatore

        friend std::ostream& operator<<(std::ostream&, const Allenatore&);
};


#endif