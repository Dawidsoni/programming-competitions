#include<stdio.h>
#include<algorithm>
using namespace std;

class punkt {
public:
    int x, y, numer;
    punkt(int x_,int y_, int num) : x(x_), y(y_), numer(num) {}
    punkt() {}
};

class oper_x {
public:
    bool operator()(const punkt & p1, const punkt & p2) {
        if(p1.x < p2.x) return true;
        return false;
    }
};

class oper_y {
public:
    bool operator()(const punkt & p1, const punkt & p2) {
        if(p1.y < p2.y) return true;
        return false;
    }
};



punkt wedlug_x[50000];
punkt wedlug_y[50000];
int ile_pocz_x, ile_w_x, ile_pocz_y, ile_w_y;
bool czy_juz_bylo[50000];
int n_testow, ile_troj, wcz_x, wcz_y;

void rob_wynik() {
    while(true) {
        int wynik[3];
        for(;czy_juz_bylo[wedlug_x[ile_pocz_x].numer] && ile_pocz_x<ile_w_x;ile_pocz_x++) {}
        for(;czy_juz_bylo[wedlug_y[ile_pocz_y].numer] && ile_pocz_y<ile_w_y;ile_pocz_y++) {}
        for(;czy_juz_bylo[wedlug_x[ile_w_x].numer] && ile_pocz_x<ile_w_x;ile_w_x--) {}
        for(;czy_juz_bylo[wedlug_y[ile_w_y].numer] && ile_pocz_y<ile_w_y;ile_w_y--) {}
        if(ile_pocz_x>=ile_w_x||ile_pocz_y>=ile_w_y) {
            break;
        }
        int num1 = wedlug_x[ile_pocz_x].numer, num2 = wedlug_x[ile_w_x].numer;
        int num3 = wedlug_y[ile_pocz_y].numer, num4 = wedlug_y[ile_w_y].numer;
        wynik[0] = num1;
        wynik[1] = num2;
        if(num1==num3||num2==num3) {
            wynik[2] = num4;
        }else {
            wynik[2] = num3;
        }
        sort(wynik, wynik + 3);
        for(int i=0;i<3;i++) {
            printf("%d ", wynik[i]);
            czy_juz_bylo[wynik[i]] = true;
        }
        printf("\n");
    }

}

int main() {
    scanf("%d", &n_testow);
    for(int i=0;i<n_testow;i++) {
        scanf("%d", &ile_troj);
        ile_w_x = ile_w_y = ile_pocz_x = ile_pocz_y = 0;
        for(int i=0;i<ile_troj;i++) {
            scanf("%d %d", &wcz_x, &wcz_y);
            wedlug_x[ile_w_x++] = punkt(wcz_x, wcz_y, i + 1);
            wedlug_y[ile_w_y++] = punkt(wcz_x, wcz_y, i + 1);
            czy_juz_bylo[i + 1] = false;
        }
        sort(wedlug_x, wedlug_x + ile_w_x, oper_x() );
        sort(wedlug_y, wedlug_y + ile_w_y, oper_y() );
        ile_w_x--;
        ile_w_y--;
        rob_wynik();
        printf("\n");
    }
    return 0;
}
