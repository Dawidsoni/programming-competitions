#include<iostream>
using namespace std;

const int MAX_SIZE = 2100000;

int count;
string str1, str2;
int pref[MAX_SIZE];

void reverseArr(string& str) {
	string tmpStr;
	for(int i = count - 1; i >= 0; i--) {
		if(str[i] == 'E') {
			tmpStr.push_back('W');
		}else if(str[i] == 'W') {
			tmpStr.push_back('E');
		}else if(str[i] == 'N') {
			tmpStr.push_back('S');
		}else if(str[i] == 'S') {
			tmpStr.push_back('N');
		}
	}
	str = tmpStr;
}

int prefixFunc(string str) {
	int ind = 0;
	for(int i = 1; i < (int)str.size(); i++) { 
		while(ind > 0 && str[i] != str[ind]) {
			ind = pref[ind - 1];
		}
		if(str[i] == str[ind]) {
			ind++;
		}
		pref[i] = ind;
	}
	return pref[str.size() - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> count;
	cin >> str1 >> str2;
	reverseArr(str2);
	int pref = prefixFunc(str2 + '#' + str1);
	if(pref == 0) {
		cout << "YES\n";
	}else {
		cout << "NO\n";
	}
	return 0; 
}
