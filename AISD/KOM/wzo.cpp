#include<iostream>

using namespace std;

class Node {
public:
	Node(int nodeId, int nodeKey) : parent(NULL), child(NULL), left(NULL), right(NULL), 
									mark(false), degree(0), id(nodeId), key(nodeKey) {}

	Node* parent, *child, *left, *right;
	bool mark;
	int degree, id, key;
};

class FibHeap {	
	int rootCount;
	Node* minRoot;
	Node* nodeArray[60];
	
	void setRoot(Node* node) {
		minRoot = node;
		node->left = node->right = node;
	}
	
	void insertNode(Node* root, Node* node) {
		Node* right = root->right;
		root->right = node;
		node->left = root;
		right->left = node;
		node->right = right;		
	}
	
	void insertRoot(Node* node) {
		insertNode(minRoot, node);
	}
	
	void addToRootList(Node* node) {
		if(node == NULL) {
			return;
		}
		Node* endNode = node;
		do {
			Node* rightNode = node->right;
			node->parent = NULL;
			insertRoot(node);			
			node = rightNode;
		}while(node != endNode);		
	}
	
	void deleteNode(Node* node) {		
		Node* right = node->right;
		Node* left = node->left;
		right->left = left;
		left->right = right;
	}
	
	void addChild(Node* node, Node* child) {
		node->degree++;
		child->parent = node;
		if(node->child == NULL) {
			node->child = child;
			child->left = child->right = child;
			return;
		}
		insertNode(node->child, child);		
	}
	
	void linkRoots(Node* node, Node* swapNode) {
		deleteNode(swapNode);
		addChild(node, swapNode);
		swapNode->mark = false;		
	}
	
	void reloadRootList() {
		minRoot = NULL;
		rootCount = 0;
		for(int i = 0; i < 60; i++) {
			if(nodeArray[i] == NULL) {
				continue;
			}
			insert(nodeArray[i]);			
		}		
	}
		
	void consolidate() {
		for(int i = 0; i < 60; i++) {
			nodeArray[i] = NULL;
		}
		Node* node = minRoot;	
		Node* nodeEnd = minRoot->left;		
		while(true) {
			Node* curNode = node;
			Node* rightNode = node->right;
			int degree = node->degree;
			while(nodeArray[degree] != NULL) {
				Node* swapNode = nodeArray[degree];
				if(node->key > swapNode->key) {
					swap(node, swapNode);
				}
				linkRoots(node, swapNode);
				nodeArray[degree] = NULL;
				degree++;				
			}
			nodeArray[degree] = node;		
			if(curNode == nodeEnd) {
				break;
			}	
			node = rightNode;
		}		
		reloadRootList();		
	}
	
	void cut(Node* node, Node* parent) {
		if(node->right == node) {
			parent->child = NULL;
		}else {
			deleteNode(node);			
			parent->child = node->right;
		}		
		parent->degree--;
		insert(node);
		node->parent = NULL;
		node->mark = false;
	}
	
	void cascadingCut(Node* node) {
		Node* parent = node->parent;
		if(parent == NULL) {
			return;
		}
		if(node->mark == false) {
			node->mark = true;
		}else {
			cut(node, parent);
			cascadingCut(parent);
		}
	}
	
public:
	FibHeap() : rootCount(0), minRoot(NULL) {}
	
	void insert(Node* node) {
		rootCount++;
		if(minRoot == NULL) {
			setRoot(node);
			return;
		}
		insertRoot(node);
		if(node->key < minRoot->key) {
			minRoot = node;
		}
	}
	
	int getMin() {
		if(minRoot != NULL) {
			return minRoot->key;
		}
		return -1;
	}
	
	int extractMin() {
		if(minRoot == NULL) {
			return -1;
		}
		Node* node = minRoot;
		addToRootList(node->child);
		deleteNode(node);
		if(node->right == node) {
			minRoot = NULL;
			rootCount = 0;
		}else {
			minRoot = node->right;
			consolidate();
		}
		return node->id;
	}	
	
