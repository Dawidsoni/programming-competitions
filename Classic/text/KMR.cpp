#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

string text;
int arr[10000][10];

class Connection {
public:
    int first, second, num;
    Connection();
    Connection(int f, int s, int n) : first(f), second(s), num(n) {}
    friend bool operator < (const Connection & conn1, const Connection & conn2) {
        if(conn1.first == conn2.first) return conn1.second < conn2.second;
        return conn1.first < conn2.first;
    }
};

bool isEqual(int fromInd1, int fromInd2, int length) {
    int pow = 1, i = 0;
    for(; pow <= length; i++, pow *= 2) {}
    pow /= 2;
    i--;
    if(arr[fromInd1][i] == arr[fromInd2][i] && arr[fromInd1 + (length - pow)][i] == arr[fromInd2 + (length - pow)][i]) return true;
    return false;
}

bool isGreater(int fromInd1, int fromInd2, int length) {
    int pow = 1, i = 0;
    for(; pow <= length; i++, pow *= 2) {}
    pow /= 2;
    i--;
    if(arr[fromInd1][i] == arr[fromInd2][i]) {
        return arr[fromInd1 + (length - pow)][i] > arr[fromInd2 + (length - pow)][i];
    }else {
        return arr[fromInd1][i] > arr[fromInd2][i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> text;
    for(int i = 0; i < (int)text.size(); i++) {
        arr[i][0] = text[i] - 'a';
    }
    for(int i = 1, pow = 1; pow * 2 <= (int)text.size(); i++, pow *= 2) {
        vector<Connection> vect;
        for(int ii = 0; ii < (int)text.size(); ii++) {
            if(ii + (pow * 2) > (int)text.size()) break;
            vect.push_back(Connection(arr[ii][i - 1], arr[ii + pow][i - 1], ii));
        }
        sort(vect.begin(), vect.end());
        arr[vect[0].num][i] = 0;
        for(int ii = 1, num = 0; ii < (int)vect.size(); ii++) {
            if(vect[ii].first != vect[ii - 1].first || vect[ii].second != vect[ii - 1].second) num++;
            arr[vect[ii].num][i] = num;
        }
    }
    cout << isEqual(0, 3, 2);
    return 0;
}
