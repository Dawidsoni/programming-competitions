#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> IPair;
typedef long long int LType;

int n, m, pArrCount;
IPair pArr[400];
int pow[400];
int interval[25][25];
LType result;

bool isPElem(int ind1, int ind2) {
	for(int i = 2; i <= min(ind1, ind2); i++) {
		if(ind1 % i == 0 && ind2 % i == 0) {
			return false;
		}
	}
	return true;
}

void makePArr() {
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(isPElem(i, j)) {
				pArr[pArrCount++] = IPair(i, j);
			}
		}
	}
//	for(int i = 0; i < pArrCount; i++) {
//		cout << pArr[i].first << " " << pArr[i].second << "\n";
//	}	
//	cout << pArrCount << "\n";
}

void makePow() {
	pow[0] = 1;
	for(int i = 1; i < 400; i++) {
		pow[i] = ((LType)pow[i - 1] * 2) % m;
//		cout << pow[i] << " ";
	}	
}

void makeDiv(int pos[]) {
//	for(int i = 0; i < n; i++) {
//		cout << pos[i] << " ";
//	}
//	cout << "\n";
	LType div = 1;
	int startInd = 0, divCount = 0;
	pos[n] = 1;
	for(int i = 0; i <= n; i++) {
		if(pos[i]) {
			int intervalCount = interval[startInd + 1][i];
			int elemCount = pow[intervalCount];
			startInd = i;
			div = (div * elemCount) % m;
			divCount++;
//			cout << elemCount << " ";
		}
	}
	if(div == 0) {
		div = m - 1;
	}else {
		div--;		
	}
	if(divCount % 2 == 0) {
		result -= div;
	}else {
		result += div;
	}
//	cout << "\n";
}

void makeInterval(int fromInd, int toInd) {
	for(int i = 0; i < pArrCount; i++) {
		if(pArr[i].first < fromInd || pArr[i].first > toInd) {
			continue;
		}
		if(pArr[i].second < fromInd || pArr[i].second > toInd) {
			continue;
		}
		interval[fromInd][toInd]++;
	}
}

void printInterval(int ind1, int ind2) {
	cout << "Interval " << ind1 << " -> " << ind2 << ": ";
	cout << interval[ind1][ind2] << "\n";
}

void makeIntervals() {
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			makeInterval(i, j);
//			printInterval(i, j);
		}
	}
}

void countResult(int pos[], int ind) {
	if(ind < n) {
		pos[ind] = 0;
		countResult(pos, ind + 1);
		pos[ind] = 1;
		countResult(pos, ind + 1);
	}else {
		makeDiv(pos);
	}
}

void countResult() {
	int pos[25];
	pos[0] = 0;
	countResult(pos, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	makePArr();
	makePow();
	makeIntervals();
	countResult();	
	result %= m;
	if(result < 0) {
		result = m + result;
	}
	cout << result << "\n";
	return 0;
}
