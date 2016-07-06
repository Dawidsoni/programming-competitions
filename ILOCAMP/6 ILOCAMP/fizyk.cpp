#include<iostream>
using namespace std;

enum map_typ {
sciana, kartka, puste, pocz_ustawienie
};

bool czy_byl[1000][1000]; //bierzemy 1 od lewej pocz¹tku ustawienia
map_typ mapa[1000][1000];
int rozmiar_mapy, rozmiar_bitego, pocz_x, pocz_y;
bool czy_juz_pocz;
char wczytaj;

int main() {
    scanf("%d %d", &rozmiar_mapy, &rozmiar_bitego);
    for(int i=0;i<rozmiar_mapy;i++) {
        for(int j=0;j<rozmiar_mapy;j++) {
            scanf("%c", &wczytaj);
            if(wczytaj=='B' && !czy_juz_pocz) {
                czy_juz_pocz = true;
                pocz_x = i;
                pocz_y = j;
            }
            if(wczytaj=='#') mapa[i][j] = sciana;
            else if(wczytaj=='B') mapa[i][j] = pocz_ustawienie;
            else if(wczytaj=='F') mapa[i][j] = kartka;
            else mapa[i][j] = puste;
        }
    }
    printf("%d %d",pocz_x,pocz_y);
    scanf("%d", &rozmiar_bitego);
    return 0;
}
