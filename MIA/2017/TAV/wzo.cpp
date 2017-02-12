#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 600;

int wordLen, holeCount, letterCount, findNum;
string word;
string lettProp[MAX_SIZE];
char holeLett[MAX_SIZE];

void sortLett(string& lett) {
	int charCount[30];
	for(int i = 0; i < 30; i++) {
		charCount[i] = 0;
	}
	for(int i = 0; i < (int)lett.size(); i++) {
		charCount[lett[i] - 'a']++;
	}
	int counter = 0;
	for(int i = 0; i < 30; i++) {
		for(int j = 0; j < charCount[i]; j++) {
			lett[counter] = ('a' + i);
			counter++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> wordLen >> holeCount >> letterCount >> findNum;
	cin >> word;
	for(int i = 0; i < holeCount; i++) {
		cin >> lettProp[i];		
		sortLett(lettProp[i]);			
	}	
	findNum--;
	for(int i = 0; i < holeCount; i++) {
		int num = findNum % letterCount;
		findNum -= num;
		findNum /= letterCount;			
		holeLett[i] = lettProp[holeCount - i - 1][num];
	}
	int counter = 0;
	for(int i = 0; i < wordLen; i++) {
		if(word[i] == '#') {
			word[i] = holeLett[holeCount - counter - 1];
			counter++;
		}
	}
	cout << word;
	return 0;
}
