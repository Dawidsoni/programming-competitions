#include<stdio.h>
#include<vector>
using namespace std;

int ile, wczyt, wynik;
vector<int> wektor;

int zmienWyn(vector<int> wek, int el1, int el2) {
    swap(wek[el1],wek[el2]);
    int aktWyn = 1, maxWyn = 1;
    for(int i = 1; i < ile; i++) {
        if(wek[i] > wek[i - 1]) {
            aktWyn++;
            maxWyn = max(maxWyn, aktWyn);
        }else aktWyn = 1;
    }
    return maxWyn;
}

int main() {
    scanf("%d", &ile);
    for(int i = 0; i < ile; i++) {
        scanf("%d", &wczyt);
        wektor.push_back(wczyt);
    }
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            if(i != ii) {
                wynik = max(wynik, zmienWyn(wektor, i,ii));
            }
        }
    }
    printf("%d",wynik);
}
