#include "allenatore.h"
#include "../class_giocatore/giocatore.h"
#include <fstream>
#include <typeinfo>

Allenatore::Allenatore(const std::string nome, const unsigned short crediti): Persona(nome,crediti) { }

void Allenatore::operazione(const Persona *giocatore)
{
    std::ofstream squadra(this->nome + ".txt",std::ios::app);

    if(typeid(*giocatore) == typeid(Giocatore))
    {
        Giocatore *nuovo = (Giocatore*) giocatore;

        this->listaGiocatori.push_front(new Giocatore(*nuovo));
    }

    else { std::cerr<<"Inserimento non valido\n"; return; }
    
    this->crediti -= giocatore->getCrediti(); 
}

void Allenatore::getInfo(std::ostream &os) const
{
    system("cls");

    os<<"Allenatore\n\n";

    Persona::getInfo(os);

    os<<"Giocatori acquistati\n\n";

    for(auto giocatore : this->listaGiocatori) giocatore->getInfo(os);
}


//overloading << per Allenatore
std::ostream& operator<<(std::ostream &os, const Allenatore &allenatore)
{
    allenatore.getInfo(os);

    return os;
}