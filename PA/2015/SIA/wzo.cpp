#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

const int MAX_N = 510000;

typedef long long int LType;

class Skos {
public:
	Skos(LType index_, LType length_, LType day_) : index(index_), length(length_), day(day_) {}	
	LType index; 
	LType length;
	LType day;
};

LType nPow, nSkos, curDay, curLength;
LType powTab[MAX_N], prefTab[MAX_N];
stack<Skos> skosStack;

void doPrefTab() {
	LType sum = 0;
	for(LType i = 0; i < nPow; i++) {
		sum += powTab[i];
		prefTab[i] = sum;
	}
}

LType getSum(LType fromIndex, LType toIndex) {
	if(fromIndex == 0) {
		return prefTab[toIndex];
	}else {
		return prefTab[toIndex] - prefTab[fromIndex - 1];
	}
}

LType getIndexAbove(LType fromIndex, LType toIndex, LType value, LType dayLength) {
	//cout << "fromIndex: " << fromIndex << "\n";
	//cout << "toIndex: " << toIndex << "\n";
	//cout << "value: " << value << "\n";
	//cout << "dayLength: " << dayLength << "\n";
	while(fromIndex < toIndex) {
		LType curIndex = (fromIndex + toIndex) / 2;
		if(powTab[curIndex] * dayLength >= value) {
			toIndex = curIndex;
		}else {
			fromIndex = curIndex + 1;
		}
	}
	return fromIndex;
}

void update() {	
	LType lastInd = nPow;
	LType lengthIndex;
	LType sum = 0;
	while(skosStack.size() > 0) {
		Skos lastSkos = skosStack.top();
		lengthIndex = getIndexAbove(lastSkos.index, lastInd, curLength - lastSkos.length, curDay - lastSkos.day);	
//		cout << "lengthIndex: " << lengthIndex << "\n";	
		if(lengthIndex < lastInd) {
			LType aboveSum = getSum(lengthIndex, lastInd - 1) * (curDay - lastSkos.day);
			LType belowSum = ((lastInd - lengthIndex) * lastSkos.length);
			LType lineSum = ((lastInd - lengthIndex) * curLength);
//			cout << "aboveSum: " << aboveSum << "\n";	
//			cout << "belowSum: " << belowSum << "\n";	
//			cout << "lineSum: " << lineSum << "\n";	
			sum += (aboveSum + belowSum - lineSum);
		}		
		if(lengthIndex > lastSkos.index) {
			break;
		}
		lastInd = lastSkos.index;
		skosStack.pop();
	}	
	skosStack.push(Skos(lengthIndex, curLength, curDay));	
//	cout << "skosStack lengthIndex: " << lengthIndex << "\n";
//	cout << "skosStack curLength: " << curLength << "\n";
//	cout << "skosStack curDay: " << curDay << "\n";	
	cout << sum << "\n";
}

void doSkos() {
	for(LType i = 0; i < nSkos; i++) {
		cin >> curDay >> curLength;
		update();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nPow >> nSkos;
	for(LType i = 0; i < nPow; i++) {
		cin >> powTab[i];
	}
	skosStack.push(Skos(0, 0, 0));
	sort(&powTab[0], &powTab[nPow]);
	doPrefTab();
	doSkos();
	return 0;
}
