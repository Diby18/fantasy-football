#include "fantacalcio.h"

Fantacalcio::Fantacalcio() { }

Persona* Fantacalcio::cerca(const std::string nome) const
{
    for(auto i : this->allenatori)

        if(i->getNome() == nome) return i;

    return nullptr;
}

Persona* Fantacalcio::cerca(const Persona *giocatore) const
{
    for(auto i : this->giocatoriAcquistati)

        if( *((Giocatore*) i) == *((Giocatore*) giocatore)) 
            return i;
    
    return nullptr;
}

void Fantacalcio::aggiungiAllenatore(Persona *allenatore)
{
    this->allenatori.push_back(allenatore);
}

void Fantacalcio::acquistaGiocatore(std::string nomeAllenatore, Persona *giocatore)
{
    Persona *allenatore = this->cerca(nomeAllenatore);

    if(this->cerca(giocatore))
    {
        std::cerr<<"\n\nIl giocatore e' stato gia' comprato\n";

        Sleep(attesa());

        return;
    }

    if(!allenatore) { std::cerr<<"\nAllenatore non trovato\n"; return; }

    if(allenatore->getCrediti() < giocatore->getCrediti())
    {
        std::cerr<<"\n\nSaldo non sufficiente per acquistare il giocatore\n";
        
        Sleep(attesa());

        return;
    }
        
    allenatore->eseguiOperazione(giocatore);

    giocatore->eseguiOperazione(allenatore);

    this->giocatoriAcquistati.push_back(giocatore);

    std::string path = "./output/" + allenatore->getNome() + ".txt";

    std::ofstream squadra(path, std::ios::app);

    squadra<< (std::string) *( (Giocatore*) giocatore )<<std::endl;
}

void Fantacalcio::stampaAllenatori() const
{
    for(auto i : this->allenatori) std::cout<<*i;
}
