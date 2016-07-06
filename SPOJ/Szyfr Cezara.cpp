#include<iostream>
#include<string>
using namespace std;

void zmien(string & napis) {
    for(int i=0;i<napis.size();i++) {
        if(napis[i]>=65&&napis[i]<=87)
            napis[i] += 3;
        else if(napis[i]==88)
            napis[i] = 65;
        else if(napis[i]==89)
            napis[i] = 66;
        else if(napis[i]==90)
            napis[i] = 67;
    }
}

int main() {//65 do 90
    string tab[100000];
    int ile;
    for(int i=0;;i++) {
    getline(cin,tab[i]);
    if(cin.eof()) {
        ile = i + 1;
        break;
    }
    zmien(tab[i]);
    }
    for(int i=0;i<ile;i++) {
        cout << tab[i] << endl;

    }
    return 0;
}
