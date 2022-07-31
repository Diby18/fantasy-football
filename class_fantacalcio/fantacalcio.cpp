#include "fantacalcio.h"

void Fantacalcio::merge(unsigned short inizio, unsigned short centrale,unsigned short fine)
{
    std::vector<Persona*> sequenzaSx, sequenzaDx;

    sequenzaSx.reserve(centrale - inizio + 1);
    sequenzaDx.reserve(fine - centrale);

    for(unsigned short i = 0; i<sequenzaSx.capacity(); i++) 
        
        sequenzaSx[i] = this->giocatoriAcquistati[inizio + i];

    for(unsigned short i = 0; i<sequenzaDx.capacity(); i++) 
        
        sequenzaDx[i] = this->giocatoriAcquistati[centrale + i + 1];

    
    unsigned short indexSx = 0, indexDx = 0;

    for(unsigned i = inizio; i<=fine; i++)
    {
        if(indexSx < sequenzaSx.capacity() && indexDx < sequenzaDx.capacity())
        {
            if(*sequenzaSx[indexSx] < *sequenzaDx[indexDx]) 
                
                this->giocatoriAcquistati[i] = sequenzaSx[indexSx++];
            
            else 
                
                this->giocatoriAcquistati[i] = sequenzaDx[indexDx++];
        }

        else if(indexSx < sequenzaSx.capacity()) this->giocatoriAcquistati[i] = sequenzaSx[indexSx++];

        else this->giocatoriAcquistati[i] = sequenzaDx[indexDx++];
    }
}

void Fantacalcio::mergeSort(unsigned short inizio, unsigned short fine)
{
    if(inizio < fine)
    {
        unsigned short centrale = (inizio + fine) / 2;

        this->mergeSort(inizio, centrale);

        this->mergeSort(centrale + 1, fine);

        this->merge(inizio, centrale, fine);
    }

}

Fantacalcio::Fantacalcio() { }

Fantacalcio::~Fantacalcio()
{
    for(auto i : this->giocatoriAcquistati)
    {
        if(i)
        {
            delete i;

            i = nullptr;
        }   

    }

    for(auto i : this->allenatori)
    {
        if(i)
        {
            delete i;

            i = nullptr;
        }
    }
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
        system("cls");

        std::cerr<<"ERRORE\nSaldo non sufficiente per acquistare il giocatore"<<std::endl;
        
        system("pause");

        return;
    }

    giocatore->eseguiOperazione(allenatore);

    allenatore->eseguiOperazione(giocatore);

    this->giocatoriAcquistati.push_back(giocatore->clona());

    this->mergeSort(0, this->giocatoriAcquistati.size() - 1);

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

        std::cout<<"Proprietario: "<< giocatore->getProprietario()
            <<"\n"<<*giocatore<<std::endl;
    }

    if(this->giocatoriAcquistati.empty()) 
        
        std::cout<<"Nessun giocatore comprato"<<std::endl<<std::endl;

    system("pause");
}

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