#include<iostream>

using namespace std;

class Node {
public:
	Node() : left(NULL), right(NULL), parent(NULL), val(0) {}
	Node * left;
	Node * right;
	Node * parent;
	int val;
};

Node * root = NULL;
int nQuery;
string oper;
int val, sucCount;

void insert(Node * node, int val) {
	if(node->left == NULL && val < node->val) {
		Node * child = new Node();
		child->val = val;
		child->parent = node;
		node->left = child;
	}else if(node->right == NULL && val >= node->val) {
		Node * child = new Node();
		child->val = val;
		child->parent = node;
		node->right = child;
	}else if(val < node->val) {
		insert(node->left, val);
	}else {
		insert(node->right, val);
	}
}

void insert(int val) {
	if(root == NULL) {
		root = new Node();
		root->val = val;
		return;
	}
	insert(root, val);
}

Node * findNode(Node * root, int val) {
	if(root->val == val) {
		return root;
	}
	if(val < root->val) {
		return findNode(root->left, val);
	}
	return findNode(root->right, val);
}

Node * findMinimum(Node * node) {
	if(node->left == NULL) {
		return node;
	}
	return findMinimum(node->left);
}

Node * getSuccessor(Node * node) {
	if(node->right != NULL) {
		return findMinimum(node->right);
	}
	Node * parent = node->parent;	
	while(parent != NULL && node == parent->right) {
		node = parent;
		parent = node->parent;
	}
	return parent;
}

void printSuccessor(int val, int sucCount) {
	Node * node = findNode(root, val);
	for(int i = 0; i < (int)sucCount; i++) {
		Node * succ = getSuccessor(node);
		if(i == 0 && succ == NULL) {
			cout << "nastepnik nie istnieje";
		}
		if(succ == NULL) {
			break;
		}
		cout << succ->val << " ";
		node = succ;
	}
	cout << "\n";	
}

int level(Node * node, int val) {
	if(node->val == val) {
		return 0;
	}
	if(node->val > val) {
		return level(node->left, val) + 1;
	}else {
		return level(node->right, val) + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nQuery;
	for(int i = 0; i < nQuery; i++) {
		cin >> oper;
		if(oper == "wstaw") {
			cin >> val;
			insert(val);
		}else if(oper == "nastepnik") {
			cin >> val >> sucCount;
			printSuccessor(val, sucCount);
		}else if(oper == "poziom") {
			cin >> val;
			cout << level(root, val) << "\n";
		}
	}
	
	
	return 0;
}
