#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX_SIZE = 8000;

int length;
int nMnieZna[MAX_SIZE];
int nZnam[MAX_SIZE];
int resultCount;
int resultArray[MAX_SIZE];
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> length;
	for(int i = 0; i < length; i++) {
		cin >> str;
		for(int j = 0; j < (int)str.size(); j++) {
			if(str[j] == '1') {
				nZnam[i]++;
				nMnieZna[j]++;
			}
		}
	}
	for(int i = 0; i < length; i++) {
		if(nMnieZna[i] == length && nZnam[i] == 1) {
			resultArray[resultCount] = (i + 1);
			resultCount++;
		}
	}
	cout << resultCount << "\n";
	for(int i = 0; i < resultCount; i++) {
		cout << resultArray[i] << "\n";
	}
	
	return 0;
}

