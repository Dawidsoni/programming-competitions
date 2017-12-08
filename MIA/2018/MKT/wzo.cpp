#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int elemCount, queryCount, elem, fromInd, toInd, kthMin;
const int TREE_SIZE = (1 << 20);
vector<int> tree[TREE_SIZE * 2];
vector<int> flattenArr;
vector<int> valArr;

void addElemToTree(int elem, int pos) {
	pos += TREE_SIZE;
	while(pos > 0) {
		tree[pos].push_back(elem);
		pos /= 2;
	}
}

void sortTree() {
	for(int i = 1; i < TREE_SIZE * 2; i++) {
		sort(tree[i].begin(), tree[i].end());
	}
}

void buildTree() {
	for(int i = 0; i < elemCount; i++) {
		addElemToTree(flattenArr[i], i + 1);
	}
	sortTree();
}

int getLessEqualCount(int treeInd, int val) {
	vector<int>::iterator it = upper_bound(tree[treeInd].begin(), tree[treeInd].end(), val);
	return (it - treeInd[tree].begin());
}

int getLowerEqualCount(int fromInd, int toInd, int val) {
	fromInd += TREE_SIZE;
	toInd += TREE_SIZE;
	int result = getLessEqualCount(fromInd, val);
	if(fromInd != toInd) {
		result += getLessEqualCount(toInd, val);
	}
	while(fromInd / 2 < toInd / 2) {
		if(fromInd % 2 == 0) {
			result += getLessEqualCount(fromInd + 1, val);
		}
		if(toInd % 2 == 1) {
			result += getLessEqualCount(toInd - 1, val);
		}
		fromInd /= 2;
		toInd /= 2;
	}
	return result;
}

int handleQuery(int fromInd, int toInd, int kthMin) {
	int minVal = 0, maxVal = elemCount + 1;
	while(minVal < maxVal) {
		int middle = (minVal + maxVal) / 2;
		if(getLowerEqualCount(fromInd, toInd, middle) >= kthMin) {
			maxVal = middle;
		}else {
			minVal = middle + 1;
		}
	}
	return valArr[minVal];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> elemCount >> queryCount;
	for(int i = 0; i < elemCount; i++) {
		cin >> elem;
		flattenArr.push_back(elem);
		valArr.push_back(elem);
	}
	sort(valArr.begin(), valArr.end());
	for(int i = 0; i < (int)flattenArr.size(); i++) {
		vector<int>::iterator it = lower_bound(valArr.begin(), valArr.end(), flattenArr[i]);
		flattenArr[i] = it - valArr.begin();
	}
	buildTree();
	for(int i = 0; i < queryCount; i++) {
		cin >> fromInd >> toInd >> kthMin;
		cout << handleQuery(fromInd, toInd, kthMin) << "\n";
	}
	return 0;
}
