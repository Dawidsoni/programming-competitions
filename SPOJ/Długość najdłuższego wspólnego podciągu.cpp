#include<iostream>
using namespace std;

int ile, wcz;
string tek1, tek2;
int tab_nwp[1100][1100];

int nwp() {
    for(int i = 1; i <= tek1.size(); i++) {
        for(int j = 1; j <= tek2.size(); j++) {
            if(tek1[i - 1] == tek2[j - 1]) tab_nwp[i][j] = tab_nwp[i - 1][j - 1] + 1;
            else if(tab_nwp[i - 1][j] > tab_nwp[i][j - 1]) tab_nwp[i][j] = tab_nwp[i - 1][j];
            else tab_nwp[i][j] = tab_nwp[i][j - 1];
        }
    }
    return tab_nwp[tek1.size()][tek2.size()];
}

int main() {
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> wcz >> tek1 >> wcz >> tek2;
        cout << nwp() << endl;
    }
    return 0;
}
