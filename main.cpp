#include <iostream>
#include<cstring>

using namespace std;


// 1. O functie care sa sorteze alfabetic un sir de caractere folosind unul dintre algoritmii studiati.
//De exemplu, din sirul "d, z, e, c, a" sa rezulte "a, c, d, e, z"


void ordonare_sir_de_caractere()
{
    int n;
    cout<<"Dimensiune sir de caractere: ";
    cin>>n;
    char* c = new char[n];

    cout<<"Sir de caractere: ";

    for(int i=0; i<n; i++)
        cin>>c[i];


    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
        {
            if(c[i]>c[j])
            {
                char aux = c[i];
                c[i]=c[j];
                c[j]=aux;
            }
        }
    cout<<"Sir ordonat: ";
    for(int i=0; i<n; i++)
        cout<<c[i];
    cout<<endl;

}

//  2. O functie care sa sorteze alfabetic un sir de cuvinte folosind unul dintre algoritmii studiati.
//De exemplu, din sirul "carte, zid, arta, casa, argon" sa rezulte "argon, arta, carte, casa, zid".

void ordonare_sir_de_cuvinte()
{
    int n;
    cout<<"Numar cuvinte: ";
    cin>>n;

    string* cuv= new string[n];

    cout<<"Sir cuvinte: ";
    for(int i=0; i<n; i++)
        cin>>cuv[i];

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
        {
            if (cuv[i]>cuv[j])
                swap(cuv[i],cuv[j]);
        }

    cout<<"Sir de cuvinte sortat: ";
    for(int i=0; i<n; i++)
        cout<<cuv[i]<<" ";

    cout<<endl;

}


// 3. O functie care sa sorteze crescator un sir de numere intregi folosind algoritmul Radix


struct coada
{
    int v[100];   //tabloul in care stocam elem cozii
    int prim, ultim;   //prim - iese , ultim - se insereaza
};

void init(coada &c)
{
    c.prim=0;
    c.ultim=-1; //ca sa ramana nula
}

bool verif_null(coada c)
{
    return c.prim > c.ultim;
}

void push(coada& c, int x)
{
    c.v[++c.ultim]=x;
}

int pop(coada&c)
{
    return c.v[c.prim++]; //muta capul cozii
}

void Radix_cu_cozi()
{
    coada q[10];
    int a[100],n;

    cout<<"Numar elemente: ";
    cin>>n;
    cout<<endl;
    cout<<"Elemente: "<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];


//det max

    int m=a[0];

    for(int i=1; i<n; i++)
        if(m<a[i])
            m=a[i];

//parcurgere cifre

    for(int exp =1; m/exp>0; exp*=10)
    {

        //init cozile

        for(int i=0; i<10; i++)
            init(q[i]);

        for(int i=0; i<n; i++)
        {
            int cifra=(a[i]/exp)%10;
            push(q[cifra],a[i]);
        }

        // ->inapoi in tablou

        int k=0;
        for(int i=0; i<10; i++)
        {
            while(!verif_null(q[i]))
            {
                a[k++]=pop(q[i]);
            }
        }
    }

    cout<<"Sortare: ";

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    cout<<endl;
}



// 4.O functie care sa interclasese n liste simplu sau dublu inlantuite intr-o lista simplu sau dublu inlantuita.

struct Nod
{
    int info;
    Nod* next;
};

/*struct Nod{   //dubla
int info;
Nod* next;
Nod* prev;
}; */


void cit_lsimpla(Nod*& cap)
{
    cout<<"citire lista: ";
    cap=nullptr;
    Nod* ultim = nullptr;

    int x;
    cin>>x;

    while(x!=-1)
    {

        Nod* nou= new Nod;
        nou->info=x;
        nou->next=nullptr;

        if(cap==nullptr)
        {
            cap=nou;
            ultim=nou;
        }

        else
        {
            ultim->next=nou;
            ultim=nou;
        }
        cin>>x;
    }


}

