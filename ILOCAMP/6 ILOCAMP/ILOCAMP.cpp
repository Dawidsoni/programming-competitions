#include<iostream>
using namespace std;

int main() {
    string napis = "ilocamp";
   // cout << (char)('w' +  16);
    for(int i=0;i<napis.size();i++) {
        if(i%2 == 1) {
            if(napis[i] - 10 < 'a') napis[i] += 26;
            napis[i] -= 10;

        }else {
            if(napis[i] + 10 > 'z') napis[i] -= 26;
            napis[i] += 10;
        }
    }
    cout << "Dawidsoni" << endl << napis << endl;
    return 0;
}
