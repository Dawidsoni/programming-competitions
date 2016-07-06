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
		
	static void unionV(Vertex* v1, Vertex* v2) {
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
	int num, v1, v2, weight;
	
	friend bool operator<(const Edge& e1, const Edge& e2) {
		if(e1.weight == e2.weight) {
			return e1.num < e2.num;
		}
		return e1.weight < e2.weight;
	}

};

const int MAX_SIZE = 310000;

int vCount, eCount;
int curResult;
Edge edge[MAX_SIZE];
Vertex vertex[MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> vCount >> eCount;
	for(int i = 0; i < eCount; i++) {
		cin >> edge[i].v1 >> edge[i].v2 >> edge[i].weight;
		edge[i].num = i + 1;
	}
	sort(edge, edge + eCount);
	for(int i = 0; i < eCount && curResult + 1 < vCount; i++) {
		Vertex* v1 = vertex[edge[i].v1].find();
		Vertex* v2 = vertex[edge[i].v2].find();
		if(v1 != v2) {
			Vertex::unionV(v1, v2);
			cout << edge[i].num << "\n";
		}
	}
	return 0;
}
