#include<iostream>
using namespace std;

const int MAX_SIZE = 1100;

int nZestaw, dlug, wys, dWzor, wWzor, x1, y1;

string wzor[MAX_SIZE], piecz[MAX_SIZE];
int wsp1[MAX_SIZE * MAX_SIZE], wsp2[MAX_SIZE * MAX_SIZE], nWsp;

void robWsp() {
    nWsp = 0;
    for(int i = 0; i < wWzor; i++) {
        for(int ii = 0; ii < wzor[i].size(); ii++) {
            if(wzor[i][ii] == 'x') {
                wsp1[nWsp] = i;
                wsp2[nWsp++] = ii;
            }
        }
    }
}

bool robPiecz(int x, int y) {
    for(int i = 0; i < nWsp; i++) {
        int w1 = wsp1[i] + x, w2 = wsp2[i] + y;
        //cout << w1 << " " << w2 << endl;
        if(w1 < 0 || w2 < 0 || w2 >= dlug || w1 >= wys || piecz[w1][w2] == '.') {
            cout << "false";
            return false;
        }
        piecz[w1][w2] = '.';
        cout << "usuwam " << w1 << " " << w2 << endl;
    }
    return true;
}

bool robWyn() {
    cout << "zaczynam! wys = " << wys << " dlug = " << dlug << "\n";
    robWsp();
    cout << nWsp << " " << wsp1[0] << " " << wsp2[0] <<  endl;
    if(nWsp > 0) {
        for(int i = -wsp1[0]; i < wys; i++) {
            for(int ii = -wsp2[0]; ii < dlug; ii++) {
                if(piecz[i + wsp1[0]][ii + wsp2[0]] == 'x') {
                    cout << i << " " << ii << endl;
                    if(robPiecz(i, ii) == false) return false;
                }
            }
        }
    }
    for(int i = 0; i < wys; i++) {
        for(int ii = 0; ii < piecz[i].size(); ii++) {
            if(piecz[i][ii] == 'x') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nZestaw;
    for(int i = 0; i < nZestaw; i++) {
        cin >> wys >> dlug >> wWzor >> dWzor;
        for(int i = 0; i < wys; i++) {
            cin >> piecz[i];
        }
        for(int i = 0; i < wWzor; i++) {
            cin >> wzor[i];
        }
        if(robWyn()) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return 0;
}
