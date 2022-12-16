
// Descompunearea unui numar natural in factori primi folosind o stiva sau o coada

#include <iostream>
using namespace std;

struct numar
{
    int v; // Variabila care retine valoarea din lista
    numar *urm; // Legatura catre urmatorul element din losta
};
// --- Functiile pentru stiva ---
void afisare_stiva(numar *cap, int nrDiv)
{
    numar *c;
    if (cap == NULL)
        cout<<"Stiva este goala"<<endl;
    else
    {
        cout<<"Afisare stiva cu factorii primi ai numarului introdus: "<<endl;
        c=cap;
        for(int i = 0; i < nrDiv; i++)
        {
            if(c != NULL)
            {
                cout<<'\t'<<c->v<<endl;
                c=c->urm;
            }
        }
    }
}

numar *adaugare_in_stiva(numar *x, int a)
{
    numar *aux;
    aux = new numar;
    aux->v = a;
    aux->urm = x;
    x = aux; // noul capat al stivei
    return x;
}

// --- Functiile pentru coada ---
// Functia de adaugare a unui numar intr-o coada
void adaugare_in_coada(numar *&prim, numar *&ultim, int v)
{
    numar *nou = new numar;
    nou->v = v;
    nou->urm = NULL;
    if (prim == NULL)
    {
        prim = nou;
    }
    else
    {
        ultim->urm = nou;
    }
    ultim = nou;
}
/* Am o coada care este reprezentata de doua pointeri: unul catre primul element (prim) si unul catre ultimul element (ultim).
   Functia adaugare_in_coada primeste ca parametrii acesti doi pointeri, impreuna cu valoarea numarului care urmeaza sa fie adaugat in coada.
   Daca coada este goala (adica prim este NULL), atunci primul element al cozii va fi noul numar creat. Daca coada nu este goala,
   ultimul element al cozii va fi legat de noul numar creat. In final, pointerul ultim este setat sa pointeze catre noul numar,
   astfel incat acesta sa devina ultimul element al cozii.
 */

void afiseaza_coada(numar *prim)
{
    numar *curent = prim;
    while (curent != NULL)
    {
        cout << curent->v << " ";
        curent = curent->urm;
    }
    cout << endl;
}

/*
    Parcurgem coada element cu element, incepand de la primul element (indicat de pointerul prim).
    Afisam valoarea fiecarui element si apoi avansam pointerul curent la urmatorul element al cozii.
    Aceasta se repeta pana cand pointerul curent devine NULL, ceea ce inseamna ca am parcurs intreaga coada.
*/

int main()
{
    int nr, nr_divizori = 0;

    int optiune;
    cout<<"1. Descompunerea in factori primi folosind o stiva"<<endl;
    cout<<"2. Descompunerea in factori primi folosind o coada"<<endl;
    cout<<"0. Inchidere program"<<endl;
    cout<<"[!] Selecteaza optiunea dorita: ";
    cin>>optiune;
    switch(optiune)
    {
    case 1:
    {
        numar *stiva;

        cout<<"Introduceti numarul: ";
        cin>>nr;

        for(int i = 2; nr > 1; i++)
        {
            while( nr % i == 0 )
            {
                nr = nr / i;
                stiva = adaugare_in_stiva(stiva, i);
                nr_divizori ++;
            }

        }
        afisare_stiva(stiva, nr_divizori);

        break;
    }

    case 2:
    {
        numar *primul = NULL;
        numar *ultimul = NULL;

        cout<<"Introduceti numarul: ";
        cin>>nr;

        for(int i = 2; nr > 1; i++)
        {
            while( nr % i == 0 )
            {
                nr = nr / i;
                adaugare_in_coada(primul, ultimul, i);
                nr_divizori ++;
            }
        }
        afiseaza_coada(primul);
        break;
    }

    default:

        break;
    }
    
    return 0;
}
