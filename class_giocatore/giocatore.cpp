#include "giocatore.h"

Giocatore::Giocatore() { }

Giocatore::Giocatore(const std::string nome, const unsigned short prezzo, const char ruolo): Persona(nome,prezzo) 
{ 
    this->ruolo = ruolo;
}

std::ostream& Giocatore::getInfo(std::ostream &os) const
{
    os<<"\tRuolo: "<<this->ruolo<<"\n";

    return Persona::getInfo(os);
}

Giocatore::operator std::string() const
{
    return '(' + std::string(1,this->ruolo) + ") " + this->nome + " " + std::to_string(this->crediti);
}

//overloading << per Giocatore
std::ostream& operator<<(std::ostream &os, const Giocatore &giocatore)
{
    return giocatore.getInfo(os);
}