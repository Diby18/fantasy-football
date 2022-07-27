#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

class Persona
{
    protected:
        std::string nome;
        unsigned short crediti;    
        
    public:
        Persona();
        Persona(const std::string, const unsigned short);
        virtual void getInfo(std::ostream&) const;
        virtual void eseguiOperazione(Persona*) = 0;

        std::string getNome() const;
        unsigned short getCrediti() const;
};


#endif