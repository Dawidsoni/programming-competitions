#include<stdio.h>
#include<bitset>
#include<algorithm>
using namespace std;
bitset<1000> druzyna[3];
bitset<1000> wczytaj;
int wynik[3];
bool czy_w;
int ile;

int main() {
    scanf("%d",&ile);
    for(int i=0;i<ile;i++) {
        wczytaj.reset();
        for(int j=0;j<ile;j++) {
            scanf("%d",&czy_w);
            wczytaj.set(j,czy_w);
        }
        for(int j=0;j<3;j++) {
            bitset<1000> wynik = druzyna[j] & wczytaj;
            if(wynik == druzyna[j]) { //mogê do³¹czyæ
                druzyna[j] |= wczytaj;
                break;
            }else if(wynik.none()) { //nie mogê do³¹czyæ {
                if(j==2) {
                    printf("NIE");
                    return 0;
                }
            }else { //Nie da siê stworzyæ takich dru¿yn
                printf("NIE");
                return 0;
            }
        }
    }
    for(int i=0;i<3;i++) {
        wynik[i] = druzyna[i].count();
    }
    sort(wynik,wynik + 3);
    printf("TAK %d %d %d",wynik[0], wynik[1], wynik[2]);
    return 0;
}
