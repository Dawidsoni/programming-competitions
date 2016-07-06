#include<iostream>

using namespace std;

const int MAX_SIZE = 1100000;

typedef long long int LType;

LType nArray;
int array[MAX_SIZE];
int tmp[MAX_SIZE];
LType tmpCounter;

LType merge(LType fromInd, LType toInd, LType halfInd) {	
	tmpCounter = 0;
	LType leftPos = fromInd, rightPos = halfInd + 1;
	LType amount = 0;
	LType result = 0;
	while(leftPos <= halfInd || rightPos <= toInd) {
		if(leftPos > halfInd) {
			tmp[tmpCounter++] = array[rightPos++];
			amount++;
		}else if(rightPos > toInd) {
			tmp[tmpCounter++] = array[leftPos++];
			result += amount;
		}else if(array[rightPos] < array[leftPos]) {
			tmp[tmpCounter++] = array[rightPos++];
			amount++;	
		}else {
			tmp[tmpCounter++] = array[leftPos++];
			result += amount;	
		}
	}
	for(LType i = 0; i < tmpCounter; i++) {
		array[fromInd + i] = tmp[i];
	}	
	return result;
}

LType divide(LType fromInd, LType toInd) {
	if(fromInd == toInd) {
		return 0;
	}
	LType size = (toInd - fromInd);
	LType halfInd = fromInd + size / 2;
	LType left = divide(fromInd, halfInd);
	LType right = divide(halfInd + 1, toInd);
	return left + right + merge(fromInd, toInd, halfInd);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nArray;
	for(LType i = 0; i < nArray; i++) {
		cin >> array[i];		
	}
	cout << divide(0, nArray - 1);	
	return 0;
}