void afisare(Nod* cap)
{
    Nod* p =cap; //p parcurge lista
    cout<<endl;
    cout<<"Afisare lista: ";
    while(p!=nullptr)
    {
        cout<<p->info<<" ";
        p=p->next;
    }

    cout<<endl;
}

Nod* interclasare(Nod* a, Nod*b)
{
    if(!a) return b;
    if(!b) return a;

    Nod* rezultat;

    if(a->info<b->info)
    {
        rezultat=a;
        rezultat->next=interclasare(a->next,b);
    }

    else
    {
        rezultat=b;
        rezultat->next=interclasare(a,b->next);
    }

    return rezultat;
}

Nod* interclasare_n(Nod* liste[],int n)
{
    if(n==0)
        return nullptr;

    Nod* rezultat= liste[0];

    for(int i=1; i<n; i++)
    {
        rezultat=interclasare(rezultat,liste[i]);
    }

    return rezultat;
}

void ex4()
{
    int n;
    cout<<"Nr liste: ";
    cin>>n;

    Nod* liste[n];

    for(int i=0; i<n; i++)
    {
        liste[i]=nullptr;
        cit_lsimpla(liste[i]);
    }


    /* for(int i=0;i<n;i++){
             cout<<"lista "<<i+1<<" ";
     afisare(liste[i]);
     } */

    cout<<endl;
    cout<<"Lista interclasata: ";
    afisare(interclasare_n(liste,n));
    cout<<endl;

}


// 5.  O functie care sa creeze o lista circulara simplu sau dublu inlantuita si
//implemnentati  operatii de adaugare, stregere, modificare si parcurgere  in lista circulara.

struct NodC
{
    int info;
    NodC* next;
};

void creare_lista_circulara(NodC*& cap)
{
    cap = nullptr;
    NodC* ultim = nullptr;

    int x;
    cout << "Introdu elemente (-1 pentru stop): ";
    cin >> x;

    while (x != -1)
    {
        NodC* nou = new NodC;
        nou->info = x;

        if (cap == nullptr)
        {
            cap = nou;
            nou->next = cap;
            ultim = nou;
        }
        else
        {
            ultim->next = nou;
            nou->next = cap;
            ultim = nou;
        }
        cin >> x;
    }
}
void afisare_circulara(NodC* cap)
{
    if (!cap)
    {
        cout << "Lista vida\n";
        return;
    }

    NodC* p = cap;
    cout << "Lista circulara: ";
    do
    {
        cout << p->info << " ";
        p = p->next;
    }
    while (p != cap);
    cout << endl;
}

void adaugare_circulara(NodC*& cap, int x)
{
    NodC* nou = new NodC;
    nou->info = x;

    if (!cap)
    {
        cap = nou;
        nou->next = cap;
        return;
    }

    NodC* p = cap;
    while (p->next != cap)
        p = p->next;

    p->next = nou;
    nou->next = cap;
}

void stergere_circulara(NodC*& cap, int x)
{
    if (!cap) return;

    NodC* p = cap;
    NodC* ant = nullptr;

    do
    {
        if (p->info == x)
        {
            if (p == cap)
            {
                NodC* ultim = cap;
                while (ultim->next != cap)
                    ultim = ultim->next;

                if (cap->next == cap)
                {
                    delete cap;
                    cap = nullptr;
                }
                else
                {
                    cap = cap->next;
                    ultim->next = cap;
                    delete p;
                }
            }
            else
            {
                ant->next = p->next;
                delete p;
            }
            return;
        }
        ant = p;
        p = p->next;
    }
    while (p != cap);
}

void modificare_circulara(NodC* cap, int vechi, int nou)
{
    if (!cap) return;

    NodC* p = cap;
    do
    {
        if (p->info == vechi)
        {
            p->info = nou;
            return;
        }
        p = p->next;
    }
    while (p != cap);
}

