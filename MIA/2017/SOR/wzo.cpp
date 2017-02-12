#include<iostream>
#include<map>
#include<queue>
using namespace std;

const int MAX_SIZE = 100000;
typedef pair<int, int> IPair;

int boardSize, swapSize;
map<int, int> permMap;
int startPoint[MAX_SIZE];
int distArr[MAX_SIZE];
bool isOcc[MAX_SIZE];
queue<IPair> vQueue;
int mapCounter; 
int arr[10];

int asKey(int arr[], int size) {
	int result = 0;
	int factor = 1;
	for(int i = 0; i < size; i++) {
		result += (factor * arr[i]);
		factor *= 10;
	}
	return result;
}

void fromKey(int key, int arr[]) {
	int counter = 0;
	while(key != 0) {
		arr[counter] = (key % 10);
		key /= 10;
		counter++;
	}
}

void createPerm(int size, int arr[], bool isOcc[]) {
	if(size == boardSize) {
		permMap[asKey(arr, size)] = mapCounter;
		mapCounter++;
	}else {
		for(int i = 1; i <= boardSize; i++) {
			if(isOcc[i] == false) {
				isOcc[i] = true;
				arr[size] = i;
				createPerm(size + 1, arr, isOcc);
				isOcc[i] = false;
			}
		}
	}	
} 
 
void createMapping() {
	int arr[10];
	bool isOcc[10];
	for(int i = 0; i < 10; i++) {
		isOcc[i] = false;
	}
	createPerm(0, arr, isOcc);	
} 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin >> boardSize;
	for(int i = 0; i < boardSize; i++) {
		cin >> startPoint[i];
	}
	cin >> swapSize;
	createMapping();
	int startKey = asKey(startPoint, boardSize);
	vQueue.push(IPair(startKey, 0));
	isOcc[permMap[startKey]] = true;
	while(vQueue.size() > 0) {
		int vertex = vQueue.front().first;
		int dist = vQueue.front().second;
		vQueue.pop();
		fromKey(vertex, arr);		
		int neigh[10];
		for(int i = 0; i <= boardSize - swapSize; i++) {
			for(int j = 0; j < boardSize; j++) {
				neigh[j] = arr[j];
			}
			for(int j = 0; j < swapSize / 2; j++) {
				swap(neigh[i + j], neigh[i + swapSize - j - 1]);
			}
			int neighKey = asKey(neigh, boardSize);
			if(isOcc[permMap[neighKey]] == false) {
				isOcc[permMap[neighKey]] = true;
				distArr[permMap[neighKey]] = dist + 1;
				vQueue.push(IPair(neighKey, dist + 1));
			}
		}		
	}	
	for(int i = 1; i <= boardSize; i++) {
		arr[i - 1] = i;
	}
	int key = asKey(arr, boardSize);
	if(isOcc[permMap[key]]) {
		cout << distArr[permMap[key]] << "\n";
	}else {
		cout << -1 << "\n";
	}
	return 0;
}
