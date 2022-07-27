#include <iostream>
#include <limits>
#include <vector>
#include <typeinfo>
#include <cctype>

#include "class_allenatore/allenatore.h"
#include "class_giocatore/giocatore.h"
#include "class_fantacalcio/fantacalcio.h"

using namespace std;

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

/*void esegui(vector<Persona*> allenatori, vector<Persona*> giocatoriAcquisiti)
{
    unsigned short azione;

    while( ( azione = selezioneAzione() ) != 0)
    {
        if(azione == 1)
        {
            Giocatore *nuovo = new Giocatore;

            cout<<"Inserire il ruolo, il nome e il prezzo di acquisto del giocatore"
                    <<" nel seguente ordine ed lasciando tra ogni campo uno spazio\n"
                    <<"Es: A Immobile 100";
                
            cin>>*nuovo;

            allenatori.push_back(nuovo);
        }

        else if(azione == 2)
        {
            string nome;
            cout<<"Inserire il nome dell'allenatore di cui si vogliono vedere gli acquisti: ";

            cin>>nome;

            for(auto i : allenatori)
            {
                if(nome == i->getNome())
                {
                    for(auto j : i->)

                }

            }
        }
    }

}*/

int main()
{
    /*vector<Persona*> allenatori;
    vector<Persona*> giocatoriAcquistati;*/

    /*input(allenatori);

    cout<<allenatori;*/

    Fantacalcio fanta(1000);

    fanta.aggiungiAllenatore(new Allenatore("flavio",1000));
    fanta.aggiungiAllenatore(new Allenatore("mattia",1000));

    fanta.stampaAllenatori();

    cout<<"\n\nFine";

    return 0;
}