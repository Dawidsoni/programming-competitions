#include<stdio.h>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int ile;
vector<int> wierz[350000];
bool czy_byl[350000];
long long int wynik = INT_MAX, wcz1, wcz2;

void rekur(int num_w,long long int & zapas,long long int l_ekip) {
    czy_byl[num_w] = true;
    int ile_s = 0;
    for(int i = 0; i < wierz[num_w].size();i++) {
        if(czy_byl[wierz[num_w][i]] == false) ile_s++;
    }
    long long int war = zapas + (l_ekip - ile_s);
    for(int i = 0; i < wierz[num_w].size();i++) {
        if(czy_byl[wierz[num_w][i]] == false) {
            rekur(wierz[num_w][i], war, l_ekip);
        }
        if(war < zapas) zapas = war;
    }
}


bool czy_da_sie(int l_ekip) { //umieszczam, jeœli muszê, a reszta mi zostaje
    long long int zapas = 0;
    for(int i = 1; i <= ile; i++) {
        czy_byl[i] = false;
    }
    rekur(1,zapas,l_ekip);
    if(zapas < 0 ) return false;
    else return true;
}


int main() {
    scanf("%d", &ile);
    for(int i = 0; i + 1 < ile;i++) {
        scanf("%d%d", &wcz1, &wcz2);
        wierz[wcz1].push_back(wcz2);
        wierz[wcz2].push_back(wcz1);
    }
    int od_kad = 0;
    int do_kad = ile;
    bool czy_koniec = false;
    while(true) {
        if(do_kad == od_kad) czy_koniec = true;
        int srednia = (od_kad + do_kad)/2;

        if(czy_da_sie(srednia)) {
            do_kad = srednia;
            wynik = srednia;
        }else {
            od_kad = srednia + 1;

        }
        if(czy_koniec) break;
    }
    printf("%d",wynik);
    return 0;
}
