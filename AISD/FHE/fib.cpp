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

FibHeap heap;
int count, number;
Node** array = new Node*[110000];

void decrease() {
	for(int i = 0; i < count; i++) {
		if(array[i] != NULL) {
			cout << "decrease " << i << "\n";
			heap.decreaseKey(array[i], 3);
			//heap.printRootList();
			break;
		}
	}
}

int main() {
	cin >> count;
	for(int i = 0; i < count; i++) {
		cin >> number;
		array[i] = new Node(i, number);
		heap.insert(array[i]);
	}	
	for(int i = 1; i <= count; i++) {
		int result = heap.extractMin();
		//heap.printRootList();			
		cout << "extract " << result << "\n";	
		delete array[result];
		array[result] = NULL;
		decrease();				
	}
	return 0;
}
