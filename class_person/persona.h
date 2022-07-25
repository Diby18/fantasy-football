#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

class Persona
{
    protected:
        unsigned short id, crediti;    
        std::string nome;
        
        virtual std::ostream& getInfo(std::ostream&) const;
    
    public:
        Persona(const unsigned short, const std::string, const unsigned short);
};


#endif