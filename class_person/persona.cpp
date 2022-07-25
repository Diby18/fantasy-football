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

Persona::operator std::string() const
{
    return this->nome + std::to_string(this->crediti);
}

unsigned short Persona::getCrediti() const { return this->crediti; }