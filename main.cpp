#include <iostream>
#include "class_allenatore/allenatore.h"
#include "class_giocatore/giocatore.h"

using namespace std;

int main()
{
    Allenatore a("mattia",1000);

    a.operazione(new Giocatore("Immobile",100,'A'));
    a.operazione(new Giocatore("Lukaku",100,'A'));

    cout<<a;

    cout<<"\n\nFine";

    return 0;
}