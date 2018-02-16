#include <iostream>
using namespace std;

typedef long long int LType;
const int Q_CONST = 1000000009;
const int P_MOD = 1000000087;
const int MAX_SIZE = 100010;
const int TREE_SIZE = 1 << 18;

string word;
int queryCount, queryType, pos;
char letter;
LType hashArrPref[MAX_SIZE];
LType hashArrSuf[MAX_SIZE];
LType pow[MAX_SIZE];
LType prefTree[TREE_SIZE * 2];
LType sufTree[TREE_SIZE * 2];

LType getTreeElem(int pos, LType tree[]) {
    LType result = 0;
    pos += TREE_SIZE;
    while(pos > 0) {
        result += tree[pos];
        pos /= 2;
    }
    return result;
}

void updateTreeInterval(int fromInd, int toInd, LType val, LType tree[]) {
    fromInd += TREE_SIZE;
    toInd += TREE_SIZE;
    tree[fromInd] += val;
    if(fromInd != toInd) {
        tree[toInd] += val;
    }
    while(fromInd / 2 < toInd / 2) {
        if(fromInd % 2 == 0) {
            tree[fromInd + 1] += val;
        }
        if(toInd % 2 == 1) {
            tree[toInd - 1] += val;
        }
        fromInd /= 2;
        toInd /= 2;
    }
}

void makePow() {
	pow[0] = 1;
	for(int i = 1; i <= (int)word.size(); i++) {
		pow[i] = (pow[i - 1] * Q_CONST) % P_MOD;
	}
}

void makeHash() {
	hashArrPref[0] = pow[0] * word[0];
	hashArrSuf[0] = pow[0] * word[word.size() - 1];
	for(int i = 1; i < (int)word.size(); i++) {
		hashArrPref[i] = (hashArrPref[i - 1] + pow[i] * word[i]) % P_MOD;
		hashArrSuf[i] = (hashArrSuf[i - 1] + pow[i] * word[word.size() - 1 - i]) % P_MOD;
	}
}

LType getHash(int pos, LType hashArr[], LType tree[]) {
    return (hashArr[pos] + getTreeElem(pos, tree)) % P_MOD;
}

unsigned int getHash(int fromPos, int toPos, LType hashArr[], LType tree[]) {
	unsigned int result = getHash(toPos, hashArr, tree);
	if(fromPos != 0) {
		result -= getHash(fromPos - 1, hashArr, tree);
	}
	result += P_MOD;
	result = ((LType)result * pow[word.size() - fromPos]) % P_MOD;
	return result;
}

void changeLetter(int pos, char letter) {
    updateTreeInterval(pos, word.size() - 1, (-pow[pos] * word[pos]) % P_MOD, prefTree);
    updateTreeInterval(word.size() - 1 - pos, word.size() - 1, (-pow[pos] * word[pos]) % P_MOD, sufTree);
    word[pos] = letter;
    updateTreeInterval(pos, word.size() - 1, (pow[pos] * word[pos]) % P_MOD, prefTree);
    updateTreeInterval(word.size() - 1 - pos, word.size() - 1, (pow[pos] * word[pos]) % P_MOD, sufTree);
}

bool isPal(int fromLeft, int toLeft, int fromRight, int toRight) {
	if(fromLeft < 0 || toRight >= word.size()) {
		return false;
	}
	int leftHash = getHash(fromLeft, toLeft, hashArrPref, prefTree);
	int rightHash = getHash(word.size() - 1 - toRight, word.size() - 1 - fromRight, hashArrSuf, sufTree);	
	return (leftHash == rightHash);
}

int findOddPal(int pos) {
	int fromLength = 1, toLength = word.size() / 2;
	int result = 1;
	while(fromLength <= toLength) {
		int midLength = (fromLength + toLength) / 2;
		if(isPal(pos - midLength, pos - 1, pos + 1, pos + midLength)) {
			result = midLength;
			fromLength = midLength + 1;
		}else {
			toLength = midLength - 1;
		}
	}
	return result;
}

int findEvenPal(int pos) {
    int fromLength = 1, toLength = word.size() / 2;
    int result = -1;
    while(fromLength <= toLength) {
        int midLength = (fromLength + toLength) / 2;
        if(isPal(pos - midLength + 1, pos, pos + 1, pos + midLength)) {
            result = midLength;
            fromLength = midLength + 1;
        }else {
            toLength = midLength - 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> word >> queryCount;
    makePow();
    makeHash();
    for(int i = 0; i < queryCount; i++) {
        cin >> queryType;
        if(queryType == 1) {
            cin >> pos >> letter;
            changeLetter(pos, letter);
        }else if(queryType == 2) {
            cin >> pos;
            cout << findOddPal(pos) << "\n";
        }else {
            cin >> pos;
            cout << findEvenPal(pos) << "\n";
        }
    }
    return 0;
}
