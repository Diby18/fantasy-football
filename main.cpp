#include <iostream>
#include <limits>
#include <vector>
#include <typeinfo>
#include <cctype>

#include "class_allenatore/allenatore.h"
#include "class_giocatore/giocatore.h"

using namespace std;

std::ostream& operator<<(std::ostream &os, const Persona &persona)
{
    persona.getInfo(os);

    return os;
}

ostream& operator<<(ostream &os, const vector<Persona*> vec)
{
    for(auto i : vec) os<<*i;

    return os;
}

bool checkInput(istream &is)
{
    if(cin.fail())
    {
        cerr<<"\nERRORE!!\nE' possibile inserire solo numeri\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return false;
    }

    return true;
}

void input(vector<Persona*> &allenatori, const unsigned short creditiAsta)
{
    unsigned short numeroAllenatori;
    string nomeAllenatore;

    do
    {
        cout<<"Inserire il numero di partecipanti: ";
        cin>>numeroAllenatori;

    } while(!checkInput(cin));

    for(unsigned i = 0; i<numeroAllenatori; i++)
    {
        system("cls");

        cout<<"Inserisci l'allenatore "<<i+1<<": ";
        cin>>nomeAllenatore;

        nomeAllenatore[0] = toupper(nomeAllenatore[0]);

        allenatori.push_back(new Allenatore(nomeAllenatore, creditiAsta));
    }
}

void input(vector<Persona*> &allenatori)
{
    bool errore;
    unsigned short crediti;

    system("cls");

    do
    {
        cout<<"Inserire i crediti dell'asta: ";
        cin>>crediti;

    } while(!checkInput(cin));

    system("cls");

    input(allenatori,crediti);

    system("cls");
}

unsigned short selezioneAzione()
{
    unsigned short scelta;

    do
    {
        system("cls");

        cout<<"Cosa vuoi fare?\n\n- 0 per terminare la sessione"<<
            "\n- 1 per registare un acquisto\n- 2 per stampare"
            << "gli acquisti di un allenatore"<<endl<<endl;

        cout<<"Inserisci: ";

        cin>>scelta;

    } while(!checkInput(cin));

    return scelta;
}

int main()
{
    vector<Persona*> allenatori;
    vector<Persona*> giocatoriAcquistati;

    /*input(allenatori);

    cout<<allenatori;*/

    selezioneAzione();

    cout<<"\n\nFine";

    return 0;
}