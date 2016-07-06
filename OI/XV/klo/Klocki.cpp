#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

typedef long long int LType;
typedef multiset<LType>::iterator iter;
const int ROZMIAR = 110000;
LType ile, dlMedian, mediana, sumPonizej, sumPowyzej;
LType tab[ROZMIAR];
LType wynik = -1, indKon, minMedian;
multiset<LType> ponizej, powyzej;

void dodaj(int ind) {
    if(tab[ind] <= mediana) {
        sumPonizej += tab[ind];
        ponizej.insert(tab[ind]);
    }else {
        sumPowyzej += tab[ind];
        powyzej.insert(tab[ind]);
    }
}

void usun(int ind) {
    if(tab[ind] == mediana) {
        mediana = *powyzej.begin();
        sumPowyzej -= *powyzej.begin();
        powyzej.erase(powyzej.begin());
    }else if(tab[ind] < mediana) {
        sumPonizej -= tab[ind];
        ponizej.erase(ponizej.find(tab[ind]));
    }else {
        sumPowyzej -= tab[ind];
        powyzej.erase(powyzej.find((tab[ind])));
    }
}

void ustalMediane() {
    if(ponizej.size() > powyzej.size()) {
        sumPowyzej += mediana;
        powyzej.insert(mediana);
        iter it = ponizej.end();
        it--;
        mediana = *it;
        sumPonizej -= *it;
        ponizej.erase(it);
    }else if(powyzej.size() > ponizej.size()) {
        sumPonizej += mediana;
        ponizej.insert(mediana);
        mediana = *powyzej.begin();
        sumPowyzej -= *powyzej.begin();
        powyzej.erase(powyzej.begin());
    }
}

void wypisz(multiset<LType> multi) {
    iter it = multi.begin();
    while(it != multi.end()) {
        printf("%lld ",*it);
        it++;
    }
}

int main() {
    scanf("%lld%lld", &ile, &dlMedian);
    for(int i = 0; i < ile; i++) {
        scanf("%lld", &tab[i]);
    }
    mediana = minMedian = tab[0];
    if(dlMedian > 1) {
        for(int i = 1; i < ile; i++) {
            dodaj(i);
            ustalMediane();
            if(i >= dlMedian) usun(i - dlMedian);
            ustalMediane();
            if(i >= dlMedian - 1 && (mediana * ponizej.size() - sumPonizej + sumPowyzej - mediana * powyzej.size() < wynik || wynik == -1)) {
                wynik = mediana * ponizej.size() - sumPonizej + sumPowyzej - mediana * powyzej.size();
                indKon = i;
                minMedian = mediana;
            }
        }
    }
    printf("%lld\n",dlMedian == 1 ? 0 : wynik);
    for(int i = 0; i < ile; i++) {
        if(i < indKon - dlMedian + 1 || i > indKon) {
            printf("%lld\n",tab[i]);
        }else {
            printf("%lld\n",minMedian);
        }
    }
    return 0;
}
