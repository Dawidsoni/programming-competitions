#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_SIZE = 210;
const int MAX_RESULT = 1100000000;

int nTest, nPrisoners, nReleases, release;
int result[MAX_SIZE][MAX_SIZE];

void clearResult() {
	for(int i = 0; i < MAX_SIZE; i++) {
		for(int j = 0; j < MAX_SIZE; j++) {
			result[i][j] = 0;
		}
	}
}

int getIntervalValue(vector<int> & releases, int fromInd, int toInd) {
	if(fromInd + 2 == toInd) {
		return releases[toInd] - releases[fromInd] - 2;
	}
	int intervalValue = MAX_RESULT;
	for(int i = fromInd + 1; i < toInd; i++) {
		intervalValue = min(intervalValue, result[fromInd][i] + result[i][toInd]);
	}
	return intervalValue + releases[toInd] - releases[fromInd] - 2;
}

void solve(int counter, vector<int> & releases) {
	clearResult();
	for(int width = 2; width < (int)releases.size(); width++) {
		for(int i = 0; i + width < (int)releases.size(); i++) {
			result[i][i + width] = getIntervalValue(releases, i, i + width);
			//cout << "i =  " << i << " j = " << (i + width) << "result = " << result[i][i + width] << "\n";
		}
	}
	cout << "Case #" << counter << ": " << result[0][releases.size() - 1] << "\n";
}

void readData(int counter) {
	cin >> nPrisoners >> nReleases;
	vector<int> releases;
	releases.push_back(0);
	for(int i = 0; i < nReleases; i++) {
		cin >> release;
		releases.push_back(release);
	}
	releases.push_back(nPrisoners + 1);
	solve(counter, releases);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		readData(i + 1);
	}	
	return 0;
}
