#include<iostream>
#include<algorithm>
using namespace std;

class Vertex {
	Vertex* parent;
	int rank;
public:
	Vertex() {
		parent = this;
		rank = 0;
	}

	Vertex* find() {
		if(this == parent) {
			return this;
		}
		parent = parent->find();
		return parent;
	}
	
	static void vUnion(Vertex* v1, Vertex* v2) {
		if(v1->rank > v2->rank) {
			v2->parent = v1;
		}else {
			v1->parent = v2;
		}
		if(v1->rank == v2->rank) {
			v2->rank++;
		}
	}
};

class Edge {
public:
	int v1, v2;
};


const int MAX_SIZE = 510000;

int vCount, eCount, qCount;
Edge edge[MAX_SIZE];
bool isOut[MAX_SIZE];
Vertex vertex[MAX_SIZE];
int edgeAdd[MAX_SIZE];
int result;
int res[MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> vCount >> eCount >> qCount;
	result = vCount;
	for(int i = 0; i < eCount; i++) {
		cin >> edge[i].v1 >> edge[i].v2;
	}
	for(int i = 0; i < qCount; i++) {
		cin >> edgeAdd[i];
		edgeAdd[i]--;
		isOut[edgeAdd[i]] = true;
	}	
	for(int i = 0; i < eCount; i++) {
		if(isOut[i] == false) {
			Vertex* v1 = vertex[edge[i].v1].find();
			Vertex* v2 = vertex[edge[i].v2].find();
			if(v1 != v2) {
				Vertex::vUnion(v1, v2);
				result--;
			}	
		}
	}
	for(int i = qCount - 1; i >= 0; i--) {
		int vNum = edgeAdd[i];
		Vertex* v1 = vertex[edge[vNum].v1].find();	
		Vertex* v2 = vertex[edge[vNum].v2].find();	
		res[i] = result;
		if(v1 != v2) {
			Vertex::vUnion(v1, v2);
			result--;
		}
	}
	for(int i = 0; i < qCount; i++) {
		cout << res[i] << "\n";
	}
	return 0;
}
