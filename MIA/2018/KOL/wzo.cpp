#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 510000;

int nodeCount, node1, node2;
vector<int> tree[MAX_SIZE];
int nodeColor[MAX_SIZE];
bool isVisited[MAX_SIZE];
int root1, root2;

void dfs(int vertex) {
	isVisited[vertex] = true;
	for(int i = 0; i < (int)tree[vertex].size(); i++) {
		if(isVisited[tree[vertex][i]]) {
			continue;
		}
		if(nodeColor[vertex] != nodeColor[tree[vertex][i]]) {
			root1 = vertex;
			root2 = tree[vertex][i];
		}
		dfs(tree[vertex][i]);
	}
}

bool isColorSubtree(int node, int color) {
	isVisited[node] = true;
	if(nodeColor[node] != color) {
		return false;
	}
	for(int i = 0; i < (int)tree[node].size(); i++) {
		if(isVisited[tree[node][i]] == false) {
			bool result = isColorSubtree(tree[node][i], color);
			if(result == false) {
				return false;
			}
		}
	}
	return true;
}

bool checkIfRoot(int node) {
	for(int i = 1; i <= nodeCount; i++) {
		isVisited[i] = false;
	}
	isVisited[node] = true;
	for(int i = 0; i < (int)tree[node].size(); i++) {
		if(isColorSubtree(tree[node][i], nodeColor[tree[node][i]]) == false) {
			return false;
		}
	}
	return true;
}

bool countResult() {
	if(root1 == 0 || root2 == 0) {
		return true;
	}
	return (checkIfRoot(root1) || checkIfRoot(root2));	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nodeCount;
	for(int i = 0; i < nodeCount - 1; i++) {
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	for(int i = 1; i <= nodeCount; i++) {
		cin >> nodeColor[i];
	}
	dfs(1);
	if(countResult()) {
		cout << "TAK\n";
	}else {
		cout << "NIE\n";
	}
	return 0;
}
