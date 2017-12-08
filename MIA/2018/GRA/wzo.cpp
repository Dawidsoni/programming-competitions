#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> IPair;
const int MAX_SIZE = 1010;

int fieldCount, pMoveCount[2];
int pMoveList[2][MAX_SIZE];
char boardState[2][MAX_SIZE];
bool isVisited[2][MAX_SIZE];
int visitedEdgeCount[2][MAX_SIZE];
queue<IPair> vQueue;

void readData() {
	cin >> fieldCount >> pMoveCount[0] >> pMoveCount[1];
	for(int i = 0; i < pMoveCount[0]; i++) {
		cin >> pMoveList[0][i];
	}
	for(int i = 0; i < pMoveCount[1]; i++) {
		cin >> pMoveList[1][i];
	}
}

void printState(char playerName, char state) {
	if((int)state == 0) {
		cout << "N";
	}else if(state == 'W') {
		cout << playerName;
	}else {
		char oppPlayerName = (playerName == 'A' ? 'B' : 'A');
		cout << oppPlayerName;
	}
}

void printResult() {
	for(int i = 1; i < fieldCount; i++) {
		printState('A', boardState[0][i]);
	}
	cout << "\n";
	for(int i = 1; i < fieldCount; i++) {
		printState('B', boardState[1][i]);
	}
	cout << "\n";
}

int getOppPlayer(int player) {
	return (player == 1 ? 0 : 1);
}

int getMovedVertex(int pos, int move) {
	int movedPos = (pos + move + fieldCount) % fieldCount;
	if(movedPos == 0) {
		movedPos = fieldCount;
	}
	return movedPos;
}

void processWinVertex(IPair vertex) {
	int oppPlayer = getOppPlayer(vertex.first);
	for(int i = 0; i < pMoveCount[oppPlayer]; i++) {
		int pos = getMovedVertex(vertex.second, -pMoveList[oppPlayer][i]);
		if(boardState[oppPlayer][pos] == 'W') {
			continue;
		}
		visitedEdgeCount[oppPlayer][pos]++;
		if(visitedEdgeCount[oppPlayer][pos] == pMoveCount[oppPlayer]) {
			boardState[oppPlayer][pos] = 'L';
			vQueue.push(IPair(oppPlayer, pos));
		}
	}
}

void processLoseVertex(IPair vertex) {
	int oppPlayer = getOppPlayer(vertex.first);
	for(int i = 0; i < pMoveCount[oppPlayer]; i++) {
		int pos = getMovedVertex(vertex.second, -pMoveList[oppPlayer][i]); 
		boardState[oppPlayer][pos] = 'W';
		vQueue.push(IPair(oppPlayer, pos));	
	}
}

void processVertex(IPair vertex) {
	if(isVisited[vertex.first][vertex.second]) {
		return;
	}
	isVisited[vertex.first][vertex.second] = true;
	if(boardState[vertex.first][vertex.second] == 'W') {
		processWinVertex(vertex);
	}else {
		processLoseVertex(vertex);
	}
}

void countResult() {
	vQueue.push(IPair(0, fieldCount));
	vQueue.push(IPair(1, fieldCount));
	while(vQueue.size() > 0) {
		IPair vertex = vQueue.front();
		vQueue.pop();
		processVertex(vertex);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	readData();
	countResult();
	printResult();
	return 0;
}
