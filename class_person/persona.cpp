#include "persona.h"

Persona::Persona() { }

Persona::Persona(const unsigned short id, const std::string nome, const unsigned short crediti)
{
    this->id = id;

    this->nome = nome;

    this->crediti = crediti;
}

std::ostream& Persona::getInfo(std::ostream &os) const
{
    return os<<"ID: "<<this->id<<"\nNome: "<<this->nome<<"\nCrediti: "<<this->crediti<<std::endl;
}