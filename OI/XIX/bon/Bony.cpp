#include<stdio.h>
#include<algorithm>
using namespace std;

const int stala = 1000100;
bool czy_bon[stala];
int ost_bon[stala];
bool czy_byl[stala];
long long int wynik[stala];
long long int ile_wynik;
int ile_dni;
int dzien;
long long int ile_bonow;
long long int ktory_klient = 1;

void zrob() {
    int paczka = ost_bon[dzien];
    int licznik = 0;
    long long int kopia = ktory_klient;
    kopia += dzien;
    while(true) {
        paczka += dzien;
        if(paczka > (stala - 10)) {
            ost_bon[dzien] = stala;
            break;
        }
        if(licznik >= dzien) break;
        if(czy_byl[paczka] == true) continue;
        ost_bon[dzien] = paczka;
        czy_byl[paczka] = true;
        licznik++;
        if(czy_bon[paczka]) {
            wynik[ile_wynik++] = ktory_klient;
        }
        ktory_klient++;
    }
    ktory_klient = kopia;
}

int wczytaj;

int main() {
    scanf("%d", &ile_bonow);
    for(int i=0;i<ile_bonow;i++) {
        scanf("%d", &wczytaj);
        czy_bon[wczytaj] = true;
    }
    scanf("%d", &ile_dni);
    for(int i=0;i<ile_dni;i++) {
        scanf("%d", &dzien);
        zrob();
    }
   // printf("%d %d", ost_bon[2], ost_bon[4]);
    printf("%lld\n", ile_wynik);
    for(int i=0;i<ile_wynik;i++) {
        printf("%lld\n",wynik[i]);
    }
    return 0;
}
