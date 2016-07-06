#include<iostream>
#include<string>
using namespace std;

string text;
int max_rad[100000];
int counter;

int main() {
    cin >> text;
    for(int i = 0; i  + 1 < (int)text.size(); ) {
        counter++;
        int len = 0;
        while(i - len >= 0 && i + len + 1 < (int)text.size() && text[i - len] == text[i + 1 + len]) {
            len++;
        }
        max_rad[i] = len;
        int j = i - 1;
        for(; j >= i - max_rad[i];j--) {
            if(i - max_rad[i] == j - max_rad[j]) {
                break;
            }
            max_rad[i + i - j] = min(max_rad[j], j - (i - max_rad[i]));
        }
        i += (i - j);
    }
    cout << counter << endl;
    for(int i = 0; i + 1 < (int)text.size();i++) {
        cout << max_rad[i] << " ";
    }
    return 0;
}
