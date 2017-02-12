#include<iostream>
using namespace std;

bool isWrong[1100];
int result;
int wordCount;
string wordList[1100];
string letterPress;

bool isOk(char letter, int key) {
	if(key == 2) {
		return (letter >= 'a' && letter <= 'c');
	}else if(key == 3) {
		return (letter >= 'd' && letter <= 'f');		
	}else if(key == 4) {
		return (letter >= 'g' && letter <= 'i');		
	}else if(key == 5) {
		return (letter >= 'j' && letter <= 'l');		
	}else if(key == 6) {
		return (letter >= 'm' && letter <= 'o');		
	}else if(key == 7) {
		return (letter >= 'p' && letter <= 's');		
	}else if(key == 8) {
		return (letter >= 't' && letter <= 'v');		
	}else if(key == 9) {
		return (letter >= 'w' && letter <= 'z');		
	}
	return true;
} 

void updateDictionary(int pos, int key) {
	for(int i = 0; i < wordCount; i++) {
		if(isOk(wordList[i][pos], key) == false) {
			isWrong[i] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> wordCount;
	for(int i = 0; i < wordCount; i++) {
		cin >> wordList[i];
	}
	cin >> letterPress;
	for(int i = 0; i < (int)letterPress.size(); i++) {
		updateDictionary(i, letterPress[i] - '0');
	}
	for(int i = 0; i < wordCount; i++) {
		if(isWrong[i] == false) {
			result++;
		}
	}
	cout << result;
	return 0;
}
