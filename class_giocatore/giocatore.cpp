#include "giocatore.h"

Giocatore::Giocatore(const std::string nome, 
const unsigned short prezzo, const char _ruolo): Persona(nome,prezzo), ruolo(_ruolo) { }

void Giocatore::eseguiOperazione(Persona *proprietario)
{
    this->proprietario = proprietario;
}

Giocatore::operator std::string() const
{
    return '(' + std::string(1,this->ruolo) + ") " + this->nome + " " 
        + std::to_string(this->crediti);
}

//overloading << per Giocatore
std::ostream& operator<<(std::ostream &os, const Giocatore &giocatore)
{
    giocatore.getInfo(os);

    return os;
}