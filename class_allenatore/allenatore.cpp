#include "allenatore.h"
#include <fstream>
#include <typeinfo>

Allenatore::Allenatore(const std::string nome, const unsigned short crediti): Persona(nome,crediti) { }

void Allenatore::eseguiOperazione(Persona *giocatore)
{
    this->listaGiocatori.push_front(giocatore);
    
    this->crediti -= giocatore->getCrediti(); 
}

//overloading << per Allenatore
/*std::ostream& operator<<(std::ostream &os, const Allenatore &allenatore)
{
    allenatore.getInfo(os);
    
    for(auto i : allenatore.listaGiocatori) os<< * ( (Giocatore*) i);

    return os;
}*/