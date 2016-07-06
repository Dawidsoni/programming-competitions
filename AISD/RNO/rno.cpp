#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 110000;

int nVertex, nEdge, v1, v2;
int result[MAX_SIZE];
vector<int> graph[MAX_SIZE];
bool isProcessed[MAX_SIZE];

int dfs(int vertex) {
	isProcessed[vertex] = true;
	for(int i = 0; i < (int)graph[vertex].size(); i++) {
		if(isProcessed[graph[vertex][i]] == false) {
			result[vertex] += dfs(graph[vertex][i]);
		}
	}
	result[vertex]++;
	return result[vertex];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nVertex >> nEdge;
	for(int i = 0; i < nEdge; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for(int i = 1; i <= nVertex; i++) {
		if(isProcessed[i] == false) {
			dfs(i);
		}
	}
	for(int i = 1; i <= nVertex; i++) {
		cout << result[i] << " ";
	}
	
	return 0;
}
