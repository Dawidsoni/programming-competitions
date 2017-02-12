#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> IPair;

const int MAX_SIZE = 45;

int arraySize, sum;
int numArray[MAX_SIZE];
vector<int> firstSumList;
vector<int> secondSumList;
int firstSumResult, secondSumResult;

void addSumList(int index, int currSum, vector<int> & sumList, int endIndex) {
	if(index < endIndex) {
		addSumList(index + 1, currSum, sumList, endIndex);
		addSumList(index + 1, currSum + numArray[index], sumList, endIndex);
	}else {
		sumList.push_back(currSum);
		sumList.push_back(currSum + numArray[index]);
	}	
}

int getHalf() {
	return arraySize/2 - 1;
}

void findSum() {
	int firstIndex = 0, secondIndex = secondSumList.size() - 1;
	while(true) {
		if(firstSumList[firstIndex] + secondSumList[secondIndex] > sum) {
			secondIndex--;
		}else if(firstSumList[firstIndex] + secondSumList[secondIndex] < sum) {
			firstIndex++;
		}else {
			firstSumResult = firstSumList[firstIndex];
			secondSumResult = secondSumList[secondIndex];
			break;
		}
	}
}

string findResult(int index, int currSum, int endIndex, int goalSum) {
	if(index < endIndex) {
		string s1 = findResult(index + 1, currSum, endIndex, goalSum);
		if(s1 != "") {
			return s1 + "0";
		}
		string s2 = findResult(index + 1, currSum + numArray[index], endIndex, goalSum);
		if(s2 != "") {
			return s2 + "1";
		}
	}else {
		if(currSum == goalSum) {
			return "0";
		}else if(currSum + numArray[index] == goalSum) {
			return "1";
		}else {
			return "";
		}
	}
	return "";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> arraySize;
	for(int i = 0; i < arraySize; i++) {
		cin >> numArray[i];
	}
	cin >> sum;
	addSumList(0, 0, firstSumList, getHalf());
	addSumList(getHalf() + 1, 0, secondSumList, arraySize - 1);
	sort(firstSumList.begin(), firstSumList.end());
	sort(secondSumList.begin(), secondSumList.end());
	findSum();
	string str1 = findResult(0, 0, getHalf(), firstSumResult);
	string str2 = findResult(getHalf() + 1, 0, arraySize - 1, secondSumResult);
	for(int i = str1.size() - 1; i >= 0; i--) {
		cout << str1[i];
	}
	for(int i = str2.size() - 1; i >= 0; i--) {
		cout << str2[i];
	}
	return 0;
}
