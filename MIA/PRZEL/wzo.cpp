#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX_SIZE = 210;

class Vertex {
public:
	Vertex() {}
	Vertex(int f, int s, int t) : first(f), second(s), third(t) {}
	int first, second, third;
};

typedef pair<Vertex, int> VPair;

int first, second, third, goal;
int shortestPath[MAX_SIZE][MAX_SIZE][MAX_SIZE];
bool isCounted[MAX_SIZE][MAX_SIZE][MAX_SIZE];

void getFillEdges(int i, int j, int k, vector<Vertex> & list) {
	list[0] = Vertex(first, j, k);
	list[1] = Vertex(i, second, k);
	list[2] = Vertex(i, j, third);
}

void getLayEdges(int i, int j, int k, vector<Vertex> & list) {
	list[3] = Vertex(0, j, k);
	list[4] = Vertex(i, 0, k);
	list[5] = Vertex(i, j, 0);	
}

void getPourEdges(int i, int j, int k, vector<Vertex> & list) {	
	int maxPour = min(second - j, i);//1->2
	list[6] = Vertex(i - maxPour, j + maxPour, k);
	maxPour = min(third - k, i);//1->3
	list[7] = Vertex(i - maxPour, j, k + maxPour);
	maxPour = min(first - i, j);//2->1
	list[8] = Vertex(i + maxPour, j - maxPour, k);	
	maxPour = min(third - k, j);//2->3
	list[9] = Vertex(i, j - maxPour, k + maxPour);	
	maxPour = min(first - i, k);//3->1
	list[10] = Vertex(i + maxPour, j, k - maxPour);	
	maxPour = min(second - j, k);//3->2
	list[11] = Vertex(i, j + maxPour, k - maxPour);
}

void getEdgeList(int i, int j, int k, vector<Vertex> & list) {
	getFillEdges(i, j, k, list);
	getLayEdges(i, j, k, list);
	getPourEdges(i, j, k, list);
}

int bfs() {
	queue<VPair> vertexQueue;
	vertexQueue.push(VPair(Vertex(0, 0, 0), 0));
	vector<Vertex> neighList;
	for(int i = 0; i < 12; i++) {
		neighList.push_back(Vertex());
	}
	isCounted[0][0][0] = true;
	while((int)vertexQueue.size() > 0) {
		Vertex vertex = vertexQueue.front().first;
		int pathLength = vertexQueue.front().second;
		vertexQueue.pop();
		getEdgeList(vertex.first, vertex.second, vertex.third, neighList);
		for(int i = 0; i < (int)neighList.size(); i++) {
			if(isCounted[neighList[i].first][neighList[i].second][neighList[i].third] == false) {
				isCounted[neighList[i].first][neighList[i].second][neighList[i].third] = true;
				shortestPath[neighList[i].first][neighList[i].second][neighList[i].third] = pathLength + 1;
				vertexQueue.push(VPair(Vertex(neighList[i].first, neighList[i].second, neighList[i].third), pathLength + 1));
				if(neighList[i].first == goal || neighList[i].second == goal || neighList[i].third == goal) {
					return pathLength + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> first >> second >> third >> goal;
	int result = bfs();
	if(result == -1) {
		cout << "NIE";
	}else {
		cout << result;
	}
	return 0;
}
