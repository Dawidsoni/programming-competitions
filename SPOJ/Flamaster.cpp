#include<iostream>
using namespace std;

void zmien(string nazwa) {
    int licznik = 1;
    for(int i=1;i<=nazwa.size();i++) {
        if(i==nazwa.size()) {
            if(nazwa[i]==nazwa[i-1]) licznik++;
            if(licznik>2) {
            cout << nazwa[i-1] << licznik;
            }else {
                if(licznik==1) cout << nazwa[i-1];
                else if(licznik==2) cout << nazwa[i-1] << nazwa[i-1];
            }
        }
        else if(nazwa[i]==nazwa[i-1]) licznik++;
        else if(nazwa[i]!=nazwa[i-1]) {
        if(licznik>2) cout << nazwa[i-1] << licznik;
        else {
            if(licznik==1) cout << nazwa[i-1];
            else if(licznik==2) cout << nazwa[i-1] << nazwa[i-1];
        }
        licznik = 1;
        }
    }
    cout << endl;
}

int main() {
    string wczytaj;
    int n;
    cin >> n;
    getline(cin,wczytaj);
    for(int i=0;i<n;i++) {
        getline(cin,wczytaj);
        zmien(wczytaj);
    }

    return 0;
}
