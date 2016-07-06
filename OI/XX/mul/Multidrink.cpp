#include<stdio.h>
#include<vector>
using namespace std;

enum rodzaj {bialy,lacznik,sciezka};

class kopiec {
public:
    vector<kopiec*> polacz;
    bool czy_jest, czy_sciezka;
    int numer;
    static int licznik;
    kopiec() : czy_jest(true), czy_sciezka(false) {numer = licznik++;}
    operator int() {
        return numer;
    }
    void dodaj_polaczenie(kopiec * ktory) {
        polacz.push_back(ktory);
    }
};

int kopiec::licznik = 0;

kopiec graf[500001];
int wynik[500000];
int n, wcz1, wcz2, hierarchia = 100, ile = 0;
kopiec * wsk = &graf[1], * nastepny = NULL;
bool czy_mozna = true;

void ustaw_sciezke(kopiec & punkt,kopiec & ktory_nie) {
    static bool czy_rek = true;
    if(punkt==n)  czy_rek = false;
    if(czy_rek) {
        for(int i=0;i<punkt.polacz.size();i++) {
            if(*punkt.polacz[i]!=ktory_nie&&czy_rek)
                ustaw_sciezke(*punkt.polacz[i],punkt);
        }
    }
    if(!czy_rek) {
        punkt.czy_sciezka = true;
    }
}

rodzaj jaki_rodzaj(kopiec & punkt) {
    if(punkt.czy_sciezka) return sciezka;
    if(punkt.polacz.size()>2) return lacznik;
    return bialy;
}

int ust_hierar_przez(kopiec & punkt, kopiec & przez) {
    rodzaj r_przez = jaki_rodzaj(przez), r_punkt = jaki_rodzaj(punkt);
    if(punkt==n) return 10;
    if(r_przez!=sciezka&&r_punkt!=sciezka&&punkt.polacz.size()<2) return 1;
    if(r_przez!=sciezka&&r_punkt!=sciezka) return 3;
    if(r_punkt!=sciezka&&punkt.polacz.size()<2) return 6;
    if(r_punkt!=sciezka) return 7;
    return 9;
}

int ust_hierar(kopiec & punkt, kopiec & zrodlo) {
    rodzaj r_punkt = jaki_rodzaj(punkt);
    if(punkt==n) return 10;
    if(r_punkt!=sciezka&&punkt.polacz.size()<2&&zrodlo.polacz.size()<3) return 2;
    if(r_punkt!=sciezka&&punkt.polacz.size()<2) return 4;
    if(r_punkt!=sciezka) return 5;
    return 8;
}


int main() {
    scanf("%d",&n);
    for(int i=0;i+1<n;i++) {
        scanf("%d%d",&wcz1,&wcz2);
        graf[wcz1].dodaj_polaczenie(&graf[wcz2]);
        graf[wcz2].dodaj_polaczenie(&graf[wcz1]);
    }
    ustaw_sciezke(graf[1],graf[0]);
    //graf[n].czy_sciezka = graf[1].czy_sciezka = false;
    for(;;ile++) {
        wynik[ile] = *wsk;
        wsk->czy_jest = false;
        hierarchia = 100;
        nastepny = NULL;
        for(vector<kopiec*>::iterator it = wsk->polacz.begin();it!= wsk->polacz.end();it++) {
            for(vector<kopiec*>::iterator it2 = (*it)->polacz.begin(); it2!=(*it)->polacz.end();it2++){
                if((*it2)->czy_jest==false) continue;
                    int hier = ust_hierar_przez(*(*it2),*(*it));
                    if(hier<hierarchia) {
                        hierarchia = hier;
                        nastepny = *it2;
                    }
            }
            if((*it)->czy_jest==false) continue;
            int hier = ust_hierar(*(*it),*wsk);
            if(hier<hierarchia) {
                hierarchia = hier;
                nastepny = *it;
            }
        }
        if(nastepny==NULL) {
            czy_mozna =false;
            break;
        }
        else if(ile+2==n&&(*nastepny==n)) {
            break;
        }
        else if((hierarchia==10)||ile==n) {
            czy_mozna = false;
            break;
        }
        wsk = nastepny;
    }
    if(czy_mozna) {
        for(int i=0;i-1<ile;i++) {
            printf("%d\n",wynik[i]);
        }
        printf("%d\n",n);
    }else {
        printf("BRAK\n");
    }
    return 0;
}
