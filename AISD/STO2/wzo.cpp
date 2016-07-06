#include<iostream>
#include<limits.h>

using namespace std;

const int MAX_SIZE = 1100;

int n, m;
int array[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE];
int dynArray[MAX_SIZE][MAX_SIZE];
int previous[MAX_SIZE][MAX_SIZE];

void countResult() {
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			int above = dynArray[j - 1][i - 1];
			int middle = dynArray[j][i - 1];
			int bottom = dynArray[j + 1][i - 1];
			if(j - 1 < 1) {
				above = INT_MAX;
			}
			if(j + 1 > n) {
				bottom = INT_MAX;
			}
			if(min(min(above, middle), bottom) == above) {
				dynArray[j][i] = above + array[j][i];
				previous[j][i] = (j - 1);
			}else if(min(min(above, middle), bottom) == bottom) {
				dynArray[j][i] = bottom + array[j][i];	
				previous[j][i] = (j + 1);			
			}else {
				dynArray[j][i] = middle + array[j][i];	
				previous[j][i] = j;							
			}			
		}		
	}	
}

void fillResult() {
	int minInd, minResult = INT_MAX;
	for(int i = 1; i <= n; i++) {
		if(dynArray[i][m] < minResult) {
			minResult = dynArray[i][m];
			minInd = i;
		}
	}
	for(int i = m; i >= 1; i--) {
		result[i] = (minInd - 1);
		minInd = previous[minInd][i];		
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> array[i][j];
		}
	}
	countResult();
	fillResult();
	for(int i = 1; i <= m; i++) {
		cout << result[i] << " ";
	}	
	return 0;
}
