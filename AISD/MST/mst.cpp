#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, short int> IPair;

const int MAX_SIZE = 7010;

int nVertex, nEdge, vertex1, vertex2, weight, result, edgeCount;
vector<IPair> graph[MAX_SIZE];
bool isProcessed[MAX_SIZE];
priority_queue<IPair, vector<IPair>, greater<IPair> > edgeQueue;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nVertex >> nEdge;
	for(int i = 0; i < nEdge; i++) {
		cin >> vertex1 >> vertex2 >> weight;
		graph[vertex1].push_back(IPair(weight, vertex2));
		graph[vertex2].push_back(IPair(weight, vertex1));
	}
	isProcessed[1] = true;
	for(int i = 0; i < (int)graph[1].size(); i++) {
		edgeQueue.push(graph[1][i]);
	}
	while(edgeCount + 1 < nVertex) {
		IPair edge = edgeQueue.top();
		edgeQueue.pop();
		if(isProcessed[edge.second] == false) {
			isProcessed[edge.second] = true;
			result += edge.first;
			edgeCount++;
			for(int i = 0; i < (int)graph[edge.second].size(); i++) {
				if(isProcessed[graph[edge.second][i].second] == false) {
					edgeQueue.push(graph[edge.second][i]);
				}
			}
		}
	}
	cout << result << "\n";
}
