#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 1100000;

typedef long long int LType;
typedef pair<LType, int> IPair;

int pairCount, twineLength, twineCount;
int result;
IPair twineArray[MAX_SIZE];
IPair twineQueue[MAX_SIZE];
int queueSize, queueFront;

int qSize() {
	return queueSize - queueFront;
}

IPair qFront() {
	return twineQueue[queueFront];
}

void qAdd(IPair twine) {
	twineQueue[queueSize++] = twine;
}

void qPop() {
	queueFront++;
}

void resetQueue() {
	int index = 0;
	for(int i = queueFront; i < queueSize; i++) {
		twineQueue[index++] = twineQueue[i];
	}
	queueSize = index;
	queueFront = 0;
}

void addTwine(IPair twine) {
	if(twine.second % 2 == 1) {
		result++;
	}
	if(twine.second == 1) {
		return;
	}
	twine.first *= 2;
	twine.second /= 2;
	qAdd(twine);
	if(queueSize >= MAX_SIZE) {
		resetQueue();
	}
}

void countResult() {
	int index = 0;
	while(index < pairCount) {
		while(qSize() > 0 && qFront().first == twineArray[index].first) {
			twineArray[index].second += qFront().second;
			qPop();
		}
		if(qSize() > 0 && qFront().first < twineArray[index].first) {
			addTwine(qFront());
			qPop();			
		}else {
			addTwine(twineArray[index]);
			index++;
		}
	}
}

void copyQueue() {
	pairCount = 0;
	while(qSize() > 0) {
		twineArray[pairCount] = qFront();
		qPop();
		pairCount++;
	}
	queueSize = queueFront = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> pairCount;
	for(int i = 0; i < pairCount; i++) {
		cin >> twineLength >> twineCount;
		twineArray[i] = IPair(twineLength, twineCount);
	}
	sort(twineArray, twineArray + pairCount);
	while(pairCount > 0) {
		countResult();
		copyQueue();
	}
	cout << result << "\n";
	return 0;
}
