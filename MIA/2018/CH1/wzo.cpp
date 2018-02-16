#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int LType;
typedef pair<LType, LType> IPair;
const int MAX_SIZE = 10010;

int nTest, pointCount;
LType coordX, coordY;
vector<IPair> pointList;

LType getDist(IPair point1, IPair point2) {
	IPair diff = IPair(point1.first - point2.first, point1.second - point2.second);
	return diff.first * diff.first + diff.second * diff.second;
}

LType countDet(IPair sPoint, IPair e1Point, IPair e2Point) { 
	IPair p1 = IPair(e1Point.first - sPoint.first, e1Point.second - sPoint.second);
	IPair p2 = IPair(e2Point.first - sPoint.first, e2Point.second - sPoint.second);
	return (p1.first * p2.second - p1.second * p2.first);
}

bool sortFunc(IPair point1, IPair point2) {
	LType det = countDet(pointList[0], point1, point2);
	if(det > 0) {
		return true;
	}else if(det < 0) {
		return false;
	}
	return getDist(point1, pointList[0]) < getDist(point2, pointList[0]);
}

void setFirstPoint(vector<IPair>& pointList) {
	int minElemIndex = 0;
	for(int i = 1; i < (int)pointList.size(); i++) {
		if(pointList[minElemIndex] > pointList[i]) {
			minElemIndex = i;
		}
	}
	swap(pointList[0], pointList[minElemIndex]);
}

vector<IPair> countHull(vector<IPair>& pointList) {
	vector<IPair> result;
	setFirstPoint(pointList);
	sort(pointList.begin() + 1, pointList.end(), sortFunc);
	result.push_back(pointList[0]);
	result.push_back(pointList[1]);
	int i = 2;
	while(countDet(result[0], result[1], pointList[i]) == 0) {
		result.pop_back();
		result.push_back(pointList[i]);
		i++;
	}
	for(; i < pointCount; i++) {
		IPair lastPoint = result[result.size() - 1];
		result.pop_back();
		while(countDet(result[result.size() - 1], lastPoint, pointList[i]) <= 0) {
			lastPoint = result[result.size() - 1];
			result.pop_back();
		}
		result.push_back(lastPoint);
		result.push_back(pointList[i]);
	}
	return result;	
}

void printHull(vector<IPair>& hullPoints, int caseNum) {
	cout << "Case #" << caseNum << "\n";
	int firstElemInd = 0;
	for(int i = 1; i < (int)hullPoints.size(); i++) {
		if(hullPoints[i] < hullPoints[firstElemInd]) {
			firstElemInd = i;
		}
	}
	for(int i = firstElemInd; i < (int)hullPoints.size(); i++) {
		cout << hullPoints[i].first << " " << hullPoints[i].second << "\n";
	}
	for(int i = 0; i < firstElemInd; i++) {
		cout << hullPoints[i].first << " " << hullPoints[i].second << "\n";
	}
}

void countResult(int caseNum) {
	vector<IPair> hullPoints = countHull(pointList);
	printHull(hullPoints, caseNum);
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
		countResult(i + 1);
		pointList.clear();
	}
	return 0;
}
