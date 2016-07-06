#include<stdio.h>

int nwd(int a, int b) {
    while(a!=b) {
        if(a>b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main() {
    int n, a, b, tab[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        scanf("%d",&b);
        tab[i] = nwd(a,b);
    }
    for(int i=0;i<n;i++) {
        printf("%d\n",tab[i]);
    }


    return 0;
}
