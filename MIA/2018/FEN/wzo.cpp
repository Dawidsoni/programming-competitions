#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int LType;
const LType MAX_SIZE = 25100;
const LType INF = 1100000000;

LType width, height, xLineCount, yLineCount;
LType xLineList[MAX_SIZE];
LType yLineList[MAX_SIZE];
LType xLenList[MAX_SIZE];
LType yLenList[MAX_SIZE];
LType xTakenCount, yTakenCount;
LType holeCount, result;

void updateLenList(LType lineList[], LType lineCount, LType maxSize, LType lenList[]) {
	LType prevElem = 0;
	for(LType i = 0; i < lineCount; i++) {
		lenList[i] = lineList[i] - prevElem;
		prevElem = lineList[i];
	}
	lenList[lineCount] = maxSize - lineList[lineCount - 1];
	lenList[lineCount + 1] = INF;
	sort(lenList, lenList + lineCount + 2);
}

void createHoles() {
	LType xInd = 0, yInd = 0, lineCount;
	while(holeCount < (xLineCount + 1) * (yLineCount + 1) - 1) {
		if(xLenList[xInd] < yLenList[yInd]) {
			if(xTakenCount >= 1 && yTakenCount >= 2) {
				lineCount = yLineCount - (yTakenCount - 1);
			}else {
				lineCount = yLineCount;
			}
			result += (lineCount * xLenList[xInd]);
			holeCount += lineCount;
			xTakenCount++;
			xInd++;
		}else {
			if(yTakenCount >= 1 && xTakenCount >= 2) {
				lineCount = xLineCount - (xTakenCount - 1);
			}else {
				lineCount = xLineCount;
			}
			result += (lineCount * yLenList[yInd]);
			holeCount += lineCount;
			yTakenCount++;
			yInd++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> width >> height >> xLineCount >> yLineCount;
	for(int i = 0; i < xLineCount; i++) {
		cin >> xLineList[i];
	}
	for(int i = 0; i < yLineCount; i++) {
		cin >> yLineList[i];
	}
	sort(xLineList, xLineList + xLineCount);
	sort(yLineList, yLineList + yLineCount);
	updateLenList(xLineList, xLineCount, width, xLenList);
	updateLenList(yLineList, yLineCount, height, yLenList);
	createHoles();
	cout << result << "\n";
	return 0;
}
