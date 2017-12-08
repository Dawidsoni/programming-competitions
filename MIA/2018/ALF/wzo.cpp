#include <iostream>
#include <algorithm>
using namespace std;

string word;

int countResult(int pos, char letter, int addedCount) {
	if(letter > 'z') {
		return addedCount;
	}
	if(pos == (int)word.size()) {
		return addedCount + ('z' - letter + 1);
	}
	if(word[pos] == letter) {
		return countResult(pos + 1, letter + 1, addedCount);
	}
	int addResult = countResult(pos, letter + 1, addedCount + 1);
	for(int i = pos; i < (int)word.size(); i++) {
		if(word[i] == letter) {
			return min(addResult, countResult(i + 1, letter + 1, addedCount));
		}
	}
	return addResult;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> word;
	cout << countResult(0, 'a', 0) << "\n";
	return 0;
}
