#include<iostream>
#include<deque>

using namespace std;

const int MAX_SIZE = 1000010;

typedef pair<int, int> IPair;

int listSize;
int numberList[MAX_SIZE];
int sumList[MAX_SIZE];

deque<IPair> numQueue;


void addElement(int elem, int ind) {
	while(numQueue.size() > 0 && numQueue.back().first > elem) {
		numQueue.pop_back();
	}
	numQueue.push_back(IPair(elem, ind));
}

void clearQueue() {
	numQueue.clear();
}

IPair getCurrentElement() {
	return *numQueue.begin();
}

void removeFirst() {
	if(numQueue.size() > 0) {
		numQueue.pop_front();
	}
}

void createSumList() {
	sumList[0] = numberList[0];
	for(int i = 1; i < listSize; i++) {
		sumList[i] = (numberList[i] + sumList[i - 1]);
	}
}

void solve() {
	for(int i = 0; i < listSize; i++) {
		addElement(sumList[i], i);
	}
	int result = 0;
	int currentPlus = 0;
	int lastSum = sumList[listSize - 1];	
	for(int i = 0; i < listSize; i++) {
		while(getCurrentElement().second <= i) {
			removeFirst();
		}
		currentPlus += numberList[i];
		addElement(lastSum + currentPlus, i + listSize);
		if(getCurrentElement().first - currentPlus >= 0) {
			result++;
		}
		//cout << lastSum + currentPlus << " ";			
	}	
	cout << result << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	while(true) {
		cin >> listSize;
		if(listSize == 0) {
			break;
		}
		for(int i = 0; i < listSize; i++) {
			cin >> numberList[i];
		}
		createSumList();
		solve();	
		clearQueue();	
	}
	
	
	return 0;
}
