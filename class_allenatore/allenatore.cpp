#include "allenatore.h"
#include "../class_giocatore/giocatore.h"
#include <fstream>
#include <typeinfo>

Allenatore::Allenatore(const std::string nome, const unsigned short crediti): Persona(nome,crediti) { }

void Allenatore::operazione(const Persona *giocatore)
{
    std::ofstream squadra(this->nome + ".txt",std::ios::app);

    this->listaGiocatori.push_front(*giocatore);

    if(typeid(*giocatore) == typeid(Giocatore)) 
        
        squadra<<(std::string) *( (Giocatore*) giocatore )<<std::endl; 

    this->crediti -= giocatore->getCrediti(); 
}

std::ostream& Allenatore::getInfo(std::ostream &os) const
{
    system("cls");

    os<<"Allenatore\n\n";

    Persona::getInfo(os);

    os<<"Giocatori acquistati\n\n";

    for(auto giocatore : this->listaGiocatori) giocatore.getInfo(os);

    return os;
}


//overloading << per Allenatore
std::ostream& operator<<(std::ostream &os, const Allenatore &allenatore)
{
    return allenatore.getInfo(os);
}