#include<iostream>
#include<vector>

using namespace std;

const int MAX_SIZE = 510;
const int INF = 1000000000;

typedef pair<int, int> IPair;

int nVertex, nEdge, sVertex, vertex1, vertex2, weight;
vector<IPair> graph[MAX_SIZE];
int result[MAX_SIZE];
bool isProcessed[MAX_SIZE];

void dfs(int vertex) {
	isProcessed[vertex] = true;
	for(int i = 0; i < (int)graph[vertex].size(); i++) {
		if(isProcessed[graph[vertex][i].second] == false) {
			dfs(graph[vertex][i].second);
		}
	}
}

void bellman() {
	for(int i = 1; i <= nVertex; i++) {
		result[i] = INF;
	}
	result[sVertex] = 0;	
	for(int i = 0; i + 1 < nVertex; i++) {
		for(int j = 0; j < nVertex; j++) {
			for(int k = 0; k < (int)graph[j].size(); k++) {
				if(result[graph[j][k].second] > result[j] + graph[j][k].first) {
					result[graph[j][k].second] = result[j] + graph[j][k].first;
				}
			}
		}
	}
	dfs(sVertex);
	for(int j = 0; j < nVertex; j++) {
		for(int k = 0; k < (int)graph[j].size(); k++) {
			if(isProcessed[j] && result[graph[j][k].second] > result[j] + graph[j][k].first) {
				cout << "NIE\n";
				return;
			}
		}
	}
	for(int i = 0; i < nVertex; i++) {
		if(i != sVertex && isProcessed[i]) {
			cout << i << " " << result[i] << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nVertex >> nEdge >> sVertex;
	for(int i = 0; i < nEdge; i++) {
		cin >> vertex1 >> vertex2 >> weight;
		graph[vertex1].push_back(IPair(weight, vertex2));
	}
	bellman();
	
	return 0;
}
