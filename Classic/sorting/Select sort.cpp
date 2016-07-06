#include<iostream>
#include<climits>
using namespace std;

int main() {
    int arr[100000];
    int count;
    cin >> count;
    for(int i = 0; i < count; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i + 1 < count; i++) {
        int min = INT_MAX, minInd;
        for(int j = i; j < count; j++) {
            if(arr[j] < min) {
                minInd = j;
                min = arr[j];
            }
        }
        swap(arr[i], arr[minInd]);
    }
    for(int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
