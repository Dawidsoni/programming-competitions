#include<iostream>
using namespace std;

typedef long long int LType;

int ingCount, compCount;
int ing1, ing2, result;
bool isOccupied[410][410];
int array[25];
int arrayCount;

void update(int x) {
	arrayCount = 0;
	int index = 1;
	while(x > 0) {		
		if(x % 2 == 1) {
			array[arrayCount] = index;
			arrayCount++;
		}
		x /= 2;
		index++;
	}
}

void checkResult() {
	for(int i = 0; i < arrayCount; i++) {
		for(int j = i + 1; j < arrayCount; j++) {
			int ind1 = array[i], ind2 = array[j];			
			if(isOccupied[min(ind1, ind2)][max(ind1, ind2)]) {
				result--;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> ingCount >> compCount;
	for(int i = 0; i <= compCount; i++) {
		cin >> ing1 >> ing2;
		isOccupied[min(ing1, ing2)][max(ing1, ing2)] = true;
	}	
	int potSize = 1;
	for(int i = 0; i < ingCount; i++) {
		potSize *= 2;
	}	
	result = potSize;	
	for(int i = 1; i < potSize; i++) {
		update(i);
		checkResult();
	}
	
	cout << result;
	return 0;
}
