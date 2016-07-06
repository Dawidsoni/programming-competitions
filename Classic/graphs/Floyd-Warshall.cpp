#include<iostream>
#include<climits>
using namespace std;

int result[10000][10000], vCount, eCount, v1, v2, dist;

int main() {
    cin >> vCount >> eCount;
    vCount++;
    for(int i=0; i < vCount; i++) {
        for(int ii=0; ii < vCount; ii++) {
            result[i][ii] = INT_MAX;
            if(i == ii) result[i][ii] = 0;
        }
    }
    for(int i = 0;i < eCount; i++) {
        cin >> v1 >> v2 >> dist;
        result[v1][v2] = dist;
    }
    for(int k = 1; k < vCount; k++) {
        for(int i = 1; i < vCount; i++) {
            for(int j = 1; j < vCount; j++) {
                if(result[i][k] != INT_MAX && result[k][j] != INT_MAX)
                    result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
            }
        }
    }
    for(int i = 0; i < vCount; i++) {
        for(int j = 0; j < vCount; j++) {
            if(i != j && result[i][j] != INT_MAX) {
                cout << "odl z " << i << " do " << j << " wynosi: " << result[i][j] << endl;
            }
        }
    }
}
