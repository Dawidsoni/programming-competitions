#include<stdio.h>
using namespace std;

typedef long long int l_int;
l_int n;

int main() {
    scanf("%lld",&n);
    for(l_int i = 1;;i++) {
        if((i*i)%n==0) {
            printf("%lld",i*i);
            break;
        }
    }
}
