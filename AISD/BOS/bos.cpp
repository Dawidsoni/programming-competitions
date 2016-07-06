#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 1100000;

int nVertex, nEdge, nQuery;
int v1, v2;

vector<int> graph[MAX_SIZE];
int indeg[MAX_SIZE];
int preOrder[MAX_SIZE];
int postOrder[MAX_SIZE];
int currentNum;

void dfs(int vertex) {
	preOrder[vertex] = currentNum++;
	for(int i = 0; i < (int)graph[vertex].size(); i++) {
		dfs(graph[vertex][i]);
	}
	postOrder[vertex] = currentNum++;
}

bool isD(int v1, int v2) {
	return (preOrder[v1] < preOrder[v2] && postOrder[v2] < postOrder[v1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nVertex >> nEdge;
	for(int i = 0; i < nEdge; i++) {
		cin >> v1 >> v2;
		indeg[v2]++;
		graph[v1].push_back(v2);
	}
	for(int i = 1; i <= nVertex; i++) {
		if(indeg[i] == 0) {
			dfs(i);
		}
	}
	cin >> nQuery;
	for(int i = 0; i < nQuery; i++) {
		cin >> v1 >> v2;
		bool isDesc = isD(v1, v2);
		if(isDesc) {
			cout << "TAK\n";
		}else {
			cout << "NIE\n";
		}
	}
	return 0;
}
