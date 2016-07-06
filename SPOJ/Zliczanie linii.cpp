#include<iostream>
using namespace std;

int main() {
    string a = "";
    int ile = 0;
    while(!cin.eof()) {
        getline(cin,a);
        ile++;
    }
    cout << ile << endl;

    return 0;
}
