#include<iostream>
#include<algorithm>

using namespace std;

typedef long long int LType;
typedef pair<LType, LType> IPair;

const int MAX_SIZE = 110000;
const int TREE_SIZE = 1 << 17;

class Point {
public:
	int coordX, coordY, weight;	
	
	Point() {}	
	Point(int x, int y, int w) : coordX(x), coordY(y), weight(w) {}
	
	static bool rawSort(const Point & p1, const Point & p2) {
		if(p1.coordY == p2.coordY) {
			return (p1.coordX < p2.coordX);
		}
		return (p1.coordY < p2.coordY);
	}
	
	static bool colSort(const Point & p1, const Point & p2) {
		if(p1.coordX == p2.coordX) {
			return (p1.coordY < p2.coordY);
		}
		return (p1.coordX < p2.coordX);
	}
};

int dimX, dimY, nPoint, pathSize;
Point pointList[MAX_SIZE];
int mapColumn[MAX_SIZE];
IPair maxTree[TREE_SIZE * 2];
IPair result[MAX_SIZE];
IPair path[MAX_SIZE];

void initTree() {
	for(int i = 0; i < TREE_SIZE * 2; i++) {
		maxTree[i].second = -1;
	}
}

IPair getMax(int fromInd, int toInd) {
	fromInd += TREE_SIZE;
	toInd += TREE_SIZE;
	IPair result = max(maxTree[fromInd], maxTree[toInd]);
	while(fromInd / 2 < toInd / 2) {
		if(fromInd % 2 == 0) {
			result = max(result, maxTree[fromInd + 1]);
		}
		if(toInd % 2 == 1) {
			result = max(result, maxTree[toInd - 1]);
		}		
		fromInd /= 2;
		toInd /= 2;
	}
	return result;
}

void setMax(LType val, int ind, int key) {
	ind += TREE_SIZE;
	maxTree[ind] = IPair(val, key);
	ind /= 2;	
	while(ind > 0) {
		maxTree[ind] = max(maxTree[ind * 2], maxTree[ind * 2 + 1]);
		ind /= 2;
	}	
}

void mapColumns() {
	int colNum = 0, prevCol = pointList[0].coordX;	
	mapColumn[colNum] = pointList[0].coordX;
	pointList[0].coordX = colNum;
	for(int i = 1; i < nPoint; i++) {
		if(pointList[i].coordX != prevCol) {
			colNum++;
			mapColumn[colNum] = pointList[i].coordX;		
			prevCol = pointList[i].coordX;			
		}
		pointList[i].coordX = colNum;		
	}	
}

void countResult() {
	for(int i = 0; i < nPoint; i++) {
		IPair prevMax = getMax(0, pointList[i].coordX);
		LType curMax = prevMax.first + pointList[i].weight;
		result[i] = IPair(curMax, prevMax.second);		
		setMax(curMax, pointList[i].coordX, i);		
	}
}

void printResult() {
	IPair node = result[nPoint - 1];
	cout << node.first << "\n";
	/*while(node.second != -1) {
		Point point = pointList[node.second];
		point.coordX = mapColumn[point.coordX];
		path[pathSize] = IPair(point.coordX, point.coordY);
		pathSize++;
		node = result[node.second];
	}	
	cout << pathSize << "\n";
	for(int i = pathSize - 1; i >= 0; i--) {
		cout << path[i].first << " " << path[i].second << "\n";
	}*/	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> dimX >> dimY >> nPoint;
	for(int i = 0; i < nPoint; i++) {
		cin >> pointList[i].coordX >> pointList[i].coordY >> pointList[i].weight;
	}
	pointList[nPoint] = Point(dimX, dimY, 0);
	nPoint++;
	sort(pointList, pointList + nPoint, Point::colSort);
	mapColumns();	
	initTree();
	sort(pointList, pointList + nPoint, Point::rawSort);	
	countResult();
	printResult();
	return 0;
}
