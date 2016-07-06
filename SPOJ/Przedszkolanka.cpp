#include<stdio.h>

int nwd(int a,int b) {
    while(a!=b) {
        if(a>b)
            a -= b;
        else
            b -= a;
    }
    return a;
}


inline int nww(int a, int b) {
    return a*b/nwd(a,b);

}



int main() {
    int n, g1, g2,tab[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&g1);
        scanf("%d",&g2);
        tab[i] = nww(g1,g2);
    }
    for(int i=0;i<n;i++) {
        printf("%d\n",tab[i]);
    }

    return 0;
}
