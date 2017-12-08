#include <iostream>
#include <map>
using namespace std;

const int MOD_NUM = 2014;

map<string, int> dp;
string word;

int calculateDp(string word) {
	if(dp.find(word) != dp.end()) {
		return dp[word];
	}
	int result = 1;
	int wordSize = word.size();
	for(int i = 1; i * 2 < wordSize; i++) {
		if(word.substr(0, i) == word.substr(wordSize - i)) {
			result += calculateDp(word.substr(0, wordSize - i));
			result += calculateDp(word.substr(i));
		}
		if(word.substr(wordSize - i) == word.substr(wordSize - 2 * i, i)) {
			result += calculateDp(word.substr(0, wordSize - i));
		}
		if(word.substr(0, i) == word.substr(i, i)) {
			result += calculateDp(word.substr(i));
		}
	}
	dp[word] = result % MOD_NUM;
	return dp[word];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> word;
	int result = calculateDp(word); 
	if(result == 0) {
		result = MOD_NUM - 1;
	}else {
		result--;
	}
	cout << result << "\n";
	return 0;
}
