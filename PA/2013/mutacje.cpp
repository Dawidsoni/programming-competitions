#include<stdio.h>
#include<bitset>
#include<algorithm>
using namespace std;

const int STALA = 500000;
bitset<STALA> bSet[2];
int tab[STALA];

int main() {
  //  for(int i = 0; i < STALA; i++) {
  //      tab[i] = STALA - i;
  //  }
   // sort(tab,&tab[STALA]);
    for(int i = 0; i < STALA; i++) {
        bitset<STALA> bs = bSet[0] & bSet[1];
    }
    printf("KONIEC");
    return 0;
}
