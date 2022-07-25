#include "giocatore.h"

Giocatore::Giocatore() { }

Giocatore::Giocatore(const std::string nome, const unsigned short prezzo): Persona(nome,prezzo) { }

std::ostream& Giocatore::getInfo(std::ostream &os) const
{
    return Persona::getInfo(os);
}


//overloading << per Giocatore
std::ostream& operator<<(std::ostream &os, const Giocatore &giocatore)
{
    return giocatore.getInfo(os);
}