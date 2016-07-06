#include "cgdzlib.h"

int main() {
    int maks_n = inicjuj();
    for(int i = 1; i < maks_n; i++) {
        for(int j = i + 1; j <= maks_n; j++) {
            if(f(i,j,maks_n - 1)) {
                if(g(i,j)) { //i wieksze
                    odpowiedz(j);
                }else {
                    odpowiedz(i);
                }
            }
        }
    }
    return 0;
}
