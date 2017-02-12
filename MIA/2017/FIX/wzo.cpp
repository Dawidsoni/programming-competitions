#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> IPair;

const int MAX_SIZE = 55;
int nRow, nCol;
char board[MAX_SIZE][MAX_SIZE];
bool isOcc[MAX_SIZE][MAX_SIZE];
int l_pos[MAX_SIZE], r_pos[MAX_SIZE], u_pos[MAX_SIZE], d_pos[MAX_SIZE];

void resetOcc() {
	for(int i = 0; i < nRow; i++) {
		for(int j = 0; j < nCol; j++) {
			isOcc[i][j] = false;
		}
	}
}

bool isNeighFree(IPair point, int xOff, int yOff) {
	int xCoord = point.first + xOff;
	int yCoord = point.second + yOff;
	if(xCoord < 0 || xCoord >= nRow) {
		return false;
	}
	if(yCoord < 0 || yCoord >= nCol) {
		return false;
	}
	return board[xCoord][yCoord] == '#' && isOcc[xCoord][yCoord] == false;
}

void updateQueue(IPair point, queue<IPair> & vQueue, int xOff, int yOff) {
	if(isNeighFree(point, xOff, yOff)) {
		int xCoord = point.first + xOff;
		int yCoord = point.second + yOff;
		isOcc[xCoord][yCoord] = true;
		vQueue.push(IPair(xCoord, yCoord));
	}	
}

void resetPos() {
	for(int i = 0; i < nRow; i++) {
		l_pos[i] = nCol;
		r_pos[i] = 0;
	}
	for(int i = 0; i < nCol; i++) {
		u_pos[i] = nRow;
		d_pos[i] = 0;
	}	
}

bool bfs(int stRow, int stCol) {
	queue<IPair> vQueue;
	bool result = false;
	vQueue.push(IPair(stRow, stCol));
	isOcc[stRow][stCol] = true;
	resetPos();
	while(vQueue.empty() == false) {
		IPair point = vQueue.front();
		vQueue.pop();
		int xC = point.first, yC = point.second;
		updateQueue(point, vQueue, 1, 0);
		updateQueue(point, vQueue, -1, 0);
		updateQueue(point, vQueue, 0, 1);
		updateQueue(point, vQueue, 0, -1);
		l_pos[xC] = min(l_pos[xC], yC);
		r_pos[xC] = max(r_pos[xC], yC);
		u_pos[yC] = min(u_pos[yC], xC);
		d_pos[yC] = max(d_pos[yC], xC);
	}
	for(int i = 0; i < nRow; i++) {
		if(l_pos[i] != nCol) {
			for(int j = l_pos[i]; j <= r_pos[i]; j++) {
				if(board[i][j] != '#') {
					result = true;
				}
				board[i][j] = '#';
			}
		}
	}
	for(int i = 0; i < nCol; i++) {
		if(u_pos[i] != nRow) {
			for(int j = u_pos[i]; j <= d_pos[i]; j++) {
				if(board[j][i] != '#') {
					result = true;
				}
				board[j][i] = '#';
			}
		}
	}
	return result;
}

bool makeSmooth() {
	bool isSmooth = false;
	while(isSmooth == false) {
		isSmooth = true;
		resetOcc();		
		for(int i = 0; i < nRow; i++) {
			for(int j = 0; j < nCol; j++) {
				if(isOcc[i][j] == false && board[i][j] == '#') {
					if(bfs(i, j)) {
						isSmooth = false;
					}
				}
			}
		}
	}	
	return 0;
}

int main() {
	cin >> nRow >> nCol;
	for(int i = 0; i < nRow; i++) {
		for(int j = 0; j < nCol; j++) {
			cin >> board[i][j];
		}
	}
	while(makeSmooth()) {}
	for(int i = 0; i < nRow; i++) {
		for(int j = 0; j < nCol; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}	
}
