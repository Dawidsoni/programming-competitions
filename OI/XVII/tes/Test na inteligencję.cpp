#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int ROZMIAR = 1100000;
int ile, wcz, nTest, ileDl;
vector<int> indeksy[ROZMIAR];


int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile;
    for(int i = 0; i < ile; i++) {
        cin >> wcz;
        indeksy[wcz].push_back(i);
    }
    cin >> nTest;
    for(int i = 0; i < nTest; i++) {
        cin >> ileDl;
        int aktInd = -1;
        bool odp = true;
        for(int ii = 0; ii < ileDl; ii++) {
            cin >> wcz;
            vector<int>::iterator it = upper_bound(indeksy[wcz].begin(), indeksy[wcz].end(), aktInd);
            if(it == indeksy[wcz].end()) odp = false;
            else aktInd = *it;
        }
        if(odp) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }

    return 0;
}
