#include<iostream>
#include<bitset>
using namespace std;

typedef pair<int,int> para;
bitset<60000> lista[1000];
int ile, ileWyn, ileLista = -1;
string tab[60000];
para tabWyn[120000];

int main() {
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> tab[i];
    }
    for(int i = 48; i <= 122; i++) {
        for(int ii = 0; ii < 5; ii++) {
            bool czy = false;
            int ileBit = 0, ktory;
            for(int iii = 0; iii < ile; iii++) {
                if(tab[iii][ii] == i) {
                    if(!czy) {
                        czy = true;
                        ileLista++;
                    }
                    lista[ileLista].set(iii,true);
                    ktory = iii;
                    ileBit++;
                }
            }
            if(ileBit == 1) {
                lista[ileLista].set(ktory,false);
                ileLista--;
            }
        }
    }
    ileLista++;
    try {
        for(int i = 0; i < ile; i++) {
            bitset<60000> ktoreNie;
            for(int ii = 0; ii < ileLista; ii++) {
                if(lista[ii][i] == true) {
                    ktoreNie = ktoreNie | lista[ii];
                }
            }
            for(int ii = i + 1; ii < ile;ii++) {
                if(ktoreNie[ii] == false) {
                    tabWyn[ileWyn++] = para(i + 1, ii + 1);
                    if(ileWyn == 100000) throw 'a';
                }
            }
        }
    }
    catch(...) {}
    cout << ileWyn << endl;
    for(int i = 0; i < ileWyn; i++) {
        cout << tabWyn[i].first << " " << tabWyn[i].second << endl;
    }
    return 0;
}
