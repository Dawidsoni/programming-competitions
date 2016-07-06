#include<iostream>
#include<math.h>
#include<algorithm>
#include<climits>

using namespace std;

typedef long long int LType;
typedef pair<int, int> IPair;

class Triangle {
	IPair p1, p2, p3;
	bool isPerimeterCounted;
	bool isInf;	
	double perimeter;
public:
	Triangle(bool isInf) : isPerimeterCounted(false) {
		this->isInf = isInf;
		this->perimeter = INT_MAX;
		this->isPerimeterCounted = true;		
	}
	
	Triangle(IPair p1, IPair p2, IPair p3) : isPerimeterCounted(false), isInf(false) {
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
	}	
		
	double getDist(IPair p1, IPair p2) {
		double x_dist = abs(p2.first - p1.first);
		double y_dist = abs(p2.second - p1.second);
		return sqrt(x_dist * x_dist + y_dist * y_dist);
	}
	
	void countPerimeter() {
		perimeter = getDist(p1, p2) + getDist(p1, p3) + getDist(p2, p3);
	}
	
	double getPerimeter() {
		if(isPerimeterCounted == false) {
			countPerimeter();
			isPerimeterCounted = true;
		}
		return perimeter;
	}
	
	friend ostream& operator <<(ostream& os, const Triangle triangle) {
		os << triangle.p1.first << " " << triangle.p1.second << "\n";
		os << triangle.p2.first << " " << triangle.p2.second << "\n";
		os << triangle.p3.first << " " << triangle.p3.second << "\n";	
		return os;	
	}
	
	static Triangle minTriangle(Triangle t1, Triangle t2) {
		if(t2.isInf || (t1.isInf == false && t1.getPerimeter() < t2.getPerimeter())) {
			return t1;
		}
		return t2;
	}
};


const int MAX_SIZE = 510000;

int nPoint;
IPair xPointList[MAX_SIZE];
IPair yPointList[MAX_SIZE];
IPair leftList[MAX_SIZE];
IPair rightList[MAX_SIZE];
IPair curPointList[MAX_SIZE];
int leftListSize, rightListSize;

void updateLeftList(IPair pList[], int pCount, LType minX) {
	leftListSize = 0;
	for(int i = 0; i < pCount; i++) {
		if(xPointList[pList[i].second].first >= minX) {
			leftList[leftListSize++] = xPointList[pList[i].second];
		}
	}		
}

void updateRightList(IPair pList[], int pCount, LType maxX) {
	rightListSize = 0;
	for(int i = 0; i < pCount; i++) {
		if(xPointList[pList[i].second].first <= maxX) {
			rightList[rightListSize++] = xPointList[pList[i].second];
		}
	}			
}

Triangle getMinTriangle(Triangle curResult, IPair curPoint, IPair pList[], int fromInd, int toInd) {
	Triangle result = curResult;
	for(int i = fromInd; i < toInd; i++) {
		for(int j = i +  1; j < toInd; j++) {
			result = Triangle::minTriangle(result, Triangle(pList[i], pList[j], curPoint));
		}		
	}
	return result;
}

Triangle getLeftCutResult(Triangle curResult, LType deviation) {
	int rightInd = 0;
	int pointInd = 0;
	int pointListSize = 0;		
	Triangle result = curResult;
	for(int i = 0; i < leftListSize; i++) {
		while(rightInd < rightListSize && rightList[rightInd].second <= leftList[i].second + deviation) {
			curPointList[pointListSize++] = rightList[rightInd];
			rightInd++;
		}
		while(pointInd < pointListSize && leftList[i].second - deviation > curPointList[pointInd].second) {
			pointInd++;
		}
		result = getMinTriangle(result, leftList[i], curPointList, pointInd, pointListSize);		
	}	
	return result;
}

Triangle getRightCutResult(Triangle curResult, LType deviation) {
	int leftInd = 0;
	int pointInd = 0;
	int pointListSize = 0;		
	Triangle result = curResult;
	for(int i = 0; i < rightListSize; i++) {
		while(leftInd < leftListSize && leftList[leftInd].second <= rightList[i].second + deviation) {
			curPointList[pointListSize++] = leftList[leftInd];
			leftInd++;
		}
		while(pointInd < pointListSize && rightList[i].second - deviation > curPointList[pointInd].second) {
			pointInd++;
		}
		result = getMinTriangle(result, rightList[i], curPointList, pointInd, pointListSize);		
	}	
	return result;	
}

Triangle getCutResult(Triangle curResult, LType deviation) {
	Triangle leftResult = getLeftCutResult(curResult, deviation);
	Triangle rightResult = getRightCutResult(curResult, deviation);
	return Triangle::minTriangle(leftResult, rightResult);
}

Triangle countResult(int fromInd, int toInd, IPair pList[], int pCount) {
	if(toInd - fromInd <= 1) {
		return Triangle(true);
	}
	if(toInd - fromInd == 2) {
		return Triangle(xPointList[fromInd], xPointList[fromInd + 1], xPointList[fromInd + 2]);
	}
	int halfInd = fromInd + (toInd - fromInd) / 2;
	IPair* leftSide = new IPair[halfInd - fromInd + 1];
	IPair* rightSide = new IPair[toInd - halfInd];
	int leftInd = 0, rightInd = 0;
	for(int i = 0; i < pCount; i++) {
		if(pList[i].second <= halfInd) {
			leftSide[leftInd++] = pList[i];
		}else {
			rightSide[rightInd++] = pList[i];
		}
	}	
	Triangle leftResult = countResult(fromInd, halfInd, leftSide, leftInd);
	Triangle rightResult = countResult(halfInd + 1, toInd, rightSide, rightInd);
	Triangle minResult = Triangle::minTriangle(leftResult, rightResult);
	LType divLine = ceil(minResult.getPerimeter() / 2.0);	
	updateLeftList(leftSide, leftInd, xPointList[halfInd].first - divLine);
	updateRightList(rightSide, rightInd, xPointList[halfInd].first + divLine);
	delete [] leftSide;
	delete [] rightSide;
	return getCutResult(minResult, divLine);	
}

void setPointList() {
	sort(xPointList, xPointList + nPoint);
	for(int i = 0; i < nPoint; i++) {
		yPointList[i] = IPair(xPointList[i].second, i);		
	}
	sort(yPointList, yPointList + nPoint);			
}

void readData() {
	cin >> nPoint;
	for(int i = 0; i < nPoint; i++) {
		cin >> xPointList[i].first >> xPointList[i].second;
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	readData();
	setPointList();
	Triangle result = countResult(0, nPoint - 1, yPointList, nPoint);	
	cout << (int)result.getPerimeter();
	return 0;
}
