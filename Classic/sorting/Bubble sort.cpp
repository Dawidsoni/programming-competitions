#include<iostream>
using namespace std;

int main() {
    int count;
    int arr[100000];
    cin >> count;
    for(int i = 0; i < count; i++) {
        cin >> arr[i];
    }
    while(true) {
        bool isEnd = true;
        for(int i = 0; i + 1 < count; i++) {
            if(arr[i] > arr[i+1]) {
                isEnd = false;
                swap(arr[i], arr[i+1]);
            }
        }
        if(isEnd) break;
    }
    for(int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
