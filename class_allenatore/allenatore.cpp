#include "allenatore.h"
#include "../class_giocatore/giocatore.h"
#include <fstream>
#include <typeinfo>

Allenatore::Allenatore(const std::string nome, const unsigned short crediti): Persona(nome,crediti) { }

void Allenatore::eseguiOperazione(Persona *giocatore)
{
    std::string path = "./output/" + this->nome + ".txt";

    std::ofstream squadra(path, std::ios::app);

    this->listaGiocatori.push_front(giocatore);

    //squadra<<(std::string) *giocatore<<std::endl; 

   // else { std::cerr<<"Inserimento non valido\n"; return; }
    
    this->crediti -= giocatore->getCrediti(); 
}

//overloading << per Allenatore
std::ostream& operator<<(std::ostream &os, const Allenatore &allenatore)
{
    allenatore.getInfo(os);

    return os;
}