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
        virtual std::ostream& getInfo(std::ostream&) const;

        std::string getNome() const;
        unsigned short getCrediti() const;
};


#endif