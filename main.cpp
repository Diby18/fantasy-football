#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>

#include "class_fantacalcio/fantacalcio.h"

using namespace std;

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

//input su stringa
string* spliStr(const string &input)
{
    string *info = new string[3];

    int indexBlank, pos = 0, count = 0;

    while(pos < input.length())
    {
        indexBlank = input.find("", pos);

        info[count++] = input.substr(pos, indexBlank - pos);

        pos = indexBlank + 1;
    }

    return (count == 1 || count == 2 ? info : nullptr);
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

    do
    {
        azione = selezioneAzione();

        switch(azione)
        {
            case 0:
                

        }

    } while(azione != 0);

}

int main()
{
    Fantacalcio *fanta = new Fantacalcio;

    if(!fanta) throw runtime_error("Impossibile allocare memoria\0");

    input(*fanta);

    fanta->stampaAllenatori();

    cout<<endl;

    esegui(*fanta);

    cout<<endl;
    fanta->stampaAllenatori();

    cout<<"\n\nFine";

    return 0;
}