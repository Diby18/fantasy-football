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

    //ordinare crescentemente gli acquisti
    void merge(unsigned short, unsigned short, unsigned short);
    void mergeSort(unsigned short, unsigned short);

    public:
        Fantacalcio();
        ~Fantacalcio();
        void aggiungiAllenatore(Persona *);
        void acquistaGiocatore(const std::string, Persona*);
        
        void stampaAllenatori() const;

        //acquisti di un determinato allenatore
        void stampaAcquisti(const std::string) const;

        //tutti i giocatori acquistati al momento
        void stampaAcquisti() const;

        //cerca allenatore
        Persona* cerca(const std::string) const;

        //cerca giocatore 
        Persona* cerca(const Persona* ) const;
};




#endif