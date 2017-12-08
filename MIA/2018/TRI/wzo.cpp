#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long int LType;
const int MAX_SIZE = 2600;
const double PI = 3.141592653589793238463;

int pointCount;
LType xCoord[MAX_SIZE];
LType yCoord[MAX_SIZE];
double angleList[MAX_SIZE * 2];
LType result;

double getAngle(LType xCoord, LType yCoord) {
	double coordLen = sqrt(xCoord * xCoord + yCoord * yCoord);
	double angle = acos(xCoord / coordLen) * 180 / PI;
	if(yCoord < 0) {
		angle = 360 - angle;
	}
	return angle;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> pointCount;
	for(int i = 0; i < pointCount; i++) {
		cin >> xCoord[i];
	}
	for(int i = 0; i < pointCount; i++) {
		cin >> yCoord[i];
	}
	for(int i = 0; i < pointCount; i++) {
		double angle = getAngle(xCoord[i], yCoord[i]);
		angleList[i] = angle;
		angleList[pointCount + i] = angle + 360;
	}
	sort(angleList, angleList + 2 * pointCount);
	/*for(int i = 0; i < 2 * pointCount; i++) {
		cout << angleList[i] << " ";
	}
	cout << "\n";*/
	for(int i = 0; i < pointCount; i++) {
		double rotAngle1 = angleList[i] + 180;
		int r1Count = upper_bound(angleList, angleList + 2 * pointCount, rotAngle1) - angleList;
		for(int j = i + 1; j < 2 * pointCount; j++) {
			if(angleList[j] - angleList[i] >= 180) {
				break;
			}
			double rotAngle2 = angleList[j] + 180;
			int r2Count = upper_bound(angleList, angleList + 2 * pointCount, rotAngle2) - angleList;
			//cout << angleList[i] << " " << angleList[j] << " " << (r2Count - r1Count) << "\n";
			result += (r2Count - r1Count);
		}
	}
	cout << (result / 3) << "\n";
	return 0;
}
