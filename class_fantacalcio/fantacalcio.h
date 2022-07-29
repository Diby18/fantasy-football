#ifndef FANTACALCIO_H
#define FANTACALCIO_H

#include <iostream>
#include <vector>
#include <fstream>

#include "../class_allenatore/allenatore.h"
#include "../class_giocatore/giocatore.h"

class Fantacalcio
{
    std::vector<Persona*> allenatori;
    std::vector<Persona*> giocatoriAcquistati;

    //const unsigned short creditiAsta;

    Persona* cercaAllenatore(const std::string) const;

    public:
        Fantacalcio();
        void aggiungiAllenatore(Persona *);
        void acquistaGiocatore(const std::string, Persona*);
        void stampaAllenatori() const;
};




#endif