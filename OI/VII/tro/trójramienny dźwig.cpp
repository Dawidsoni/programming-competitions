#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX_SIZE = 510000;

class Wynik {
public:
    int a, b, c;
    Wynik() {}
    Wynik(int a_, int b_, int c_) : a(a_), b(b_), c(c_) {}
};

int p, q, ile;
bool czyByl[MAX_SIZE], czyZmien;
vector<Wynik> wynik;

int main() {
    scanf("%d%d%d", &p, &q, &ile);
    if(p > q) swap(p, q);
    for(int i = 1; i <= ile; i++) {
        if(czyByl[i]) continue;
        if(czyByl[i + p]) {
            swap(p, q);
            czyZmien = true;
        }
        wynik.push_back(Wynik(i, i + p, i + p + q));
        czyByl[i] = czyByl[i + p] = czyByl[i + p + q] = true;
        if(czyZmien) {
            swap(p, q);
            czyZmien = false;
        }
    }
    printf("%d\n", wynik.size());
    for(int i = 0; i < wynik.size(); i++) {
        printf("%d %d %d\n", wynik[i].a, wynik[i].b, wynik[i].c);
    }
    return 0;
}
