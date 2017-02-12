#include<iostream>
#include<set>
using namespace std;

const int MAX_SIZE = 210;

int timeCount;
int timeArray[MAX_SIZE];

bool isOk(int cameraCount) {
	int currentTime = 0;
	multiset<int> cameraDeadline;
	for(int i = 1; i < cameraCount; i++) {
		cameraDeadline.insert(0);
	}
	cameraDeadline.insert(60);		
	for(int i = 0; i + 1 < timeCount; i++) {
		currentTime += timeArray[i];
		if((*cameraDeadline.begin()) <= currentTime) {
			cameraDeadline.erase(cameraDeadline.begin());
			cameraDeadline.insert(currentTime + 60);
		}else {
			return false;
		}		
	}
	return true;	
}

void countResult() {
	int fromInd = 1, toInd = timeCount + 1;
	while(fromInd < toInd) {
		int aver = (fromInd + toInd) / 2;
		if(isOk(aver)) {
			toInd = aver;
		}else {
			fromInd = aver + 1;
		}		
	}
	cout << toInd << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	while(true) {
		cin >> timeCount;
		if(timeCount == 0) {
			break;
		}
		for(int i = 0; i + 1 < timeCount; i++) {
			cin >> timeArray[i];
		}
		countResult();
	}
	return 0;
}
