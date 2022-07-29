#include "fantacalcio.h"

Fantacalcio::Fantacalcio() { }

Persona* Fantacalcio::cercaAllenatore(const std::string nome) const
{
    for(auto i : this->allenatori)

        if(i->getNome() == nome) return i;

    return nullptr;
}

void Fantacalcio::aggiungiAllenatore(Persona *allenatore)
{
    this->allenatori.push_back(allenatore);
}

void Fantacalcio::acquistaGiocatore(std::string nomeAllenatore, Persona *giocatore)
{
    Persona *allenatore = this->cercaAllenatore(nomeAllenatore);

    if(!allenatore) { std::cerr<<"\nAllenatore non trovato\n"; return; }

    allenatore->eseguiOperazione(giocatore);

    giocatore->eseguiOperazione(allenatore);

    std::string path = "./output/" + allenatore->getNome() + ".txt";

    std::ofstream squadra(path, std::ios::app);

    squadra<< (std::string) *( (Giocatore*) giocatore );
}

void Fantacalcio::stampaAllenatori() const
{
    for(auto i : this->allenatori) std::cout<<*i;
}
