#include<iostream>
#include <cmath>
using namespace std;

typedef long long int LType;

const LType MAX_SIZE = 610;

LType numberCount;
LType numberArray[MAX_SIZE];
char charArray[MAX_SIZE];
LType maxResult[MAX_SIZE][MAX_SIZE];
LType minResult[MAX_SIZE][MAX_SIZE];

void doubleArray() {
	for(LType i = 0; i < numberCount; i++) {
		numberArray[i + numberCount] = numberArray[i];
		charArray[i + numberCount] = charArray[i];
	}	
	numberCount *= 2;
}

LType countPlusMin(LType fromInd, LType toInd, LType k) {
	LType result = min(minResult[fromInd][k] + minResult[k + 1][toInd], maxResult[fromInd][k] + maxResult[k + 1][toInd]);
	result = min(result, minResult[fromInd][k] + maxResult[k + 1][toInd]);
	result = min(result, maxResult[fromInd][k] + minResult[k + 1][toInd]);		
	return result;
}

LType countPlusMax(LType fromInd, LType toInd, LType k) {
	LType result = max(minResult[fromInd][k] + minResult[k + 1][toInd], maxResult[fromInd][k] + maxResult[k + 1][toInd]);
	result = max(result, minResult[fromInd][k] + maxResult[k + 1][toInd]);
	result = max(result, maxResult[fromInd][k] + minResult[k + 1][toInd]);		
	return result;
}

LType countMinusMin(LType fromInd, LType toInd, LType k) {
	LType result = min(minResult[fromInd][k] - minResult[k + 1][toInd], maxResult[fromInd][k] - maxResult[k + 1][toInd]);
	result = min(result, minResult[fromInd][k] - maxResult[k + 1][toInd]);
	result = min(result, maxResult[fromInd][k] - minResult[k + 1][toInd]);		
	return result;
}

LType countMinusMax(LType fromInd, LType toInd, LType k) {
	LType result = max(minResult[fromInd][k] - minResult[k + 1][toInd], maxResult[fromInd][k] - maxResult[k + 1][toInd]);
	result = max(result, minResult[fromInd][k] - maxResult[k + 1][toInd]);
	result = max(result, maxResult[fromInd][k] - minResult[k + 1][toInd]);		
	return result;
}

LType countMultiplyMin(LType fromInd, LType toInd, LType k) {
	LType result = min(minResult[fromInd][k] * minResult[k + 1][toInd], maxResult[fromInd][k] * maxResult[k + 1][toInd]);
	result = min(result, minResult[fromInd][k] * maxResult[k + 1][toInd]);
	result = min(result, maxResult[fromInd][k] * minResult[k + 1][toInd]);		
	return result;
}

LType countMultiplyMax(LType fromInd, LType toInd, LType k) {
	LType result = max(minResult[fromInd][k] * minResult[k + 1][toInd], maxResult[fromInd][k] * maxResult[k + 1][toInd]);
	result = max(result, minResult[fromInd][k] * maxResult[k + 1][toInd]);
	result = max(result, maxResult[fromInd][k] * minResult[k + 1][toInd]);		
	return result;
}


LType countMin(char sign, LType fromInd, LType toInd, LType k) {
	if(sign == '+') {
		return countPlusMin(fromInd, toInd, k);
	}else if(sign == '-') {
		return countMinusMin(fromInd, toInd, k);
	}else if(sign == '*') {
		return countMultiplyMin(fromInd, toInd, k);	
	}else {
		LType result = countPlusMin(fromInd, toInd, k);
		result = min(result,  countMinusMin(fromInd, toInd, k));
		result = min(result, countMultiplyMin(fromInd, toInd, k));
		return result;
	}	
}

LType countMax(char sign, LType fromInd, LType toInd, LType k) {
	if(sign == '+') {
		return countPlusMax(fromInd, toInd, k);
	}else if(sign == '-') {
		return countMinusMax(fromInd, toInd, k);
	}else if(sign == '*') {
		return countMultiplyMax(fromInd, toInd, k);
	}else {
		LType result =  countPlusMax(fromInd, toInd, k);
		result = max(result, countMinusMax(fromInd, toInd, k));
		result = max(result, countMultiplyMax(fromInd, toInd, k));
		return result;
	}	
}

void countResult(LType fromInd, LType toInd) {
	minResult[fromInd][toInd] = countMin(charArray[fromInd], fromInd, toInd, fromInd);
	maxResult[fromInd][toInd] = countMax(charArray[fromInd], fromInd, toInd, fromInd);	
	for(LType k = fromInd + 1; k < toInd; k++) {
		minResult[fromInd][toInd] = min(minResult[fromInd][toInd], countMin(charArray[k], fromInd, toInd, k));
		maxResult[fromInd][toInd] = max(maxResult[fromInd][toInd], countMax(charArray[k], fromInd, toInd, k));		
	}	
}

void countResult() {
	for(LType i = 0; i < numberCount; i++) {
		maxResult[i][i] = minResult[i][i] = numberArray[i];
	}
	for(LType length = 1; length < (numberCount / 2 + 2); length++) {
		for(LType i = 0; i + length < numberCount; i++) {
			countResult(i, i + length);
		}
	}
}

LType absolute(LType x) {
	return x >= 0 ? x : -x;
}

void printResult() {
	for(LType i = 0; i < numberCount / 2; i++) {
		cout << absolute(minResult[i][numberCount / 2 - 1 + i]);
		cout << absolute(maxResult[i][numberCount / 2 - 1 + i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> numberCount;
	for(LType i = 0; i < numberCount; i++) {
		cin >> numberArray[i];
		cin >> charArray[i];
	}
	doubleArray();
	countResult();
	printResult();
	return 0;
}
