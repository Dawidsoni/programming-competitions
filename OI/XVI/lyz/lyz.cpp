#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long int LType;

const int MAX_SIZE = 200100;
const int TREE_SIZE = 1 << 18;
LType ile, nZdarz, nPar, nTol, numLyz, ileDodac;
LType suma[TREE_SIZE * 2];
LType pref[TREE_SIZE * 2];
LType suf[TREE_SIZE * 2];
LType maxSuma[TREE_SIZE * 2];

void robDrz() {
	for(int i = 0; i < ile; i++) {
		suma[i + TREE_SIZE] = pref[i + TREE_SIZE] = suf[i + TREE_SIZE] = maxSuma[i + TREE_SIZE] = -nPar;
	}
	for(int i = TREE_SIZE - 1; i >= 0; i--) {
		suma[i] = suma[i * 2] + suma[i * 2 + 1];
	}
}

LType zwieksz(LType ind, LType oIle) {
	LType wynik = 0;
	ind += TREE_SIZE;
	maxSuma[ind] += oIle;
	suma[ind] += oIle;
	pref[ind] += oIle;
	suf[ind] += oIle;
	ind /= 2;
	while(ind > 0) {
		suma[ind] = suma[ind * 2] + suma[ind * 2 + 1];
		pref[ind] = max(suma[ind * 2] + pref[ind * 2 + 1], pref[ind * 2]);
		suf[ind] = max(suf[ind * 2 + 1], suma[ind * 2 + 1] + suf[ind * 2]);
		maxSuma[ind] = max(max(maxSuma[ind * 2], maxSuma[ind * 2 + 1]), suf[ind * 2] + pref[ind * 2 + 1]);
		wynik = max(wynik, maxSuma[ind]);
		ind /= 2;
	}
	return wynik;
}

void robZdarz() {
	if(zwieksz(numLyz, ileDodac) > nPar * nTol) {
		printf("NIE\n");
	}else {
		printf("TAK\n");
	}
}

void wczytaj() {
	scanf("%lld%lld%lld%lld", &ile, &nZdarz, &nPar, &nTol);
	robDrz();
	for(int i = 0; i < nZdarz; i++) {
		scanf("%lld%lld", &numLyz, &ileDodac);
		robZdarz();
	}
}

int main() {
	wczytaj();	
	return 0;
}