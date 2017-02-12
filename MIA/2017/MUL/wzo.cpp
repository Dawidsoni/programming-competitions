#include <iostream>
using namespace std;

string text;
int count[30];
int curCount[30];

int toInt(char s) {
	return s - 'a';
}

void resetCount() {
	for(int i = 0; i < 30; i++) {
		count[i] = 0;
	}
}

void resetCurCount() {
	for(int i = 0; i < 30; i++) {
		curCount[i] = 0;
	}
}

bool isDatagram(int val) {
	if((int)text.size() % val != 0) {
		return false;
	}
	resetCount();
	resetCurCount();	
	for(int i = 0; i < val; i++) {
		count[toInt(text[i])]++;
	}
	for(int i = 0; i < (int)text.size(); i += val) {
		for(int j = i; j < i + val; j++) {
			curCount[toInt(text[j])]++;			
		}
		for(int i = 0; i < 30; i++) {
			if(count[i] != curCount[i]) {
				return false;
			}
		}		
		resetCurCount();
	}
	return true;
}

int getResult() {
	for(int i = 1; i < (int)text.size(); i++) {
		if(isDatagram(i)) {
			return i;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> text;
	int result = getResult();
	if(result == -1) {
		cout << result << "\n";
	}else {
		for(int i = 0; i < result; i++) {
			cout << text[i];
		}
	}
	return 0;
}
