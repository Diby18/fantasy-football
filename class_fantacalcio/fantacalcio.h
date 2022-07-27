#ifndef FANTACALCIO_H
#define FANTACALCIO_H

#include <iostream>
#include <vector>
#include "../class_person/persona.h"

class Fantacalcio
{
    std::vector<Persona*> allenatori;
    std::vector<Persona*> giocatoriAcquistati;

    const unsigned short creditiAsta;

    public:
        Fantacalcio(const unsigned short);
        void aggiungiAllenatore(Persona *giocatore);
        void stampaAllenatori() const;
};




#endif