#include<iostream>
#include<climits>
using namespace std;

string str;
int ile, nWyn, nJest;
const int MAX = 200000;

int main() {
    cin >> str;
    if(str == "sortowanie") {
        cin >> ile;
        cout << ile << endl;
        for(int i = 1; i <= ile/2; i++) {
            cout << i << " ";
        }
        if(ile % 2 == 1) cout << ile/2 + 1 << " ";
        for(int i = 1; i <= ile/2; i++) {
            cout << i << " ";
        }
    }else if(str == "sciezki") {
        cin >> ile;
        cout << ile << " " << ile*2 - 3 << endl;
        for(int i = 1; i < ile; i++) {
            cout << i << " " << ile << " " << MAX - i*2 << endl;
        }
        for(int i = 1; i + 1 < ile; i++) {
            cout << i << " " << i + 1 << " " << 1 << endl;
        }

    }
    return 0;
}
