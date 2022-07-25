#include "persona.h"

Persona::Persona() { }

Persona::Persona(const std::string nome, const unsigned short crediti)
{
    this->nome = nome;

    this->crediti = crediti;
}

std::ostream& Persona::getInfo(std::ostream &os) const
{
    return os<<"Nome: "<<this->nome<<"\nCrediti: "<<this->crediti<<std::endl;
}