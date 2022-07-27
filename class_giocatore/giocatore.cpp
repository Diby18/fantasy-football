#include "giocatore.h"

Giocatore::Giocatore(): Persona() { }

Giocatore::Giocatore(const std::string nome, 
const unsigned short prezzo, const char ruolo): Persona(nome,prezzo)
{
    this->ruolo = ruolo;
}

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
    os<<"Ruolo: "<<giocatore.ruolo<<std::endl;

    giocatore.getInfo(os);

    return os;
}

std::istream& operator>>(std::istream &is, Giocatore &giocatore)
{
    is>>giocatore.ruolo>>giocatore.nome>>giocatore.crediti;
    
    return is;
}