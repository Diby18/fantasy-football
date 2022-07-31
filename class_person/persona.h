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
        
        Persona(const Persona&);
        virtual Persona* clona() const = 0;

        virtual ~Persona();

        void getInfo(std::ostream&) const;
        std::string getNome() const;
        unsigned short getCrediti() const;

        bool operator<(const Persona&) const;

        virtual void eseguiOperazione(Persona*) = 0;

        friend std::ostream& operator<<(std::ostream&, const Persona&);
};


#endif