void ex5()
{
    NodC* cap = nullptr;
    int opt, x, y;

    do
    {
        cout << "\n1. Creare lista\n2. Afisare\n3. Adaugare\n4. Stergere\n5. Modificare\n0. Inapoi\n";
        cin >> opt;

        switch (opt)
        {
        case 1:
            creare_lista_circulara(cap);
            break;
        case 2:
            afisare_circulara(cap);
            break;
        case 3:
            cout << "Valoare de adaugat: ";
            cin >> x;
            adaugare_circulara(cap, x);
            break;
        case 4:
            cout << "Valoare de sters: ";
            cin >> x;
            stergere_circulara(cap, x);
            break;
        case 5:
            cout << "Valoare veche si noua: ";
            cin >> x >> y;
            modificare_circulara(cap, x, y);
            break;
        }
    }
    while (opt != 0);
}

//6. Scrieti o functie care sa determine reuninea si intersectia a doua  multimi descrise prin liste dinamice.
// folosim struct Nod deja definit

void inserare_ordonata(Nod*& cap, int x)
{
    Nod* nou = new Nod;
    nou->info = x;
    nou->next = nullptr;

    if (!cap || x < cap->info)
    {
        nou->next = cap;
        cap = nou;
        return;
    }

    Nod* p = cap;
    while (p->next && p->next->info < x)
        p = p->next;

    if (p->info == x || (p->next && p->next->info == x))
        return;

    nou->next = p->next;
    p->next = nou;
}

Nod* reuniune(Nod* a, Nod* b)
{
    Nod* r = nullptr;

    while (a)
    {
        inserare_ordonata(r, a->info);
        a = a->next;
    }
    while (b)
    {
        inserare_ordonata(r, b->info);
        b = b->next;
    }
    return r;
}

Nod* intersectie(Nod* a, Nod* b)
{
    Nod* r = nullptr;

    while (a && b)
    {
        if (a->info < b->info)
            a = a->next;
        else if (a->info > b->info)
            b = b->next;
        else
        {
            inserare_ordonata(r, a->info);
            a = a->next;
            b = b->next;
        }
    }
    return r;
}

void ex6()
{
    Nod *a = nullptr, *b = nullptr;

    cout << "Multimea A:\n";
    cit_lsimpla(a);
    cout << "Multimea B:\n";
    cit_lsimpla(b);

    cout << "Reuniune: ";
    afisare(reuniune(a, b));

    cout << "Intersectie: ";
    afisare(intersectie(a, b));
}

//7. Arbori binari: reprezentare, parcurgere.
struct NodArb
{
    int info;
    NodArb* st;
    NodArb* dr;
};

NodArb* nod[1001];
bool copil[1001];


void init() {
    for (int i = 0; i < 1001; i++) {
        nod[i] = nullptr;
        copil[i] = false;
    }
}

NodArb* get(int x) {
    if (!nod[x]) {
        nod[x] = new NodArb;
        nod[x]->info = x;
        nod[x]->st = nod[x]->dr = nullptr;
    }
    return nod[x];
}


NodArb* construire(int n) {
    init();

    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;

        NodArb* par = get(p);
        NodArb* cop = get(c);

        if (!par->st) par->st = cop;
        else par->dr = cop;

        copil[c] = true;
    }

    for (int i = 1; i <= 1000; i++)
        if (nod[i] && !copil[i])
            return nod[i];

    return nullptr;
}


void RSD(NodArb* r) {
    if (!r) return;
    cout << r->info << " ";
    RSD(r->st);
    RSD(r->dr);
}

void SRD(NodArb* r) {
    if (!r) return;
    SRD(r->st);
    cout << r->info << " ";
    SRD(r->dr);
}

void SDR(NodArb* r) {
    if (!r) return;
    SDR(r->st);
    SDR(r->dr);
    cout << r->info << " ";
}

void ex7() {
    int n;
    cout << "Numar perechi (parinte copil): ";
    cin >> n;

    NodArb* r = construire(n);

    cout << "\nRSD: ";
    RSD(r);

    cout << "\nSRD: ";
    SRD(r);

    cout << "\nSDR: ";
    SDR(r);

    cout << endl;
}


