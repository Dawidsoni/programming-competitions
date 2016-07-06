#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef long long int LType;

class Line {
public:
	Line() {}
	Line(LType id_, LType x1_, LType x2_) {
		id = id_;
		x1 = x1_;
		x2 = x2_;
	}
	friend bool operator < (Line line1, Line line2) {
		if(line1.x1 == line2.x1) {
			return line1.x2 < line2.x2;
		}
		return line1.x1 < line2.x1;
	}
	
	LType id, x1, x2;	
};

class Rectangle {
public:
	Rectangle() {}
	Rectangle(LType id_, LType x1_, LType y1_, LType x2_, LType y2_) {
		id = id_;
		x1 = x1_;
		y1 = y1_;
		x2 = x2_;
		y2 = y2_;
	}
	LType id, x1, y1, x2, y2;		
};

typedef pair<LType, LType> IPair;

const LType MAX_SIZE = 51000;

LType rectCount;
LType x1, y1, x2, y2;
vector<LType> graph[MAX_SIZE];
Rectangle rectList[MAX_SIZE];
bool isCounted[MAX_SIZE];
LType result;
map<LType, vector<Line> > xStartAxis;
map<LType, vector<Line> > xEndAxis;
map<LType, vector<Line> > yStartAxis;
map<LType, vector<Line> > yEndAxis;
map<LType, LType> areaMap;

LType dfs(LType vertex) {
	isCounted[vertex] = true;
	LType result = areaMap[vertex];
	for(LType i = 0; i < (LType)graph[vertex].size(); i++) {
		if(isCounted[graph[vertex][i]] == false) {
			result += dfs(graph[vertex][i]);
		}
	}
	return result;
}

void addEdges(vector<Line> & startAxis, vector<Line> & endAxis) {
	LType startIndex = 0, endIndex = 0;
	while(startIndex < (LType)startAxis.size() && endIndex < (LType)endAxis.size()) {	
		LType sX1 = startAxis[startIndex].x1;
		LType sX2 = startAxis[startIndex].x2;
		LType eX1 = endAxis[endIndex].x1;
		LType eX2 = endAxis[endIndex].x2;
		if((sX1 >= eX1 && sX1 <= eX2) || (eX1 >= sX1 && eX1 <= sX2)) {
			graph[startAxis[startIndex].id].push_back(endAxis[endIndex].id);
			graph[endAxis[endIndex].id].push_back(startAxis[startIndex].id);
		}
		if(sX2 < eX2) {
			startIndex++;
		}else {
			endIndex++;
		}
	}	
}

void countXGraph() {
	for(LType i = 0; i < rectCount; i++) {
		if(xStartAxis.find(rectList[i].x1) == xStartAxis.end()) {
			xStartAxis[rectList[i].x1] = vector<Line>();
		}		
		if(xEndAxis.find(rectList[i].x2) == xEndAxis.end()) {
			xEndAxis[rectList[i].x2] = vector<Line>();
		}		
		xStartAxis[rectList[i].x1].push_back(Line(rectList[i].id, rectList[i].y1, rectList[i].y2));
		xEndAxis[rectList[i].x2].push_back(Line(rectList[i].id, rectList[i].y1, rectList[i].y2));		
	}
	for(map<LType, vector<Line> >::iterator it = xStartAxis.begin(); it != xStartAxis.end(); it++) {		
		if(xEndAxis.find(it->first) == xEndAxis.end()) {
			continue;
		}
		vector<Line> startAxis = it->second;
		vector<Line> endAxis = xEndAxis.find(it->first)->second;
		sort(startAxis.begin(), startAxis.end());
		sort(endAxis.begin(), endAxis.end());
		addEdges(startAxis, endAxis);
	}
}

void countYGraph() { 
	for(LType i = 0; i < rectCount; i++) {
		if(yStartAxis.find(rectList[i].y1) == yStartAxis.end()) {
			yStartAxis[rectList[i].y1] = vector<Line>();
		}		
		if(yEndAxis.find(rectList[i].y2) == yEndAxis.end()) {
			yEndAxis[rectList[i].y2] = vector<Line>();
		}		
		yStartAxis[rectList[i].y1].push_back(Line(rectList[i].id, rectList[i].x1, rectList[i].x2));
		yEndAxis[rectList[i].y2].push_back(Line(rectList[i].id, rectList[i].x1, rectList[i].x2));		
	}
	for(map<LType, vector<Line> >::iterator it = yStartAxis.begin(); it != yStartAxis.end(); it++) {		
		if(yEndAxis.find(it->first) == yEndAxis.end()) {
			continue;
		}
		vector<Line> startAxis = it->second;
		vector<Line> endAxis = yEndAxis.find(it->first)->second;
		sort(startAxis.begin(), startAxis.end());
		sort(endAxis.begin(), endAxis.end());
		addEdges(startAxis, endAxis);
	}
}

void countGraph() {
	countXGraph();
	countYGraph();
}

void countResult() {
	for(LType i = 0; i < rectCount; i++) {
		if(isCounted[i] == false) {
			result = max(result, dfs(i));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> rectCount;
	for(LType i = 0; i < rectCount; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		rectList[i] = Rectangle(i, x1, y1, x1 + x2, y1 + y2);
		areaMap[i] = (x2 * y2);
	}
	countGraph();
	countResult();
	cout << result;	
	return 0;
}
