#include<iostream>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include <iomanip>  

using namespace std;

typedef long long int LType;
typedef pair<int, int> IPair;

const int MAX_SIZE = 110000;

int nPoint;
IPair xPointList[MAX_SIZE];
IPair yPointList[MAX_SIZE];
IPair curPointList[MAX_SIZE];
IPair leftList[MAX_SIZE];
IPair rightList[MAX_SIZE];
int leftListSize, rightListSize;

LType getDist(IPair p1, IPair p2) {
	LType absX = abs(p1.first - p2.first);
	LType absY = abs(p1.second - p2.second);
	return (absX * absX) + (absY * absY);
}

LType getCutResult(LType subResult) {
	int rightInd = 0;
	int pointInd = 0;
	int pointListSize = 0;	
	LType result = LONG_LONG_MAX;
	for(int i = 0; i < leftListSize; i++) {
		while(rightInd < rightListSize && rightList[rightInd].second <= leftList[i].second + subResult) {
			curPointList[pointListSize++] = rightList[rightInd];
			rightInd++;
		}
		while(pointInd < pointListSize && leftList[i].second - subResult > subResult) {
			pointInd++;
		}
		if(pointListSize - pointInd >= 100) {
			cout << "BLAAAAAD";
		}
		for(int j = pointInd; j < pointListSize; j++) {
			result = min(result, getDist(leftList[i], curPointList[j]));
		}
	}
	return result;
}

void updateLeftList(IPair pList[], int pCount, int subResult) {
	leftListSize = 0;
	for(int i = 0; i < pCount; i++) {
		if(xPointList[pList[i].second].first >= subResult) {
			leftList[leftListSize++] = xPointList[pList[i].second];
		}
	}	
}

void updateRightList(IPair pList[], int pCount, int subResult) {
	rightListSize = 0;
	for(int i = 0; i < pCount; i++) {
		if(xPointList[pList[i].second].first <= subResult) {
			rightList[rightListSize++] = xPointList[pList[i].second];
		}
	}		
}

LType divide(int fromInd, int toInd, IPair pList[], int pCount) {
	if(fromInd == toInd) {
		return INT_MAX;
	}
	if(toInd - 1 == fromInd) {
		return getDist(xPointList[fromInd], xPointList[toInd]);
	}	
	int halfInd = fromInd + (toInd - fromInd) / 2;
	IPair leftList[halfInd - fromInd + 1], rightList[toInd - halfInd];
	int leftInd = 0, rightInd = 0;
	for(int i = 0; i < pCount; i++) {
		if(pList[i].second <= halfInd) {
			leftList[leftInd++] = pList[i];
		}else {
			rightList[rightInd++] = pList[i];
		}
	}	
	LType leftResult = divide(fromInd, halfInd, leftList, leftInd);
	LType rightResult = divide(halfInd + 1, toInd, rightList, rightInd);
	LType subResult = min(leftResult, rightResult);
	updateLeftList(leftList, leftInd, xPointList[halfInd].first - sqrt(subResult));
	updateRightList(rightList, rightInd, xPointList[halfInd].first + sqrt(subResult));
	return min(subResult, getCutResult(subResult));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nPoint;
	for(int i = 0; i < nPoint; i++) {
		cin >> xPointList[i].first >> xPointList[i].second;
	}
	sort(xPointList, xPointList + nPoint);
	for(int i = 0; i < nPoint; i++) {
		yPointList[i] = (IPair(xPointList[i].second, i));		
	}
	sort(yPointList, yPointList + nPoint);	
	cout.setf(ios::fixed, ios::floatfield);
	cout << setprecision(5) << sqrt(divide(0, nPoint - 1, yPointList, nPoint)) << "\n";	
	return 0;
}
