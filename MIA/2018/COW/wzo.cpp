#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> IPair;

int cowCount, awardCount;
vector<IPair> awardList[30];
int cowEventList[30][30];
int dp[1 << 22];
int eventCount, pointCount, bonusCount;

int getBitCount(int num) {
	int result = 0;
	while(num > 0) {
		if(num % 2 == 1) {
			result++;
		}
		num /= 2;
	}
	return result;
}

int getAward(int pointCount, int eventCount) {
	int award = 0;
	for(int i = 0; i < (int)awardList[eventCount].size(); i++) {
		if(awardList[eventCount][i].first <= pointCount) {
			award += awardList[eventCount][i].second;
		}
	}
	return award;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> cowCount >> awardCount;
	for(int i = 0; i < awardCount; i++) {
		cin >> eventCount >> pointCount >> bonusCount;
		awardList[eventCount].push_back(IPair(pointCount, bonusCount));
	}
	for(int i = 0; i < cowCount; i++) {
		for(int j = 0; j < cowCount; j++) {
			cin >> cowEventList[i][j];	
		}
	}
	for(int i = 1; i < (1 << cowCount); i++) {
		int eventCount = getBitCount(i);
		for(int j = 0; j < cowCount; j++) {
			if((1 << j) & i) {
				dp[i] = max(dp[i], dp[i ^ (1 << j)] + cowEventList[j][eventCount - 1]);
			}
		}
		dp[i] = dp[i] + getAward(dp[i], eventCount);
	}
	cout << dp[(1 << cowCount) - 1] << "\n";
}
