#include "persona.h"

Persona::Persona() { }

Persona::Persona(const std::string _nome, const unsigned short crediti): nome(_nome)
{
    this->crediti = crediti;
}

void Persona::getInfo(std::ostream &os) const
{
    os<<"Nome: "<<this->nome<<"\nCrediti: "<<this->crediti<<std::endl<<std::endl;
}

std::string Persona::getNome() const { return this->nome; }

unsigned short Persona::getCrediti() const { return this->crediti; }