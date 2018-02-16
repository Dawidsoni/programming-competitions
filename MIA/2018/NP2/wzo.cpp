#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef unsigned long long int LType;
const int MAX_SIZE = 1000010;
const LType MOD_P = 1000000000LL * 10000LL;
const LType MOD_Q = 10000;
LType n, k, firstElem, result;
bool isPrime[MAX_SIZE];
LType primeCount[MAX_SIZE];
vector<LType> numList;

void updatePrimeCount(LType prime, LType num) {
	while(num % prime == 0) {
		primeCount[prime]++;
		num /= prime;
	}
}

void findPrimes() {
	for(LType i = 2; i <= k; i++) {
		isPrime[i] = true;
	}
	for(LType i = 2; i <= k; i++) {
		if(isPrime[i] == false) {
			continue;
		}
		for(LType j = i; j <= k; j += i) {
			updatePrimeCount(i, j);
			isPrime[j] = false;
		}
	}
}

void countNumList() {
	for(LType i = n - k + 1; i <= n; i++) {
		numList.push_back(i);
	}
	firstElem = numList[0];
}

void shortenNumList(LType prime, LType count) {
	LType ind = (prime - (firstElem % prime)) % prime; 
	LType i = 0;
	while(i < count) {
		if(numList[ind] % prime == 0) {
			numList[ind] /= prime;
			i++;
		}else {
			ind += prime;
		}
	}
}

void shortenNumList() {
	for(LType i = 2; i <= k; i++) {
		shortenNumList(i, primeCount[i]);
	}
}

LType multiplyNums(LType num1, LType num2) {
	LType n11 = num1 / MOD_Q;
	LType n12 = num1 % MOD_Q;
	LType n21 = num2 / MOD_Q;
	LType n22 = num2 % MOD_Q;
	LType result = (n12 * n22) % MOD_P;
	result += (n11 * n22 * MOD_Q) % MOD_P; 
	result %= MOD_P;
	result += (n12 * n21 * MOD_Q) % MOD_P;
	result %= MOD_P;
	result += ((MOD_Q * MOD_Q) * ((n11 * n21) % (MOD_Q * MOD_Q))) % MOD_P;
	result %= MOD_P;
	return result;
}

void countResult() {
	result = 1;
	for(LType i = 0; i < (int)numList.size(); i++) {
		numList[i] %= MOD_P;
		result %= MOD_P;
		result = multiplyNums(numList[i], result);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	if(k == 0) {
		cout << "1\n";
		return 0;
	}
	findPrimes();
	countNumList();
	shortenNumList();
	countResult();
	cout << result << "\n";
	return 0;
}
