#include <iostream>
#include<algorithm>

using namespace std;

const int ROZMIAR = 300;

int ile, promien;
int suma[ROZMIAR][ROZMIAR];
int wyn[ROZMIAR][ROZMIAR];

void robSume() {
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            suma[i][ii] += (ii - 1 >= 0 ? suma[i][ii - 1] : 0);
        }
    }
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            suma[i][ii] += (i - 1 >= 0 ? suma[i - 1][ii] : 0);
        }
    }
}

int prost(int odkadX, int odkadY, int dokadX, int dokadY) {
    return suma[dokadX][dokadY] - (odkadX - 1 >= 0 ? suma[odkadX - 1][dokadY] : 0) - (odkadY - 1 >= 0 ? suma[dokadX][odkadY - 1] : 0) +
     (odkadX - 1 >= 0 && odkadY - 1 >= 0 ? suma[odkadX - 1][odkadY - 1] : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile >> promien;
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            cin >> suma[i][ii];
        }
    }
    robSume();
    for(int i = 0; i < ile; i++) {
        for(int ii = 0; ii < ile; ii++) {
            int odkadX = max(0, i - promien), odkadY = max(0, ii - promien);
            int dokadX = min(ile - 1, i + promien), dokadY = min(ile - 1, ii + promien);
            wyn[i][ii] = prost(odkadX, odkadY, dokadX, dokadY);
            cout << wyn[i][ii] << " ";
        }
        cout << endl;
    }
    return 0;
}
