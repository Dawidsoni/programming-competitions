#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> IPair;

int nVertex, nEdge, nGoal;
int vertex1, vertex2, dist, result;

const int MAX_V_COUNT = 110000;
const int INF = 2100000000;

vector<IPair> graph[MAX_V_COUNT];
int goalList[MAX_V_COUNT];
int minDist[MAX_V_COUNT];
bool isCounted[MAX_V_COUNT];

void readData() {
	cin >> nVertex >> nEdge >> nGoal;
	for(int i = 0; i < nEdge; i++) {
		cin >> vertex1 >> vertex2 >> dist;
		graph[vertex1].push_back(IPair(vertex2, dist));
		graph[vertex2].push_back(IPair(vertex1, dist));		
	}
	for(int i = 0; i < nGoal; i++) {
		cin >> goalList[i];
	}	
}

void dijkstra(int sVertex) {
	priority_queue<IPair> distQueue;
	for(int i = 1; i <= nVertex; i++) {
		minDist[i] = INF;
	}
	minDist[sVertex] = 0;
	distQueue.push(IPair(0, sVertex));
	while(distQueue.size() > 0) {
		while(distQueue.size() > 0 && isCounted[distQueue.top().second]) {
			distQueue.pop();
		}
		if(distQueue.empty()) {
			break;
		}
		int vertex = distQueue.top().second;
		isCounted[vertex] = true;
		for(int i = 0; i < (int)graph[vertex].size(); i++) {
			if(isCounted[graph[vertex][i].first]) {
				continue;
			}
			if(minDist[vertex] + graph[vertex][i].second < minDist[graph[vertex][i].first]) {
				minDist[graph[vertex][i].first] = minDist[vertex] + graph[vertex][i].second;
				distQueue.push(IPair(-minDist[graph[vertex][i].first], graph[vertex][i].first));
			}			
		}		
	}
}

bool countResult() {
	for(int i = 0; i < nGoal; i++) {
		if(minDist[goalList[i]] == INF) {
			return false;
		}
		result += minDist[goalList[i]];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	readData();
	dijkstra(1);
	if(countResult()) {
		cout << (result * 2) << "\n";			
	}else {
		cout << "NIE\n";
	}
	return 0;
}
