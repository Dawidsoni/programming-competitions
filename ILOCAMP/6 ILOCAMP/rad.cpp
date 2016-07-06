#include<stdio.h>
#include<set>
using namespace std;

int ile_skrzyzowan, ile_powrotnych, ile_dodac;
class para {
public:
    para() {}
    para(int z_d, int do_d) : z_drogi(z_d), do_drogi(do_d) {}
    int z_drogi, do_drogi;
    friend bool operator < (const para & p1, const para & p2) {
        if(p1.z_drogi < p2.z_drogi) return true;
        return false;
    }
    friend bool operator == (const para & p1, const para & p2) {
        if(p1.z_drogi == p2.z_drogi) return true;
        return false;
    }
};

int z_drogi, do_drogi;
set<para>  powrot;
set<para> do_ktorego;

//muszê skoñczyæ, id¹c do jak najmniejszego
//muszê dojœæ do jak najwiêkszego
para wynik;

int main() {
    scanf("%d %d", &ile_skrzyzowan, &ile_powrotnych);
    for(int i=0;i<ile_powrotnych;i++) {
        scanf("%d %d", &z_drogi, &do_drogi);
        powrot.insert(para(z_drogi, do_drogi));
        do_ktorego.insert(para(do_drogi, z_drogi));
    }
    int max = 0;
    while(!powrot.empty()) {
    set<para>::iterator it = powrot.end();
    it--;
    wynik = *it;
    int ile = it->z_drogi;
    if(ile + 1 < max + ile_dodac) break;
    ile_dodac = 0;
    set<para>::iterator it2 = do_ktorego.end();
    while(true) {
        it2--;
        para wyn = *it2;
        ile_dodac++;
        if(it2 == do_ktorego.begin() || wynik) {
            ile = ile - it2->do_drogi;
             break;
        }
        wynik = wyn;
    }
    if(ile > max) max = ile;
    powrot.erase(it);
    }
    printf("%d", max);
    return 0;
}
