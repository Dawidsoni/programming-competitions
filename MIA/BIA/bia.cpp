#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int LType;
typedef pair<LType, LType> LPair;

const int MAX_SIZE = 11000;

LType width, height, pointCount;
LPair pointList[MAX_SIZE];
LType widthResult;
LType areaResult;
LType result;
LType tmp[30];
LType tmpCount;

void countSum() {
	for(LType i = 0; i < width; i++) {
		widthResult += (i + 1);
	}
	for(LType i = 0; i < height; i++) {
		areaResult += ((i + 1) * widthResult);
	}
}

void addToResult() {
	LType minX = pointList[tmp[0]].first, minY = pointList[tmp[0]].second;
	LType maxX = pointList[tmp[0]].first, maxY = pointList[tmp[0]].second;
	for(LType i = 1; i < tmpCount; i++) {
		minX = min(minX, pointList[tmp[i]].first);
		minY = min(minY, pointList[tmp[i]].second);
		maxX = max(maxX, pointList[tmp[i]].first);
		maxY = max(maxY, pointList[tmp[i]].second);
	}
	LType sum = (minX * minY) * (width - maxX + 1) * (height - maxY + 1);
	if(tmpCount % 2 == 0) {
		result -= sum;
	}else {
		result += sum;
	}
}

void getIndexList(LType number) {
	LType index = 0;
	tmpCount = 0;
	while(number > 0) {
		if(number % 2 == 1) {
			tmp[tmpCount] = index;
			tmpCount++;
		}
		number /= 2;
		index++;
	}
	addToResult();
}

void makePossibilities() {
	LType pos = 1;
	for(LType i = 0; i < pointCount; i++) {
		pos *= 2;
	}	
	for(LType i = 1; i <= pos - 1; i++) {
		getIndexList(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> width >> height >> pointCount;
	for(LType i = 0; i < pointCount; i++) {
		cin >> pointList[i].first >> pointList[i].second;
	}
	countSum();
	makePossibilities();
	cout << (areaResult - result) << "\n";
	return 0;
}
