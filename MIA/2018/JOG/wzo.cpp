#include <iostream>
#include <set>
using namespace std;

typedef long long int LType;
const int MAX_SIZE = 110000;

LType cowCount, timeCount, pos, speed;
LType endTime[MAX_SIZE];
multiset<LType> laneSet;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> cowCount >> timeCount;
	for(int i = 0; i < cowCount; i++) {
		cin >> pos >> speed;
		endTime[i] = pos + speed * timeCount;
	}
	for(int i = 0; i < cowCount; i++) {
		if(laneSet.empty()) {
			laneSet.insert(endTime[i]);
			continue;
		}
		set<LType>::iterator iter = laneSet.lower_bound(endTime[i]);
		if(iter == laneSet.begin()) {
			laneSet.insert(endTime[i]);
		}else {
			iter--;
			laneSet.erase(iter);
			laneSet.insert(endTime[i]);
		}
	}
	cout << laneSet.size() << "\n";
	return 0;
}
