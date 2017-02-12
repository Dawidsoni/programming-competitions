#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_SIZE = 400000;

int vCount;
int v1, v2, r1, r2, sizeA, sizeB, result = MAX_SIZE;
bool isOcc[MAX_SIZE];
vector<int> tree[MAX_SIZE];
vector<int> path;

bool findPath(int v1, int v2) {
	isOcc[v1] = true;
	if(v1 == v2) {
		path.push_back(v2);
		return true;
	}
	for(int i = 0; i < (int)tree[v1].size(); i++) {
		if(isOcc[tree[v1][i]] == false) {
			if(findPath(tree[v1][i], v2)) {
				path.push_back(v1);
				return true;
			}
		} 
	}
	return false;
}

void resetOcc() {
	for(int i = 1; i <= vCount; i++) {
		isOcc[i] = false;
	} 
}

int countResult(vector<int>& subResult) {
	sort(subResult.begin(), subResult.end());
	int result = 0, counter = 1;
	for(int i = subResult.size() - 1; i >= 0; i--) {
		result = max(result, subResult[i] + counter);
		counter++;
	}
	return result;
} 

int findDiv(int vertex) {
	bool isLeaf = true;
	vector<int> subResult;	
	isOcc[vertex] = true;
	for(int i = 0; i < (int)tree[vertex].size(); i++) {
		if(isOcc[tree[vertex][i]] == false) {
			isLeaf = false;
			subResult.push_back(findDiv(tree[vertex][i]));			
		}
	}
	if(isLeaf) {
		return 0;
	}
	return countResult(subResult);
}

void removeEdge(int r1, int r2) {
	vector<int> edgeList;
	for(int i = 0; i < (int)tree[r1].size(); i++) {
		if(tree[r1][i] != r2) {
			edgeList.push_back(tree[r1][i]);
		}
	}
	tree[r1] = edgeList;
}

void addEdge(int r1, int r2) {
	tree[r1].push_back(r2);
}

void countSizes(int ind) {
	int r1 = path[ind], r2 = path[ind + 1];
	removeEdge(r1, r2);
	removeEdge(r2, r1);
	resetOcc();
	sizeA = findDiv(v1);
	resetOcc();
	sizeB = findDiv(v2);
	addEdge(r1, r2);
	addEdge(r2, r1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> vCount >> v1 >> v2;
	for(int i = 0; i + 1 < vCount; i++) {
		cin >> r1 >> r2;
		tree[r1].push_back(r2);
		tree[r2].push_back(r1);
	}
	findPath(v2, v1);	
	int fromInd = 0, toInd = (int)path.size() - 2;
	while(fromInd <= toInd) {
		int ind = (fromInd + toInd) / 2;
		countSizes(ind);
		result = min(result, max(sizeA, sizeB));
		if(sizeA == sizeB) {
			break;
		}else if(sizeA < sizeB) {
			fromInd = ind + 1;
		}else {
			toInd = ind - 1;
		}
	}
	cout << result << "\n";
	return 0;
}
