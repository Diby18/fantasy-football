#include "fantacalcio.h"

Fantacalcio::Fantacalcio(const unsigned short crediti): creditiAsta(crediti) { }

void Fantacalcio::aggiungiAllenatore(Persona *allenatore)
{
    this->allenatori.push_back(allenatore);
}

void Fantacalcio::stampaAllenatori() const
{
    for(auto i : this->allenatori) std::cout<<*i;
}
