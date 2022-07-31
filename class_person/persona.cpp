#include "persona.h"

Persona::Persona() { }

Persona::Persona(const std::string nome, const unsigned short crediti)
{
    this->nome = nome;

    this->crediti = crediti;
}

Persona::Persona(const Persona &persona): nome(persona.nome), crediti(persona.crediti) { }
    
Persona::~Persona() { }

void Persona::getInfo(std::ostream &os) const
{
    os<<"Nome: "<<this->nome<<"\nCrediti: "<<this->crediti<<std::endl<<std::endl;
}

std::string Persona::getNome() const { return this->nome; }

unsigned short Persona::getCrediti() const { return this->crediti; }

bool Persona::operator<(const Persona &persona) const
{
    return this->crediti < persona.crediti;
}

//overloading <<
std::ostream& operator<<(std::ostream &os, const Persona &persona)
{
    persona.getInfo(os);

    return os;
}