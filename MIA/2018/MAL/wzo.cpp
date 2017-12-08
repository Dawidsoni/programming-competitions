#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int LType;
typedef pair<LType, LType> IPair;
LType wallSize, artistCount, fromInterval, toInterval;
vector<IPair> artistList;
map<LType, LType> dp;

LType getEndResult(IPair interval) {
	map<LType, LType>::iterator it = dp.lower_bound(interval.first);
	if(it == dp.begin()) {
		return (interval.first - 1);
	}
	it--;
	return it->second + (interval.first - it->first - 1);  
}

void updateDp(LType fromInd, LType toInd) {
	LType endSize = artistList[fromInd].first; 
	LType dpResult = getEndResult(IPair(endSize, endSize)) + 1;
	for(int i = fromInd; i <= toInd; i++) {
		dpResult = min(dpResult, getEndResult(IPair(artistList[i].second, artistList[i].first)));
	}
	dp[endSize] = dpResult;
}

int main() {
	cin >> wallSize >> artistCount;
	artistList.reserve(artistCount + 1);
	for(int i = 0; i < artistCount; i++) {
		cin >> fromInterval >> toInterval;
		artistList.push_back(IPair(toInterval, fromInterval));
	}
	sort(artistList.begin(), artistList.end());
	LType lastIndex = 0;
	LType lastEnd = artistList[0].first;
	for(int i = 0; i < (int)artistList.size(); i++) {
		if(artistList[i].first != lastEnd) {
			updateDp(lastIndex, i - 1);
			lastIndex = i;
			lastEnd = artistList[i].first;
		}
		if(i + 1 == (int)artistList.size()) {
			updateDp(lastIndex, i);
		}
	}
	map<LType, LType>::iterator it = dp.end();
	it--;
	LType result = it->second + (wallSize - it->first);
	cout << result << "\n";
	return 0;
}
