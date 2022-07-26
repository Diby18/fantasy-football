#include "persona.h"

Persona::Persona() { }

Persona::Persona(const std::string nome, const unsigned short crediti)
{
    this->nome = nome;

    this->crediti = crediti;
}

std::ostream& Persona::getInfo(std::ostream &os) const
{
    return os<<"\tNome: "<<this->nome<<"\n\tCrediti: "<<this->crediti<<std::endl<<std::endl;
}

unsigned short Persona::getCrediti() const { return this->crediti; }