#include<iostream>
using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    if(n>m) {
        int kopia = n;
        n = m;
        m = kopia;
    }
    if(n<k) cout << "0";
    else if(n<2*k) cout << m/k;
    else cout << 2*(m/k) + 2*((n - 2*k)/k);
    return 0;
}
