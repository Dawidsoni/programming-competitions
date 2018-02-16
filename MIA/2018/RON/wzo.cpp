#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 1100;

int vCount, eCount, e1, e2;
bool isEdge1[MAX_SIZE][MAX_SIZE];
bool isEdge2[MAX_SIZE][MAX_SIZE];

void changeEdges(bool isEdge[MAX_SIZE][MAX_SIZE], int vertex) {
	for(int i = 1; i <= vCount; i++) {
		isEdge[min(vertex, i)][max(vertex, i)] = 1 - isEdge[min(vertex, i)][max(vertex, i)];
	}
}

bool isAll(bool isEdge[MAX_SIZE][MAX_SIZE]) {
	for(int i = 1; i <= vCount; i++) {
		for(int j = i + 1; j <= vCount; j++) {
			if(isEdge[i][j] == false) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> vCount >> eCount;
	for(int i = 0; i < eCount; i++) {
		cin >> e1 >> e2;
		isEdge1[min(e1, e2)][max(e1, e2)] = true;
		isEdge2[min(e1, e2)][max(e1, e2)] = true;
	}
	for(int i = 2; i <= vCount; i++) {
		if(isEdge1[1][i] == false) {
			changeEdges(isEdge1, i);
		}
	}
	if(isAll(isEdge1)) {
		cout << "DA\n";
		return 0;
	}
	changeEdges(isEdge2, 1);
	for(int i = 2; i <= vCount; i++) {
		if(isEdge2[1][i] == false) {
			changeEdges(isEdge2, i);
		}
	}
	if(isAll(isEdge2)) {
		cout << "DA\n";
	}else {
		cout << "NE\n";
	}
	return 0;
}
