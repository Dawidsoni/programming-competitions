#include<algorithm>
using namespace std;

class punkt {
public:
    bool czy_pocz;
    int war;
    friend bool operator < (const punkt & p1, const punkt & p2) {
        if(p1.war < p2.war) return true;
        return false;
    }
};


const int rozmiar = 500000;
punkt przedz[rozmiar*2];
int ile_pun = 0;
int ile, wys_doj, tab[rozmiar];
int drzewo[rozmiar * 2];
bool czy_dodac = true;


void dodaj_elem(int poz) {
    poz += rozmiar;
    drzewo[poz] = 1;
    while(poz > 1) {
        poz /= 2;
        drzewo[poz] = drzewo[poz * 2] + drzewo[poz * 2 + 1];
    }
}

void inicjuj(int n, int k, int *D)
{
    ile = n;
    wys_doj = k;
    for (int i = 0; i < n; ++i) {
        tab[i] = D[i];
        if(tab[i] >= wys_doj) dodaj_elem(i);
    }
}

void podlej(int a, int b)
{
    czy_dodac = true;
    przedz[ile_pun].czy_pocz = true;
    przedz[ile_pun].war = a;
    ile_pun++;
    przedz[ile_pun].czy_pocz = false;
    przedz[ile_pun].war = b + 1;
    ile_pun++;
}

int dojrzale(int od_kad, int do_kad)
{
    if(czy_dodac) {
//        printf("to: %d",ile_pun);
        sort(przedz, przedz + ile_pun);
        int od_kad = 0, ile_dodac = 0;
        for(int i = 0; i < ile; i++) {
            while(od_kad < ile_pun &&przedz[od_kad].war == i) {
                if(przedz[od_kad].czy_pocz) ile_dodac++;
                else ile_dodac--;
                od_kad++;
            }
            tab[i] += ile_dodac;
            if(tab[i] >= wys_doj) dodaj_elem(i);
        }
        ile_pun = 0;
    }
    od_kad += rozmiar;
    do_kad += rozmiar;
    int wynik = drzewo[od_kad];
    if(od_kad != do_kad) wynik += drzewo[do_kad];
    while(od_kad/2 < do_kad/2) {
        if(od_kad % 2 == 0) wynik += drzewo[od_kad + 1];
        if(do_kad % 2 == 1) wynik += drzewo[do_kad - 1];
        od_kad /= 2;
        do_kad /= 2;
    }
    czy_dodac = false;
    return wynik;
}
