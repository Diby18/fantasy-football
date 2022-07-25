#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

class Persona
{
    protected:
        std::string nome;
        unsigned short crediti;    
        
        virtual std::ostream& getInfo(std::ostream&) const;
    
    public:
        Persona();
        Persona(const std::string, const unsigned short);
};


#endif