#include<stdio.h>

struct struk {
int ile;
int tab[100];
};

int main() {
    int n;
    struk tab[1000];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&tab[i].ile);
        for(int ii=0;ii<tab[i].ile;ii++) {
            scanf("%d",&tab[i].tab[ii]);
        }
    }
    for(int i=0;i<n;i++) {
        for(int ii=tab[i].ile-1;ii>=0;ii--) {
            printf("%d ",tab[i].tab[ii]);
        }
        printf("\n");
    }

    return 0;
}
