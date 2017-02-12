#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 310000;

typedef long long int LType;

vector<vector<char> > letterArray;
string str;
int nUnderscores;
LType result;

void generateArray(vector<char> & tmpVec, int pursuitLength) {
	if((int)tmpVec.size() == pursuitLength) {
		letterArray.push_back(tmpVec);
	}else {
		tmpVec.push_back('A');
		generateArray(tmpVec, pursuitLength);
		tmpVec.pop_back();
		tmpVec.push_back('B');
		generateArray(tmpVec, pursuitLength);
		tmpVec.pop_back();
		tmpVec.push_back('L');
		generateArray(tmpVec, pursuitLength);
		tmpVec.pop_back();
	}
}

bool isVovel(char x) {
	return (x == 'A' || x == 'E' || x == 'U' || x == 'I' || x == 'O');
}

bool isCons(char x) {
	return (isVovel(x) == false);
}

bool isOk(string str) {
	for(int i = 2; i < (int)str.size(); i++) {
		if(isVovel(str[i]) && isVovel(str[i - 1]) && isVovel(str[i - 2])) {
			return false;			
		}
		if(isCons(str[i]) && isCons(str[i - 1]) && isCons(str[i - 2])) {
			return false;
		}		
	}
	for(int i = 0; i < (int)str.size(); i++) {
		if(str[i] == 'L') {
			return true;
		}
	}	
	return false;
}

bool isOk(vector<char> & letterArray) {
	int counter = 0;
	string tmpStr;
	for(int i = 0; i < (int)str.size(); i++) {
		if(str[i] == '_') {
			tmpStr += letterArray[counter];
			counter++;
		}else {
			tmpStr += str[i];
		}
	}
	return isOk(tmpStr);
}

LType getMultiplier(vector<char> & letterArray) {
	LType result = 1;
	for(int i = 0; i < (int)letterArray.size(); i++) {
		if(letterArray[i] == 'A') {
			result *= 5;
		}else if(letterArray[i] == 'B') {
			result *= 20;				
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> str;
	for(int i = 0; i < (int)str.size(); i++) {
		if(str[i] == '_') {
			nUnderscores++;
		}
	}
	vector<char> tmpVec;
	generateArray(tmpVec, nUnderscores);
	for(int i = 0; i < (int)letterArray.size(); i++) {
		LType multiplier = getMultiplier(letterArray[i]);
		if(isOk(letterArray[i])) {
			result += multiplier;
		}
	}
	cout << result << "\n";
	return 0;
}
