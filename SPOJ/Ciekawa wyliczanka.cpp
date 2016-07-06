#include<stdio.h>
using namespace std;

int wynik[1000], ile_wynik;
typedef long long int long_type;
long_type ktora_liczba;

int main() {
    scanf("%lld", &ktora_liczba);
    for(long_type ile_podziel = 2;ktora_liczba>0; ile_podziel *= 2) {
        long_type reszta = ktora_liczba%ile_podziel;
        if(reszta == 0) reszta = ile_podziel;
        if(reszta<=ile_podziel / 2) {
            wynik[ile_wynik++] = 5;
        }else {
            wynik[ile_wynik++] = 6;
        }
        ktora_liczba -= ile_podziel;
    }
    for(int i= ile_wynik - 1;i>=0; i--) {
        printf("%d", wynik[i]);
    }
    return 0;
}
