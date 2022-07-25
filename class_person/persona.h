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
        operator std::string() const;
        virtual std::ostream& getInfo(std::ostream&) const;
    
};


#endif