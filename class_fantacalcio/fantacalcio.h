#ifndef FANTACALCIO_H
#define FANTACALCIO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>

#include "../class_allenatore/allenatore.h"
#include "../class_giocatore/giocatore.h"

class Fantacalcio
{
    std::vector<Persona*> allenatori;
    std::vector<Persona*> giocatoriAcquistati;

    //const unsigned short creditiAsta;

    public:
        Fantacalcio();
        void aggiungiAllenatore(Persona *);
        void acquistaGiocatore(const std::string, Persona*);
        void stampaAllenatori() const;

         Persona* cercaAllenatore(const std::string) const;
        Persona* cercaGiocatore(const std::string) const;

};




#endif