#include "allenatore.h"
#include <fstream>
#include <typeinfo>

Allenatore::Allenatore(const std::string nome, const unsigned short crediti): Persona(nome,crediti) { }

Persona* Allenatore::clona() const { return new Allenatore(*this); }

Allenatore::~Allenatore()
{
    for(auto i : this->listaGiocatori)
    {
        if(i) 
        { 
            delete i; 
            
            i = nullptr; 
        }
    }
}

void Allenatore::eseguiOperazione(Persona *giocatore)
{
    this->listaGiocatori.push_back(giocatore);

    this->crediti -= giocatore->getCrediti();
}

const Persona* const Allenatore::operator[](const unsigned index) const
{
    return this->listaGiocatori[index % this->listaGiocatori.size()];
}

unsigned short Allenatore::numeroAcquistati() const
{
    return this->listaGiocatori.size();
}

//overloading << per Allenatore
std::ostream& operator<<(std::ostream &os, const Allenatore &allenatore)
{
    allenatore.getInfo(os);
    
    for(auto i : allenatore.listaGiocatori) os<<*i;

    return os;
}