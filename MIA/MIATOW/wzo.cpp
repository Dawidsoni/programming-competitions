#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

const int MAX_SIZE = 210000;

typedef pair<int, int> IPair;

int arrayLength;
int numberArray[MAX_SIZE];
IPair sortedArray[MAX_SIZE];
set<int> indexList;
int result[MAX_SIZE];
int maxResult;

int main() { 
	ios_base::sync_with_stdio(false);
	cin >> arrayLength;
	for(int i = 0; i < arrayLength; i++) {
		cin >> numberArray[i];
		sortedArray[i] = IPair(numberArray[i], i);
	}
	sort(sortedArray, sortedArray + arrayLength);
	for(int i = 0; i < arrayLength; i++) {
		result[sortedArray[i].second] = sortedArray[i].first;
		set<int>::iterator prev = indexList.lower_bound(sortedArray[i].second);
		set<int>::iterator next = indexList.upper_bound(sortedArray[i].second);
		if(prev != indexList.begin() && indexList.size() > 0) {
			prev--;
			int indexOffset = sortedArray[i].second - *prev;
			result[sortedArray[i].second] = min(result[sortedArray[i].second], result[*prev] + indexOffset);
		}
		if(next != indexList.end()) {
			int indexOffset = *next - sortedArray[i].second;
			result[sortedArray[i].second] = min(result[sortedArray[i].second], result[*next] + indexOffset);	
		}		
		indexList.insert(sortedArray[i].second);		
	}
	for(int i = 0; i < arrayLength; i++) {
		result[i] = min(result[i], i + 1);
		result[i] = min(result[i], arrayLength - i);
	}
	for(int i = 0; i < arrayLength; i++) {
		maxResult = max(maxResult, result[i]);
	}
	cout << maxResult << "\n";
	return 0;
}
