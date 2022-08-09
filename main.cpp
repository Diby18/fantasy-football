#include <iostream>
#include <limits>
#include <stdexcept>
#include <ctype.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "class_fantacalcio/fantacalcio.h"

using namespace std;

//messaggio di errore in caso di mancata allocazione
inline string noAlloc() { return "Impossibile allocare memoria"; } 

//numero minimo di crediti per l'asta
inline unsigned short minCrediti() { return 100; }

//converte i caratteri di una stringa in caratteri maiuscoli 
void toUpperStr(string &str)
{
    for(auto &i : str) i = toupper(i);
}

//estrae tutte le informazioni contenute nella stringa
vector<string>* splitStr(const string &str)
{
    vector<string> *vec = new vector<string>;

    if(!vec) throw runtime_error(noAlloc());

    int pos = 0, blank;

    do
    {
        blank = str.find(' ', pos);

        vec->push_back( str.substr(pos, blank - pos) );

        pos = blank + 1;

    } while(pos-1 != string::npos);

    return vec;
}

//controllo dell'input stream
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

//verifica la presenza di caratteri non numerici
bool checkInput(const string &str)
{
    for(auto i : str)

        if(!isdigit(i)) return false;

    return true;
}

//verifica che le informazioni contenute nella struttura siano nel formato corretto
bool checkInput(const vector<string> &vec)
{
    unsigned count = 0;

    const string ruoli = "PDCA";

    if(ruoli.find(vec[0]) == string::npos) return false;
    
    return ( checkInput(vec[vec.size() - 1]) && !(vec[vec.size() - 1] == "0") );
}

//input allenatori
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

//input dati asta
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

//caricare i dati contenuti nella struttura nell'oggetto giocatore
void caricaDatiGiocatore(const vector<string> &info, Giocatore *giocatore)
{
    giocatore->ruolo = info[0].at(0);

    for(unsigned i = 1; i<info.size(); i++)
    {
        if(!checkInput(info[i]))
        {
            giocatore->nome += info[i];

            if(!checkInput(info[i+1])) giocatore->nome += " ";
        }

        else giocatore->crediti = stoi(info[i]);
    }
}

//crea un nuovo giocatore
Persona* creaGiocatore()
{
    Giocatore *nuovo = new Giocatore;

    bool errore;
    string ruoliPossibili = "PDCA", tmp;
    vector<string> *info;

    do
    {
        errore = false;

        cout<<"Per annullare l'operazione digitare 0\n\n"
            <<"Altrimenti inserire i dati del giocatore nel seguente formato: "
            <<"ruolo nome prezzo\n"<<"Es: A Immobile 100\n\nInserisci: ";

        cin.clear();
        cin.sync();

        getline(cin, tmp);

        if(tmp == "0") return nullptr;

        toUpperStr(tmp);

        info = splitStr(tmp);

        if(!checkInput(*info))
        {
            system("cls");

            cerr<<"ERRORE!!\nInserire correttamente i dati"<<endl<<endl;

            errore = true;

            delete info;
        }

    } while(errore);

    caricaDatiGiocatore(*info, nuovo);

    if(info)
    {
        delete info;
        info = nullptr;
    }

    return nuovo;
}

//menu principale
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

        errore = !checkInput(cin) || errore;

    } while(errore);

    return scelta;
}

//esecuzione dell'azione scelta dall'utente
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
                Persona *nuovo = creaGiocatore();
                
                if(nuovo && !fanta.cerca(nuovo)) fanta.acquistaGiocatore(allenatore, nuovo);

                else if(nuovo)
                {
                    system("cls");

                    cerr<<"ERRORE\nIl giocatore e' stato gia' comprato"<<endl<<endl;
                    
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
            
            cin.clear();
            cin.sync();

            getline(cin, nome);

            toUpperStr(nome);
            
            fanta.esiste(nome);
        }

        system("cls");

        fanta.stampaAllenatori();
    }

}

//salvataggio su file dei dati
void salva(const Fantacalcio &fanta)
{
    ofstream file("crediti.txt");

    for(auto i : fanta.allenatori)

        file<<(string) *i<<endl;
}

//eliminazione dei dati salvati
bool eliminazioneSalvataggi()
{
    char scelta = '\0';
    bool errore;    
    
    do
    {
        errore = false;

        if(scelta == '\0') 
        {
            cout<<"Sono presenti dati in memoria, caricarli?\n\n"
                <<"Digitare S per si oppure N per no: ";
            
            cin>>scelta;

            scelta = toupper(scelta);
        } 
            
        if(scelta != 'S' && scelta != 'N')
        {
            system("cls");

            cerr<<"ERRORE\nE' possibile inserire solo S o N"<<endl<<endl;

            errore = true;

            scelta = '\0';
        }

        if(scelta == 'N')
        {
            system("cls");

            cout<<"Sei veramente sicuro di eliminare i dati?" 
                <<" Una volta fatto non sara' possibile"
                <<" recuperarli\n\nDigitare S per si oppure N per no: ";
            
            cin>>scelta;

            scelta = toupper(scelta);

            if(scelta != 'S' && scelta != 'N') errore = true;

            else if(scelta == 'S') return true;

            else scelta = '\0';
        }

    } while(errore || scelta == '\0');

    return false;
}

//caricamento da file dei dati
bool carica(Fantacalcio &fanta)
{
    system("cls");

    ifstream file("crediti.txt");
    
    if(!file.is_open() || file.peek() == ifstream::traits_type::eof()) return false;

    if(eliminazioneSalvataggi()) return false;

    system("cls");

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