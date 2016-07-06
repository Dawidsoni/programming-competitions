#include<iostream>
#include<algorithm>

using namespace std;

typedef pair<int, int> IPair;

const int MAX_SIZE = 510000;

int nSteps, nCases, step, caseNumber;
IPair stepArray[MAX_SIZE];
int minSuf[MAX_SIZE];

void countMinSuf() {
	minSuf[nSteps - 1] = stepArray[nSteps - 1].second;
	for(int i = nSteps - 2; i >= 0; i--) {
		minSuf[i] = min(minSuf[i + 1], stepArray[i].second);		
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> nSteps >> nCases;
	for(int i = 0; i < nSteps; i++) {
		cin >> step;
		stepArray[i] = IPair(step, i);
	}
	sort(&stepArray[0], &stepArray[nSteps]);
	countMinSuf();
	for(int i = 0; i < nCases; i++) {
		cin >> caseNumber;
		IPair * wsk = lower_bound(&stepArray[0], &stepArray[nSteps], IPair(caseNumber, 0));
		int index = (wsk - &stepArray[0]);
		if(index == nSteps) {
			cout << nSteps << " ";
		}else {
			cout << minSuf[index] << " ";					
		}
	}
	
	return 0;
}
