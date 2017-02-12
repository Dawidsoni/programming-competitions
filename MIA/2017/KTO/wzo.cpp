#include <iostream>

using namespace std;

typedef unsigned long long int LType;
const int MOD_P = 1000000103;

int nTest, aNum, bNum;

struct Matrix {
	Matrix(int x11, int x12, int x21, int x22) {
		mtx[0][0] = x11;
		mtx[0][1] = x12;
		mtx[1][0] = x21;
		mtx[1][1] = x22;
	}	
	LType mtx[2][2];
};


Matrix mul(Matrix m1, Matrix m2) {
	Matrix result(0, 0, 0, 0);	
	result.mtx[0][0] = m1.mtx[0][0] * m2.mtx[0][0] + m1.mtx[0][1] * m2.mtx[1][0];
	result.mtx[0][1] = m1.mtx[0][0] * m2.mtx[0][1] + m1.mtx[0][1] * m2.mtx[1][1];
	result.mtx[1][0] = m1.mtx[1][0] * m2.mtx[0][0] + m1.mtx[1][1] * m2.mtx[1][0];
	result.mtx[1][1] = m1.mtx[1][0] * m2.mtx[0][1] + m1.mtx[1][1] * m2.mtx[1][1];
	result.mtx[0][0] %= MOD_P;
	result.mtx[0][1] %= MOD_P;
	result.mtx[1][0] %= MOD_P;
	result.mtx[1][1] %= MOD_P;	
	return result;
}

int countFib(int num) {
	num -= 2;
	Matrix result(3, 2, 2, 1);
	Matrix base(1, 1, 1, 0);
	while(num > 0) {
		if(num % 2 == 1) {
			result = mul(result, base);
		}
		base = mul(base, base);
		num /= 2;
	}
	return result.mtx[1][1];
}

int gcd(int a, int b) {
	if(a == 0) {
		return b;
	}else if(b == 0) {
		return a;
	}else if(a > b) {
		return gcd(b, a % b);
	}else {
		return gcd(a, b % a);
	}
}

LType invertP(LType num) {
	int pot = MOD_P - 2;
	LType result = 1;
	while(pot > 0) {
		if(pot % 2 == 1) {
			result = (result * num) % MOD_P;
		}
		num = (num * num) % MOD_P;
		pot /= 2;
	}
	return result;
}

void solve(int aNum, int bNum) {
	LType xNum = countFib(aNum);
	LType yNum = countFib(bNum);
	LType dNum = countFib(gcd(aNum, bNum));
	if(dNum != 0) {
		dNum = invertP(dNum);
		xNum = (xNum * dNum) % MOD_P;
		yNum = (yNum * dNum) % MOD_P;
		xNum = (xNum * xNum) % MOD_P;
		yNum = (yNum * yNum) % MOD_P;
		cout << xNum << "/" << yNum << "\n";
	}else if(aNum == bNum) {
		cout << "1/1\n";
	}else if(aNum > bNum) {
		LType fib1 = countFib(bNum - 1);
		LType fib2 = countFib(bNum + 1);
		LType result = (fib1 + fib2) % MOD_P;
		result = (result * result) % MOD_P;
		cout << result << "/1\n";
	}else {
		LType fib1 = countFib(aNum - 1);
		LType fib2 = countFib(aNum + 1);
		LType result = (fib1 + fib2) % MOD_P;		
		result = (result * result) % MOD_P;
		cout << "1/" << result << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		cin >> aNum >> bNum;
		aNum++;
		bNum++;
		solve(aNum, bNum);
	}	
	return 0;
}
