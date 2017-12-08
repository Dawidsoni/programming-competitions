#include <iostream>
#include <set>
using namespace std;

const int MAX_SIZE = 110000;
const int MAX_TREE_SIZE = 1 << 18;

int treeArr[MAX_TREE_SIZE];
char operType;
int elemCount, operCount, ind, num, fromInterval, toInterval, treeSize;
set<int> zeroSet;

void initTree(int elemCount) {
	treeSize = 1;
	while(treeSize <= elemCount) {
		treeSize *= 2;
	}
	for(int i = treeSize * 2 - 1; i >= 1; i--) {
		treeArr[i] = 0;
	}
}

int getSum(int fromInterval, int toInterval) {
	fromInterval += treeSize;
	toInterval += treeSize;
	if(fromInterval == toInterval) {
		return treeArr[fromInterval];
	}
	int result = treeArr[fromInterval] + treeArr[toInterval];
	while(fromInterval / 2 < toInterval / 2) {
		if(fromInterval % 2 == 0) {
			result += treeArr[fromInterval + 1];
		}
		if(toInterval % 2 == 1) {
			result += treeArr[toInterval - 1];
		}
		fromInterval /= 2;
		toInterval /= 2;
	}
	return result;
}

char handleQuery(int fromInterval, int toInterval) {
	set<int>::iterator it = zeroSet.lower_bound(fromInterval);
	if(it != zeroSet.end() && *it <= toInterval) {
		return '0';
	}
	int minusOneSum = getSum(fromInterval, toInterval);
	if(minusOneSum % 2 == 0) {
		return '+';
	}else {
		return '-';
	}
}

void incrementTree(int ind, int count) {
	ind += treeSize;
	while(ind >= 1) {
		treeArr[ind] += count;
		ind /= 2;
	}
}

void setZeroVal(int ind) {
	if(getSum(ind, ind) == 1) {
		incrementTree(ind, -1);
	}
}

void setOneVal(int ind) {
	if(getSum(ind, ind) == 0) {
		incrementTree(ind, 1);
	}
}

void handleChange(int ind, int num) {
	if(num == 0) {
		zeroSet.insert(ind);
		setZeroVal(ind);
		return;
	}
	if(zeroSet.find(ind) != zeroSet.end()) {
		zeroSet.erase(ind);
	}	
	if(num > 0) {
		setZeroVal(ind);
	}else {
		setOneVal(ind);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	while(!cin.eof()) {
		cin >> elemCount >> operCount;
		if(cin.eof()) {
			break;
		}
		initTree(elemCount);
		for(int i = 0; i < elemCount; i++) {
			cin >> num;
			handleChange(i + 1, num);
		}
		for(int i = 0; i < operCount; i++) {
			cin >> operType;
			if(operType == 'P') {
				cin >> fromInterval >> toInterval;
				cout << handleQuery(fromInterval, toInterval);
			}else {
				cin >> ind >> num; 
				handleChange(ind, num);
			}
		}
		zeroSet.clear();
		cout << "\n";
	}
	return 0;
}
