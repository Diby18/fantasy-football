#ifndef FANTACALCIO_H
#define FANTACALCIO_H

#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <windows.h>

#include "../class_allenatore/allenatore.h"
#include "../class_giocatore/giocatore.h"

inline unsigned attesa() { return 1000; }

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
        void stampaAcquisti(const std::string) const;
        void stampaAcquisti() const;

        Persona* cerca(const std::string) const;
        Persona* cerca(const Persona* ) const;

};




#endif