#include <iostream>
#include <limits>
#include <stdexcept>
#include <ctype.h>


#include "class_fantacalcio/fantacalcio.h"

using namespace std;

inline string noAlloc() { return "Impossibile allocare memoria"; } 

//input su stream
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

void input(Fantacalcio &fanta, const unsigned short crediti)
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

        fanta.aggiungiAllenatore(new Allenatore(nomeAllenatore,crediti));
    }
}

void input(Fantacalcio &fanta)
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

    input(fanta,crediti);

    system("cls");
}

Giocatore* creaGiocatore()
{
    Giocatore *nuovo = new Giocatore;
    bool errore;
    string ruoliPossibili = "PDCA";
   
    do
    {
        errore = false;

        cout<<"Inserire i dati del giocatore nel seguente formato:"
            <<"ruolo nome prezzo\n"<<"Es: A Immobile 100\n\nInserisci: ";
    
        cin>>*nuovo;

        errore = !checkInput(cin);

        if(ruoliPossibili.find(nuovo->getRuolo()) == string::npos)
        {
            errore = true;

            cerr<<"\nERRORE!!\nI ruoli possibili sono: P D C A\n";
        }

    } while(errore);

    return nuovo;
}

unsigned short selezioneAzione()
{
    unsigned short scelta;

    do
    {
        cout<<"Cosa vuoi fare?\n\n- 0 per terminare la sessione"<<
            "\n- 1 per registare un acquisto\n- 2 per stampare"
            << "gli acquisti di un allenatore"<<endl<<endl;

        cout<<"Inserisci: ";

        cin>>scelta;

    } while(!checkInput(cin));

    return scelta;
}

void esegui(Fantacalcio &fanta)
{
    unsigned short azione;

    while( (azione = selezioneAzione()) != 0)
    {
        if(azione == 1)
        {
            string allenatore;
            bool notFound;

            do
            {
                notFound = false;

                cout<<"Inserire il nome dell'allenatore: ";
                cin>>allenatore;

                if(!fanta.cercaAllenatore(allenatore))
                {
                    system("cls");

                    notFound = true;

                    cerr<<"\n\nERRORE\nL'allenatore inserito non esiste\n";
                }

            } while(notFound);
            
            system("cls");

            fanta.acquistaGiocatore(allenatore, creaGiocatore());
        }
    }

}

int main()
{
    Fantacalcio *fanta = new Fantacalcio;

    if(!fanta) throw runtime_error(noAlloc());

    input(*fanta);

    fanta->stampaAllenatori();

    cout<<endl;

    esegui(*fanta);

    cout<<endl;
    fanta->stampaAllenatori();

    cout<<"\n\nFine";

    return 0;
}