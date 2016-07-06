#include<stdio.h>
#include<set>
using namespace std;

class Licz2 {
public:
    Licz2() {}
    Licz2(int l1, int l2) : a(l1), b(l2), wyn(0) {}
    int a,b;
    mutable int wyn;
    friend bool operator < (const Licz2 & ob1, const Licz2 & ob2) {
        if(ob1.a > ob2.a) return true;
        if(ob1.a < ob2.a) return false;
        if(ob1.b > ob2.b) return true;
        return false;
    }
};

typedef set<Licz2>::iterator iter;
const int ROZ = 310000;
int tab[3][ROZ];
int ile, licz;
set<Licz2> zbior;
int wyn;

int main() {
    scanf("%d", &ile);
    for(int i = 0; i < 3; i++) {
        for(int ii = 1; ii <= ile; ii++) {
            scanf("%d", &licz);
            tab[i][licz] = ii;
        }
    }
    for(int ii = 1; ii <= ile; ii++) {

        int a = tab[1][ii] - tab[0][ii];
        int b = tab[2][ii] - tab[1][ii];
        if(a < 0) a = ile + a;
        if(b < 0) b = ile + b;
        Licz2 obj(a,b);
        iter it = zbior.find(obj);
        if(it==zbior.end()) {
            zbior.insert(obj);
        }else {
            it->wyn++;
        }
    }
    for(iter it = zbior.begin(); it != zbior.end(); it++) {
        if(it->wyn > wyn) wyn = it->wyn;
    }
    printf("%d",wyn + 1);
    return 0;
}
