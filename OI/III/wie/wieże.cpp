#include<stdio.h>
#include<algorithm>
using namespace std;

class Rect {
public:
    int num, pocz, kon;
    Rect(int nu, int po, int ko) : num(nu), pocz(po), kon(ko) {}
    Rect() {}
    friend bool operator < (const Rect & rect1, const Rect & rect2) {
        if(rect1.kon < rect2.kon) return true;
        else return false;
    }
};

const int ROZMIAR = 3100;
Rect rectX[ROZMIAR];
Rect rectY[ROZMIAR];
int wynX[ROZMIAR];
int wynY[ROZMIAR];
int tabX[ROZMIAR];
int tabY[ROZMIAR];
int ile, wczX1, wczY1, wczX2, wczY2;

int main() {
    scanf("%d", &ile);
    for(int i = 0; i < ile; i++) {
        scanf("%d%d%d%d", &wczX1, &wczY1, &wczX2, &wczY2);
        rectX[i] = Rect(i + 1,wczX1, wczX2);
        rectY[i] = Rect(i + 1,wczY1, wczY2);
    }
    sort(rectX, rectX + ile);
    sort(rectY, rectY + ile);
    for(int i = 0; i < ile; i++) {
        int odKad = rectX[i].pocz;
        while(wynX[odKad] != 0) {
            odKad++;
            if(odKad > rectX[i].kon) {
                printf("NIE");
                return 0;
            }
        }
        wynX[odKad] = rectX[i].num;
    }
    for(int i = 0; i < ile; i++) {
        int odKad = rectY[i].pocz;
        while(wynY[odKad] != 0) {
            odKad++;
            if(odKad > rectY[i].kon) {
                printf("NIE");
                return 0;
            }
        }
        wynY[odKad] = rectY[i].num;
    }
    for(int i = 1; i <= ile; i++) {
        tabX[wynX[i]] = i;
    }
    for(int i = 1; i <= ile; i++) {
        tabY[wynY[i]] = i;
    }
    for(int i = 1; i <= ile; i++) {
        printf("%d %d\n",tabX[i],tabY[i]);
    }
    return 0;
}
