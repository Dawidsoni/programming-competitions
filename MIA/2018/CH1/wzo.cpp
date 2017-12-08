#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> IPair;
const int MAX_SIZE = 10010;

int nTest, pointCount, coordX, coordY;
vector<IPair> pointList;

bool sortFunc(IPair point1, IPair point2) {
	
}

void setFirstPoint(vector<IPair>& pointList) {
	int minElemIndex = 0;
	for(int i = 1; i < (int)pointList.size(); i++) {
		if(pointList[minElemIndex].second > pointList[i].second) {
			minElemIndex = i;
		}
	}
	swap(pointList[0], pointList[minElemIndex]);
}

vector<IPair> countHull(vector<IPair>& pointList) {
	setFirstPoint(pointList);
	sort(pointList + 1, pointList.end(), sortFunc);
	
	return vector<IPair>();//TODO
}

void printHull(vector<IPair>& hullPoints) {

}

void countResult() {
	sort(pointList.begin(), pointList.end());
	vector<IPair> hullPoints = countHull(pointList);
	printHull(hullPoints);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nTest;
	for(int i = 0; i < nTest; i++) {
		cin >> pointCount; 
		for(int i = 0; i < pointCount; i++) {
			cin >> coordX >> coordY;
			pointList.push_back(IPair(coordX, coordY));
		}
		countResult();
		pointList.clear();
	}
	return 0;
}
