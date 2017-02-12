#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long int LType;

LType manacher(string str, bool isOdd) {
	vector<LType> radiusList;
	for(LType i = 0; i < (LType)str.size(); i++) {
		radiusList.push_back(0);
	}
	LType currentRadius = 0;			
	for(LType i = 1; i < (LType)str.size();) {
		if(isOdd) {
			while(str[i - currentRadius - 1] == str[i + currentRadius + 1]) {
				currentRadius++;
			}			
		}else {
			while(str[i - currentRadius] == str[i + currentRadius + 1]) {
				currentRadius++;
			}			
		}
		radiusList[i] = currentRadius;
		LType j = 1;
		while(j <= radiusList[i] && radiusList[i - j] != radiusList[i] - j) {
			radiusList[i + j] = min(radiusList[i - j], radiusList[i] - j);
			j++;
		}
		currentRadius -= j;
		currentRadius = max(currentRadius, (LType)0);
		i += j;
	}
	LType result = 0;
	for(LType i = 0; i < (LType)str.size(); i++) {
		result += radiusList[i];
	}
	return result;
}

int main() {
	string str;
	cin >> str;
	str = "!" + str + "@";
	LType result = 0;
	result += manacher(str, true);
	result += manacher(str, false);
	result += (str.size() - 2);	
	cout << result;	
	return 0;
}