//8.  Arbori binari de cautare: creare, inserare, stergere, modificare nod.
NodArb* inserare_abc(NodArb* r, int x) {
    if (!r) {
        NodArb* nou = new NodArb;
        nou->info = x;
        nou->st = nou->dr = nullptr;
        return nou;
    }

    if (x < r->info)
        r->st = inserare_abc(r->st, x);
    else if (x > r->info)
        r->dr = inserare_abc(r->dr, x);

    return r;
}

NodArb* minim(NodArb* r) {
    while (r && r->st)
        r = r->st;
    return r;
}

NodArb* stergere_abc(NodArb* r, int x) {
    if (!r) return r;

    if (x < r->info)
        r->st = stergere_abc(r->st, x);
    else if (x > r->info)
        r->dr = stergere_abc(r->dr, x);
    else {
        if (!r->st) {
            NodArb* temp = r->dr;
            delete r;
            return temp;
        }
        if (!r->dr) {
            NodArb* temp = r->st;
            delete r;
            return temp;
        }

        NodArb* temp = minim(r->dr);
        r->info = temp->info;
        r->dr = stergere_abc(r->dr, temp->info);
    }
    return r;
}

void modificare_abc(NodArb*& r, int vechi, int nou) {
    r = stergere_abc(r, vechi);
    r = inserare_abc(r, nou);
}


void ex8() {
    NodArb* r = nullptr;
    int n, x, opt, y;

    cout << "Numar noduri: ";
    cin >> n;

    cout << "Valori: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        r = inserare_abc(r, x);
    }

    do {
        cout << "\n1. Afisare SRD (ordonat)\n2. Inserare\n3. Stergere\n4. Modificare\n0. Inapoi\n";
        cin >> opt;

        switch (opt) {
        case 1:
            SRD(r);
            cout << endl;
            break;

        case 2:
            cout << "Valoare: ";
            cin >> x;
            r = inserare_abc(r, x);
            break;

        case 3:
            cout << "Valoare de sters: ";
            cin >> x;
            r = stergere_abc(r, x);
            break;

        case 4:
            cout << "Valoare veche si noua: ";
            cin >> x >> y;
            modificare_abc(r, x, y);
            break;
        }
    } while (opt != 0);
}


int main()
{
    int optiune=1;

    do
    {
        cout << "PROIECT-ASD, ILIESCU DARIA:" << endl<<endl;
        cout << " 1. Ordonare sir de caractere" << endl;
        cout << " 2. Ordonare sir de cuvinte" << endl;
        cout << " 3. Algoritmul Radix pentru numere intregi" <<endl;
        cout << " 4. Interclasarea a n liste simplu inlantuite " << endl;
        cout << " 5. Lista circulara si operatii in lista circulara. " << endl;
        cout << " 6. Reuniune si intersectie de multimi descrise prin liste dinamice. " << endl;
        cout << " 7. Arbori binari: reprezentare, parcurgere." <<endl;
        cout << " 8.  Arbori binari de cautare: creare,inserare, stergere, modificare nod." << endl;
        cout << "0. Terminare program" << endl;
        cout<<endl;
        cout << "Scrieti optiune: ";
        cin>>optiune;

        switch (optiune)
        {
        case 1:
            ordonare_sir_de_caractere();
            cout<<endl;
            break;

        case 2:
            ordonare_sir_de_cuvinte();
            cout<<endl;
            break;

        case 3:
            Radix_cu_cozi();
            cout<<endl;
            break;

        case 4:
            ex4();
            cout<<endl;
            break;

        case 5:
            ex5();
            cout << endl;
            break;
        case 6:
            ex6();
            cout<<endl;
            break;
        case 7:
            ex7();
            cout<<endl;
            break;
        case 8:
            ex8();
            cout<<endl;
            break;

        case 0:
            cout << "La revedere!" << endl;
            break;

        default:
            cout << "Optiune invalida!" << endl<<endl;
        } // end switch
    }
    while(optiune!=0);   // end pentru do


    cout << "" << endl;
    return 0;
}
