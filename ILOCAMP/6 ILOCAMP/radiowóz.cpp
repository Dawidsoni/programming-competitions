#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

typedef long long int long_type;
long_type ile_w_przod, ile_powrot, wcz1, wcz2;
long_type max_wynik;
long_type wynik;
long_type pierwszy;
typedef pair<long_type,long_type> para;
para powrot[300010];

int main() {
    scanf("%lld %lld", &ile_w_przod, &ile_powrot);
    for(int i=0;i<ile_powrot;i++) {
        scanf("%lld %lld", &wcz1, &wcz2 );
        powrot[i] = para(wcz2, wcz1);
    }
    sort(powrot, powrot + ile_powrot);
    powrot[ile_powrot] = para(2000000000000000000,0);
    wynik = 1;
    pierwszy = powrot[0].first;
    for(int i=0;i<ile_powrot;i++) {
        if(powrot[i].second >= powrot[i + 1].first ) {
            wynik++;
        }else {
            wynik = wynik + (powrot[i].second - pierwszy);
            if(wynik > max_wynik) max_wynik = wynik;
            wynik = 1;
            pierwszy = powrot[i + 1].first;
        }
    }
    printf("%lld",max_wynik);
    return 0;
}
