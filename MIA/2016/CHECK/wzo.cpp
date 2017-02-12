#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 2100;

int caseCount, boardSize;
string board[MAX_SIZE];
string boardCopy[MAX_SIZE];

string getInversed(string str) {
	string result = "";
	for(int i = 0; i < (int)str.size(); i++) {
		if(str[i] == '0') {
			result += '1';
		}else {
			result += '0';
		}
	}
	return result;
}

int countSwaps(vector<int> & posList) {
	int result = 0;
	for(int i = 0; i < (int)posList.size(); i++) {
		if(posList[i] % 2 != 0) {
			result++;
		}
	}
	return result;
}

int countRows() {
	string typeA = board[0];
	string typeB = getInversed(board[0]);
	vector<int> typeAPos, typeBPos;
	for(int i = 0; i < boardSize; i++) {
		if(board[i] == typeA) {
			typeAPos.push_back(i + 1);
		}else if(board[i] == typeB) {
			typeBPos.push_back(i + 1);			
		}else {
			return -1;
		}
	}
	if(typeAPos.size() != typeBPos.size()) {
		return -1;
	}
	//cout << "A" << countSwaps(typeAPos) << "\n" <<  "B" << countSwaps(typeBPos) << "\n";
	return min(countSwaps(typeAPos), countSwaps(typeBPos));
}

void flipBoard() {
	for(int i = 0; i < boardSize; i++) {
		boardCopy[i] = "";
		for(int j = 0; j < boardSize; j++) {
			boardCopy[i] += board[i][j];	
		}
	}
	for(int i = 0; i < boardSize; i++) {
		board[i] = "";
		for(int j = 0; j < boardSize; j++) {
			board[i] += boardCopy[j][i];
		}
	}
}

int solve() {
	int rowCount = countRows();
	if(rowCount == -1) {
		return -1;
	}
	flipBoard();
	int columnCount = countRows();
	if(columnCount == -1) {
		return -1;
	}
	return (rowCount + columnCount);	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> caseCount;
	for(int i = 0; i < caseCount; i++) {
		cin >> boardSize;
		boardSize *= 2;
		for(int j = 0; j < boardSize; j++) {
			cin >> board[j];					
		}
		int result = solve();
		if(result == -1) {
			cout << "Case #" << (i + 1) << ": IMPOSSIBLE\n";			
		}else {
			cout << "Case #" << (i + 1) << ": " << result << "\n";
		}
	}
	return 0;
}
