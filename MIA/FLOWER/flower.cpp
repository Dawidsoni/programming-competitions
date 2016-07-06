#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

typedef pair<int, int> IPair;

const int INF = 110000000;
const int MAX_SIZE = 1100000;

int vertexLength, edgeLength, edge1, edge2, weight;
vector<IPair> graph[MAX_SIZE];
bool isCounted[MAX_SIZE];
int shortestPath[MAX_SIZE];
vector<IPair> shortestList[MAX_SIZE];
int result = 0;

void dijkstra() {
	int start = 0;
	set<IPair> minVertex;
	minVertex.insert(IPair(0, start));
	for(int i = 0; i < vertexLength; i++) {
		shortestPath[i] = INF;
	}
	shortestPath[start] = 0;
	for(int i = 0; i < vertexLength; i++) {
		while(minVertex.size() > 0 && isCounted[minVertex.begin()->second]) {
			minVertex.erase(minVertex.begin());
		}		
		if(minVertex.size() == 0) {
			break;
		}
		int curVertex = minVertex.begin()->second;
		minVertex.erase(minVertex.begin());
		isCounted[curVertex] = true;
		for(int i = 0; i < (int)graph[curVertex].size(); i++) {	
			int neighVertex = graph[curVertex][i].second;
			int edgeLength = graph[curVertex][i].first;
			if(shortestPath[curVertex] + edgeLength < shortestPath[neighVertex]) {
				shortestPath[neighVertex] = shortestPath[curVertex] + edgeLength;
				shortestList[neighVertex].clear();
				shortestList[neighVertex].push_back(IPair(edgeLength, curVertex));
				minVertex.insert(IPair(shortestPath[neighVertex], neighVertex));
			}else if(shortestPath[curVertex] + edgeLength == shortestPath[neighVertex]) {
				shortestList[neighVertex].push_back(IPair(edgeLength, curVertex));				
			}			
		}		
	}
}

void bfs() {
	for(int i = 0; i < vertexLength; i++) {
		isCounted[i] = false;
	}
	queue<int> vQueue;
	vQueue.push(vertexLength - 1);
	while(vQueue.size() > 0) {
		int curVertex = vQueue.front();
		vQueue.pop();
		isCounted[curVertex] = true;
		for(int i = 0; i < (int)shortestList[curVertex].size(); i++) {
			if(isCounted[shortestList[curVertex][i].second] == false) {
				isCounted[shortestList[curVertex][i].second] = true;
				vQueue.push(shortestList[curVertex][i].second);
			}
			result += shortestList[curVertex][i].first;
		}
		
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> vertexLength >> edgeLength;
	for(int i = 0; i < edgeLength; i++) {
		cin >> edge1 >> edge2 >> weight;
		graph[edge1].push_back(IPair(weight, edge2));
		graph[edge2].push_back(IPair(weight, edge1));
	}
	dijkstra();
	bfs();
	cout << (result * 2);
	return 0;
}