	void decreaseKey(Node* node, int key) {
		if(key > node->key) {
			return;
		}
		node->key = key;
		Node* parent = node->parent;
		if(parent != NULL && node->key < parent->key) {
			cut(node, parent);
			cascadingCut(parent);
		}
		if(node->key < minRoot->key) {
			minRoot = node;
		}
	}
};

int nVertex, nEdge, nGoal;
int vertex1, vertex2, dist, result;

const int MAX_V_COUNT = 100001;
const int MAX_E_COUNT = 1000001;
const int INF = 2100000000;

int* minDist;
bool* isCounted;
int goalList[MAX_V_COUNT];
Node* nodeArray[MAX_V_COUNT];
int* vertexList[MAX_V_COUNT];
short int* distList[MAX_V_COUNT];
int vertexCountList[MAX_V_COUNT];
int vertexSizeList[MAX_V_COUNT];

void createGraph(int* v1List, int* v2List, short int* dList) {
	for(int i = 1; i <= nVertex; i++) {
		if(vertexCountList[i] > 0) {
			vertexList[i] = new int[vertexCountList[i]];
			distList[i] = new short int[vertexCountList[i]];
		}
	}
	for(int i = 0; i < nEdge; i++) {
		int v1 = v1List[i], v2 = v2List[i], dist = dList[i];		
		int v1Size = vertexSizeList[v1], v2Size = vertexSizeList[v2];
		vertexList[v1][v1Size] = v2;
		distList[v1][v1Size] = dist;
		vertexList[v2][v2Size] = v1;
		distList[v2][v2Size] = dist;
		vertexSizeList[v1]++;
		vertexSizeList[v2]++;		
	}
}

void readData() {
	cin >> nVertex >> nEdge >> nGoal;
	int* v1List = new int[nEdge];
	int* v2List = new int[nEdge];
	short int* distList = new short int[nEdge];
	for(int i = 0; i < nEdge; i++) {
		cin >> vertex1 >> vertex2 >> dist;
		v1List[i] = vertex1;
		v2List[i] = vertex2;
		distList[i] = dist;
		vertexCountList[vertex1]++;
		vertexCountList[vertex2]++;				
	}
	for(int i = 0; i < nGoal; i++) {
		cin >> goalList[i];
	}	
	createGraph(v1List, v2List, distList);
	delete[] v1List;
	delete[] v2List;
	delete[] distList;
}

void updateNode(FibHeap & distQueue, int num, int dist) {
	if(nodeArray[num] == NULL) {
		nodeArray[num] = new Node(num, dist);
		distQueue.insert(nodeArray[num]);
	}else {
		distQueue.decreaseKey(nodeArray[num], dist);
	}
}

void dijkstra(int sVertex) {
	FibHeap distQueue;
	for(int i = 1; i <= nVertex; i++) {
		minDist[i] = INF;
		nodeArray[i] = NULL;
	}
	nodeArray[sVertex] = new Node(sVertex, 0);
	minDist[sVertex] = 0;
	distQueue.insert(nodeArray[sVertex]);
	while(true) {		
		int vertex = distQueue.extractMin();
		delete nodeArray[vertex];
		if(vertex == -1) {
			break;
		}
		isCounted[vertex] = true;
		for(int i = 0; i < (int)vertexCountList[vertex]; i++) {
			if(isCounted[vertexList[vertex][i]]) {
				continue;
			}
			if(minDist[vertex] + distList[vertex][i] < minDist[vertexList[vertex][i]]) {
				minDist[vertexList[vertex][i]] = minDist[vertex] + distList[vertex][i];
				updateNode(distQueue, vertexList[vertex][i], minDist[vertexList[vertex][i]]);
			}			
		}
		if(vertexCountList[vertex] > 0) {
			delete[] vertexList[vertex];
			delete[] distList[vertex];		
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
	minDist = new int[MAX_V_COUNT];
	isCounted = new bool[MAX_V_COUNT];
	dijkstra(1);
	if(countResult()) {
		cout << (result * 2) << "\n";			
	}else {
		cout << "NIE\n";
	}
	return 0;
}

