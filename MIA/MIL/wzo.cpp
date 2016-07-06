#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

typedef pair<int, int> IPair;

const int MAX_SIZE = 900000;

set<int> indexSet;
int cowCount;
IPair cowInfo[MAX_SIZE];
int result;

void fillIndexSet() {
	for(int i = 1; i <= 11000; i++) {
		indexSet.insert(i);
	}
}

void tryAdd(int index) {
	if(indexSet.size() == 0) {
		return;
	}
	set<int>::iterator iter = indexSet.upper_bound(cowInfo[index].second);
	if(iter == indexSet.begin()) {
		return;
	}
	iter--;
	indexSet.erase(iter);
	result += cowInfo[index].first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> cowCount;
	for(int i = 0; i < cowCount; i++) {
		cin >> cowInfo[i].first >> cowInfo[i].second;
	}
	fillIndexSet();
	sort(&cowInfo[0], &cowInfo[cowCount]);
	for(int i = cowCount - 1; i >= 0; i--) {
		tryAdd(i);
	}
	cout << result;
	return 0;
}
