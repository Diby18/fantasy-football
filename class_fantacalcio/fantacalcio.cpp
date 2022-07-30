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

    if(allenatore->getCrediti() < giocatore->getCrediti())
    {
        std::cerr<<"\n\nSaldo non sufficiente per acquistare il giocatore\n";
        
        system("pause");

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

    std::cout<<std::endl;
}

void Fantacalcio::stampaAcquisti(std::string nomeAllenatore) const
{    
    Allenatore *allenatore = dynamic_cast<Allenatore*>(this->cerca(nomeAllenatore));

    if(allenatore->numeroAcquistati() == 0) 
        
        std::cout<<"Nessun giocatore acquistato"<<std::endl<<std::endl;

    else
    {
        for(unsigned short i = 0; i<allenatore->numeroAcquistati(); i++)

            std::cout<< *( (const Giocatore* const) (*allenatore)[i] )<<std::endl;
    }

    system("pause");
}

void Fantacalcio::stampaAcquisti() const
{
    for(auto i : this->giocatoriAcquistati)
    {
        Giocatore *giocatore = dynamic_cast<Giocatore*>(i);

        std::cout<<"Proprietario: "<< giocatore->getProprietario()->getNome()
            <<"\n"<<*giocatore<<std::endl;
    }

    if(this->giocatoriAcquistati.empty()) 
        
        std::cout<<"Nessun giocatore comprato"<<std::endl<<std::endl;

    system("pause");
}