//Dawid Wegner
//279743
//KLO

#include<iostream>

using namespace std;

typedef long long int LType;

LType nTest, nFib, mod;

class Matrix {
public:
	LType list[2][2];

	Matrix() {
		list[0][0] = list[0][1] = list[1][0] = 1;
		list[1][1] = 0;
	}
	
	friend Matrix operator*(Matrix m1, Matrix m2) {
		Matrix result;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				result.list[i][j] = 0;
				for(int k = 0; k < 2; k++) {
					result.list[i][j] += ((m1.list[i][k] * m2.list[k][j]) % mod);
					result.list[i][j] %= mod;
				}
			}
		}		
		return result;
	}
};

LType solve() {
	Matrix result;
	Matrix currentMatrix;
	while(nFib >= 1) {
		if(nFib % 2 == 1) {
			result = result * currentMatrix;
		}
		nFib /= 2;
		currentMatrix = currentMatrix * currentMatrix;
	}
	return result.list[1][1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		cin >> nFib >> mod;
		cout << solve() << "\n";
	}
	return 0;
}
