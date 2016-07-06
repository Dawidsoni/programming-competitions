#include<iostream>
using namespace std;

string p1, p2, result;

enum Dir {Left, Up, Diagonally};

int maxRes[10000][10000];
Dir dir[10000][10000];

int main() {
    cin >> p1 >> p2;
    for(int i = 1; i <= (int)p1.size(); i++) {
        for(int j = 1; j <= (int)p2.size(); j++) {
            if(p1[i - 1] == p2[j - 1]) {
                maxRes[i][j] = maxRes[i - 1][j - 1] + 1;
                dir[i][j] = Diagonally;
            }else if(maxRes[i - 1][j] > maxRes[i][j - 1]) {
                maxRes[i][j] = maxRes[i - 1][j];
                dir[i][j] = Left;
            }else {
                maxRes[i][j] = maxRes[i][j - 1];
                dir[i][j] = Up;
            }
        }
    }
    cout << maxRes[p1.size()][p2.size()] << " ";
    result.resize(maxRes[p1.size()][p2.size()]);
    int currDir = result.size() - 1;
    for(int i = p1.size(), j = p2.size(); i > 0 && j > 0 ;) {
        if(dir[i][j] == Diagonally) {
            result[currDir] = (p1.size() > p2.size() ? p1[i - 1] : p2[j - 1]);
            currDir--;
            i--;
            j--;
        }else if(dir[i][j] == Left) {
            i--;
        }else {
            j--;
        }
    }
    cout << result << endl;
    return 0;
}
