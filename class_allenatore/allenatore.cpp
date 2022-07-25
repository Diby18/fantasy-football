#include "allenatore.h"
#include <fstream>

Allenatore::Allenatore(const std::string nome, const unsigned short crediti): Persona(nome,crediti) { }

void Allenatore::operazione(const Persona &giocatore)
{
    std::ofstream squadra(this->nome + ".txt");

    this->listaGiocatori.push_front(giocatore);

    squadra<<(std::string) giocatore<<"\n";
}

std::ostream& Allenatore::getInfo(std::ostream &os) const
{
    Persona::getInfo(os);

    for(auto giocatore : this->listaGiocatori) giocatore.getInfo(os);

    return os;
}


//overloading << per Allenatore
std::ostream& operator<<(std::ostream &os, const Allenatore &allenatore)
{
    return allenatore.getInfo(os);
}