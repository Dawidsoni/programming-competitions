#include <iostream>
using namespace std;

const int MAX_SIZE = 200010;

typedef long long int LType;

const int Q_CONST = 1000000009;
const int P_MOD = 1000000087;
LType pow[MAX_SIZE];
LType hashArrPref[MAX_SIZE];
LType hashArrSuf[MAX_SIZE];
string text;
int count;
LType curPal[MAX_SIZE];
LType curPos[MAX_SIZE];
LType newPal[MAX_SIZE][30];
LType delPal[MAX_SIZE];
LType delForward[MAX_SIZE];
LType delBack[MAX_SIZE];
LType result;

void editText() {
	string result;
	result += '#';
	for(int i = 0; i < (int)text.size(); i++) {
		result += text[i];
		result += '#';			
	}
	text = result;
//	cout << text << "\n";
}

void makePow() {
	pow[0] = 1;
	for(int i = 1; i <= count; i++) {
		pow[i] = (pow[i - 1] * Q_CONST) % P_MOD;
	}
}

void makeHash() {
	hashArrPref[0] = pow[0] * text[0];
	hashArrSuf[0] = pow[0] * text[count - 1];
	for(int i = 1; i < count; i++) {
		hashArrPref[i] = (hashArrPref[i - 1] + pow[i] * text[i]) % P_MOD;
		hashArrSuf[i] = (hashArrSuf[i - 1] + pow[i] * text[count - 1 - i]) % P_MOD;
	}
}

unsigned int getHash(int fromPos, int toPos, LType hashArr[]) {
	unsigned int result = hashArr[toPos];
	if(fromPos != 0) {
		result -= hashArr[fromPos - 1];
	}
	result += P_MOD;	
	result = ((LType)result * pow[count - fromPos]) % P_MOD;
	return result;
}

bool isPal(int mid, int length, int offset) {
	if(mid - length < 0 || mid + length >= count) {
		return false;
	}
	if(length < offset) {
		return true;
	}	
	int leftHash = getHash(mid - length, mid - offset, hashArrPref);
	int rightHash = getHash(count - 1 - mid - length, count - 1 - mid - offset, hashArrSuf);	
	return (leftHash == rightHash);
}

int getPal(int mid, int offset) {
	int fromLength = 1, toLength = count / 2;
	int result = 0;
	while(fromLength <= toLength) {
		int midLength = (fromLength + toLength) / 2;
		if(isPal(mid, midLength, offset)) {
			result = midLength;
			fromLength = midLength + 1;
		}else {
			toLength = midLength - 1;
		}
	}
	return result;
}

void countCurPal() {
	for(int i = 0; i < count; i++) {
		curPos[i] = getPal(i, 1);
		curPal[i] = curPos[i] / 2;
//		cout << curPal[i] << " ";
	}
//	cout << "\n";
}

void countNewPal() {
	for(int i = 0; i < count; i++) {
		if(i - curPos[i] == 0 || i + curPos[i] == count - 1) {
			continue;
		}
		int leftInd = i - curPos[i] - 1;
		int rightInd = i + curPos[i] + 1;
		int pal = getPal(i, curPos[i] + 2) / 2;		
		newPal[leftInd][text[rightInd] - 'a'] += (pal - curPal[i]); 
		newPal[rightInd][text[leftInd] - 'a'] += (pal - curPal[i]);
	}
}

void countDelForward() {
	for(int i = 0; i < count; i++) {
		if(curPal[i] != 0) {
			delForward[i - curPos[i] + 1]++;			
		}
	}
	LType curOpen = 0;
	LType curSum = 0;
	for(int i = 1; i < count; i += 2) {
		curOpen += delForward[i];
		curSum += curOpen;
		delPal[i] += curSum;
//		cout << delPal[i] << " " << " ";
		if(curPal[i + 1] != 0) {
			curOpen--;
			curSum -= curPal[i + 1];
		}
		if(i + 2 < count && curPal[i + 2] != 0) {
			curOpen--;
			curSum -= curPal[i + 2];
		}
	}
//	cout << "\n";
}

void countDelBack() { 
	for(int i = 0; i < count; i++) {
		if(curPal[i] != 0) {
			delBack[i + curPos[i] - 1]++;		
		}
	}
	LType curOpen = 0;
	LType curSum = 0;
	for(int i = 1; i < count; i += 2) {
		curSum -= curOpen;
		delPal[i] += curSum;		
//		cout << curSum << "";		
		if(curPal[i] != 0) {
			curOpen++;
			curSum += (curPal[i] + 1);
//			cout << "(" << curPal[i] << ", ";
		}		
		if(curPal[i + 1] != 0) {
			curOpen++;
			curSum += (curPal[i + 1] + 1);
//			cout << curPal[i + 1] << "), ";
		}	
		curOpen -= delBack[i];
		curSum -= delBack[i];
	}
//	cout << "\n";
}

LType getPalSum() {
	LType result = 0;
	for(int i = 0; i < count; i++) {
		result += curPal[i];
	}
	return result;
}

LType getMaxChange() {
	LType result = 0;
	for(int i = 0; i < count; i++) {
		LType addMax = 0;
		for(int j = 0; j < 30; j++) {
			addMax = max(addMax, newPal[i][j]);
//			cout << newPal[i][j] << " ";
		}
//		cout << "(" << delPal[i] << ")\n";
		result = max(result, addMax - delPal[i]);
	}	
//	cout << "\n";
	return result;
}

void countResult() {	
	countCurPal();	
	countNewPal();
	countDelForward();
	countDelBack();	
	result = getPalSum() + getMaxChange() + (count / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> text;
	editText();
	count = text.size();
	makePow();
	makeHash();
	countResult();
	cout << result << "\n";
	return 0;
}
