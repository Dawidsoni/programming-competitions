#include <iostream>
using namespace std;

const int MAX_SIZE = 100010;
const int MOD_P = 1000000007;
typedef unsigned long long int LType;

int chainSize;
int rb, rg, br, bg, gr, gb;
LType dp[3][11][11][11][11][11][11];
LType fcArr[MAX_SIZE];
LType invFcArr[MAX_SIZE];
LType result;

LType countDp(int rb, int rg, int br, int bg, int gr, int gb, int type) {
	if(dp[type][rb][rg][br][bg][gr][gb] != -1) {
		return dp[type][rb][rg][br][bg][gr][gb];
	} 
    if(rb == 0 && rg == 0 && br == 0 && bg == 0 && gr == 0 && gb == 0) {
        return 1;
    }
	LType result = 0;
	if(type == 0 && rb > 0) {
		result += countDp(rb - 1, rg, br, bg, gr, gb, 2);
    }
    if(type == 0 && rg > 0) {
		result += countDp(rb, rg - 1, br, bg, gr, gb, 1);
	}
    if(type == 1 && gr > 0) {
		result += countDp(rb, rg, br, bg, gr - 1, gb, 0);
    }
    if(type == 1 && gb > 0) {
		result += countDp(rb, rg, br, bg, gr, gb - 1, 2);
	}
    if(type == 2 && br > 0) {
		result += countDp(rb, rg, br - 1, bg, gr, gb, 0);
    }
    if(type == 2 && bg > 0) {
		result += countDp(rb, rg, br, bg - 1, gr, gb, 1);
	}
	result %= MOD_P;
	dp[type][rb][rg][br][bg][gr][gb] = result;
	return result;
}

LType countPower(LType num, int pow) {
    LType result = 1;
    LType mult = num;
    while(pow > 0) {
        if(pow % 2 == 1) {
            result *= mult;
            result %= MOD_P;
        }
        mult *= mult;
        mult %= MOD_P;
        pow /= 2;
    }
    return result;
}

LType getInverse(LType num) {
    return countPower(num, MOD_P - 2);
}

void initFcArr() {
    fcArr[0] = 1;
    for(int i = 1; i <= chainSize; i++) {
        fcArr[i] = fcArr[i - 1] * i;
        fcArr[i] %= MOD_P;
    }
}

void initFcArrInv() {
    invFcArr[chainSize] = getInverse(fcArr[chainSize]);
    for(int i = chainSize - 1; i >= 0; i--) {
        invFcArr[i] = invFcArr[i + 1] * (i + 1);
        invFcArr[i] %= MOD_P;
    }
}

LType getBinCoef(int n, int k) {
    if(n < 0 || k < 0 || n < k) {
        return 0;
    }
    LType result = fcArr[n] * invFcArr[k];
    result %= MOD_P;
    result *= invFcArr[n - k];
    result %= MOD_P;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> chainSize;
    for(int i = 0; i < chainSize; i++) {
        cin >> rb >> rg >> br >> bg >> gr >> gb;
    }
    initFcArr();
    initFcArrInv();
    if(chainSize == 1) {
        cout << 3 << "\n";
        return 0;
    }
    for(int irb = 0; irb <= rb; irb++) {
        for(int irg = 0; irg <= rg; irg++) {
            for(int ibr = 0; ibr <= br; ibr++) {
                for(int ibg = 0; ibg <= bg; ibg++) {
                    for(int igr = 0; igr <= gr; igr++) {
                        for(int igb = 0; igb <= gb; igb++) {
							dp[0][irb][irg][ibr][ibg][igr][igb] = -1;
							dp[1][irb][irg][ibr][ibg][igr][igb] = -1;
							dp[2][irb][irg][ibr][ibg][igr][igb] = -1;
                            int seqSize = irb + irg + ibr + ibg + igr + igb + 1;
                            if(seqSize > chainSize) {
                                continue;
                            }
                            LType restRes = getBinCoef(chainSize - 1, chainSize - seqSize);
                            if(restRes == 0) {
                                continue;
                            }
                            LType curRes = 0;
                            curRes += countDp(irb, irg, ibr, ibg, igr, igb, 0);
                            curRes += countDp(irb, irg, ibr, ibg, igr, igb, 1);
                            curRes += countDp(irb, irg, ibr, ibg, igr, igb, 2);
                            result += ((curRes * restRes) % MOD_P);
                        }
                    }
                }
            }
        }
    }
    result %= MOD_P;
    cout << result << "\n";
    return 0;
}
