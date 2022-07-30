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

char Giocatore::getRuolo() const { return this->ruolo; }

const Persona* const Giocatore::getProprietario() const { return this->proprietario; }

Giocatore::operator std::string() const
{
    return '(' + std::string(1,this->ruolo) + ") " + this->nome + " " 
        + std::to_string(this->crediti);
}

bool Giocatore::operator==(const Giocatore &giocatore) const
{
    return this->nome == giocatore.nome && this->ruolo == giocatore.ruolo;
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
    
    giocatore.ruolo = toupper(giocatore.ruolo);

    for(auto &i: giocatore.nome) i = tolower(i);

    return is;
}