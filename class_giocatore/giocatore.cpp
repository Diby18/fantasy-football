#include "giocatore.h"

Giocatore::Giocatore(): Persona(), proprietario(nullptr) { }

Giocatore::Giocatore(const std::string nome, 
const unsigned short prezzo, const char ruolo): Persona(nome,prezzo)
{
    this->ruolo = ruolo;

    this->proprietario = nullptr;
}

Giocatore::Giocatore(const Giocatore &giocatore): Persona(giocatore)
{
    this->ruolo = giocatore.ruolo;

    this->proprietario = new std::string(*giocatore.proprietario);
}

Persona* Giocatore::clona() const { return new Giocatore(*this); }

Giocatore::~Giocatore()
{
    if(this->proprietario)
    { 
        delete this->proprietario;

        this->proprietario = nullptr;
    }
}

void Giocatore::eseguiOperazione(Persona *proprietario)
{
    this->proprietario = new std::string(proprietario->getNome());
}

char Giocatore::getRuolo() const { return this->ruolo; }

const std::string& Giocatore::getProprietario() const { return *this->proprietario; }

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