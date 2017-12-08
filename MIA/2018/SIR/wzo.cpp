#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int LType;
typedef pair<int, int> IPair;
const int MAX_NODE = 10000010;
const int MAX_NODE_COUNT = 1000010;

class Node {
	int rank;
	Node* parent; 

public:
	Node() {
		rank = 1;		
		parent = this;
	}

	Node* find() {
		if(parent == this) {
			return this;
		}
		parent = parent->find();
		return parent;
	}	

	static void nodeUnion(Node* node1, Node* node2) {
		node1 = node1->find();
		node2 = node2->find();
		if(node1->rank > node2->rank) {
			node2->parent = node1;
		}else {
			node1->parent = node2;
			if(node1->rank == node2->rank) {
				node2->rank++;
			}
		}
	}
};

int nodeCount, node;
set<int> nodeSet;
vector<IPair> edgeList;
Node nodeList[MAX_NODE];
vector<IPair> cArr[MAX_NODE];
LType result;

int nodeWeight(IPair node) {
	if(node.first < node.second) {
		return (node.second % node.first);
	}
	return (node.first % node.second);
}

void fillEdgeList(int node) {
	for(int i = node; i <= MAX_NODE; i += node) {
		set<int>::iterator nodeIt = nodeSet.lower_bound(max(i, node + 1));
		if(nodeIt == nodeSet.end()) {
			break;
		}
		if(*nodeIt >= i + node) {
			continue;
		}
		edgeList.push_back(IPair(node, *nodeIt));
	}	
}

void fillEdgeList() {
	for(set<int>::iterator nodeIt = nodeSet.begin(); nodeIt != nodeSet.end(); nodeIt++) {
		fillEdgeList(*nodeIt);
	}
}

void sortEdgeList() {
	for(int i = 0; i < (int)edgeList.size(); i++) {
		cArr[nodeWeight(edgeList[i])].push_back(edgeList[i]);
	} 
	edgeList.clear();
	for(int i = 0; i < MAX_NODE; i++) {
		for(int j = 0; j < (int)cArr[i].size(); j++) {
			edgeList.push_back(cArr[i][j]);
		}
	}
}

void buildTree() {
	for(int i = 0; i < (int)edgeList.size(); i++) {
		IPair edge = edgeList[i];
		if(nodeList[edge.first].find() != nodeList[edge.second].find()) {
			Node::nodeUnion(&nodeList[edge.first], &nodeList[edge.second]);		
			result += nodeWeight(edge);
		}
	}		
}

int main() {
	cin >> nodeCount;
	for(int i = 0; i < nodeCount; i++) {
		cin >> node;
		nodeSet.insert(node);
	}
	fillEdgeList();
	sortEdgeList();
	buildTree();
	cout << result << "\n";
    return 0;
}
