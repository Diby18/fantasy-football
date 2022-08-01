#include <iostream>
#include <limits>
#include <stdexcept>
#include <ctype.h>
#include <fstream>

#include "class_fantacalcio/fantacalcio.h"

using namespace std;

inline string noAlloc() { return "Impossibile allocare memoria"; } 

inline unsigned short minCrediti() { return 100; }

void toUpperStr(string &str)
{
    for(auto &i : str) i = toupper(i);
}

//input su stream
bool checkInput(istream &is)
{
    if(cin.fail())
    {
        system("cls");

        cerr<<"ERRORE!!\nE' possibile inserire solo numeri"<<std::endl<<std::endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        return false;
    }

    return true;
}

void input(Fantacalcio &fanta, const unsigned short crediti)
{
    short numeroAllenatori;
    string nomeAllenatore;
    bool errore;

    do
    {
        errore = false;

        cout<<"Inserire il numero di partecipanti: ";
        cin>>numeroAllenatori;

        if(numeroAllenatori <= 0)
        {
            system("cls");

            cerr<<"ERRORE\nImpossibile inserire 0 o meno allenatori"<<endl;

            errore = true;
        }

        errore = !checkInput(cin) || errore;

    } while(errore);

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
    short crediti;

    system("cls");

    do
    {
        errore = false;

        cout<<"Inserire i crediti dell'asta: ";
        cin>>crediti;

        if(crediti < minCrediti())
        {
            system("cls");

            cerr<<"ERRORE\nImpossibile inserire meno di 100 crediti!"<<endl;

            errore = true;
        }

        errore = !checkInput(cin) || errore;

    } while(errore);

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
            system("cls");

            errore = true;

            cerr<<"ERRORE!!\nI ruoli possibili sono: P D C A\n";
        }

    } while(errore);

    return nuovo;
}

unsigned short selezioneAzione()
{
    short scelta;
    bool errore;

    do
    {
        errore = false;

        cout<<"Cosa vuoi fare?\n\n- 0 per terminare la sessione"<<
            "\n- 1 per registare un acquisto\n- 2 per stampare "
            << "gli acquisti di un allenatore\n- 3 per stampare tutti "
            << "i giocatori comprati\n- 4 per verificare se un determinato"
            <<" giocatore e' stato acquistato"<<endl<<endl;

        cout<<"Inserisci: ";

        cin>>scelta;

        if(scelta < 0 && scelta > 4)
        {
            system("cls");

            cerr<<"Errore\nInserisci solamente i numeri indicati"<<endl;

            errore = true;
        }

        errore = !checkInput || errore;

    } while(errore);

    return scelta;
}

void esegui(Fantacalcio &fanta)
{
    unsigned short azione;

    fanta.stampaAllenatori();

    while( (azione = selezioneAzione()) != 0)
    {
        system("cls");
        
        if(azione == 1 || azione == 2)
        {
            string allenatore;
            bool notFound;

            do
            {
                notFound = false;

                cout<<"Inserire il nome dell'allenatore: ";
                cin>>allenatore;

                if(!fanta.cerca(allenatore))
                {
                    system("cls");

                    notFound = true;

                    cerr<<"ERRORE\nL'allenatore inserito non esiste"<<endl<<endl;
                }

            } while(notFound);
            
            system("cls");

            if(azione == 1)
            {
                Giocatore *nuovo = creaGiocatore();
                
                if(!fanta.cerca(nuovo)) fanta.acquistaGiocatore(allenatore, nuovo);

                else
                {
                    system("cls");

                    cerr<<"ERRORE\nIl giocatore e' stato gia' comprato"<<endl;
                    
                    delete nuovo;

                    system("pause");
                }
            }

            else fanta.stampaAcquisti(allenatore);
        }

        else if(azione == 3) fanta.stampaAcquisti();

        else
        {
            system("cls");

            string nome;

            cout<<"Inserire il giocatore da cercare: ";
            cin>>nome;

            toUpperStr(nome);
            
            fanta.esiste(nome);
        }

        system("cls");

        fanta.stampaAllenatori();
    }

}

void salva(const Fantacalcio &fanta)
{
    ofstream file("crediti.txt");

    for(auto i : fanta.allenatori)

        file<<(string) *i<<endl;
}

bool carica(Fantacalcio &fanta)
{
    ifstream file("crediti.txt");
    
    if(!file.is_open() || file.peek() == ifstream::traits_type::eof()) return false;

    string row, nome, crediti;

    int blank;

    while(getline(file,row))
    {
        blank = row.find(" ", 0);

        nome = row.substr(0, blank);
        crediti = row.substr(blank + 1);

        fanta.aggiungiAllenatore( new Allenatore( nome, stoi(crediti) ) );
    }

    return true;
}

int main()
{
    Fantacalcio *fanta = new Fantacalcio;

    if(!fanta) throw runtime_error(noAlloc());

    if(!carica(*fanta)) input(*fanta);

    esegui(*fanta);

    salva(*fanta);

    delete fanta;

    cout<<"\n\nFine";

    return 0;
}