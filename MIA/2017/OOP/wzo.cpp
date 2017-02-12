#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int LType;
typedef pair<int, char> CPair; 
typedef pair<int, int> IPair;
typedef pair<IPair, int> HPair;

const int MAX_SIZE = 100100;
const int LETTER_COUNT = 3100100;
const int Q1_CONST = 1000000093;
const int P1_MOD = 1000000123;
const int Q2_CONST = 1000000337;
const int P2_MOD = 1000000463;


int textCount, patternCount;
string textArr[MAX_SIZE];
string patternArr[MAX_SIZE];
vector<CPair> tree[LETTER_COUNT];
int vCount = 1;
int textLength = 0;
int preOrder[LETTER_COUNT], postOrder[LETTER_COUNT];
int pow1[LETTER_COUNT];
int pow2[LETTER_COUNT];
vector<int> hashArr1[MAX_SIZE];
vector<int> hashArr2[MAX_SIZE];
HPair hashMap[LETTER_COUNT];
int hashMapCount;

void makePow() {
	pow1[0] = 1;
	pow2[0] = 1;
	for(int i = 1; i < textLength; i++) {
		pow1[i] = ((LType)pow1[i - 1] * Q1_CONST) % P1_MOD;
		pow2[i] = ((LType)pow2[i - 1] * Q2_CONST) % P2_MOD;		
	}
}

void countHash(int num) {
	int textSize = textArr[num].size();
	hashArr1[num].reserve(textSize);
	hashArr2[num].reserve(textSize);
	hashArr1[num][0] = textArr[num][textSize - 1];
	hashArr2[num][0] = textArr[num][textSize - 1];	
//	cout << hashArr[num][0] << " ";	
	for(int i = 1; i < textSize; i++) {
		int index = textSize - 1 - i;
		hashArr1[num][i] = (hashArr1[num][i - 1] + (LType)pow1[i] * textArr[num][index]) % P1_MOD;
		hashArr2[num][i] = (hashArr2[num][i - 1] + (LType)pow2[i] * textArr[num][index]) % P2_MOD;
//		cout << hashArr[num][i] << " ";
	}
//	cout << "\n";
}

void countHashArr() {
	makePow();
	for(int i = 0; i < textCount; i++) {
		countHash(i);
	}
}

void readData() {
	ios_base::sync_with_stdio(false);
	cin >> textCount >> patternCount;
	for(int i = 0; i < textCount; i++) {
		cin >> textArr[i];
		textLength += textArr[i].size();
	}
	for(int i = 0; i < patternCount; i++) {
		cin >> patternArr[i];
	}	
}

void addWord(string text, int pos, int vertex) {
	if(pos == (int)text.size()) {
		return;
	}
	for(int i = 0; i < (int)tree[vertex].size(); i++) {
		if(tree[vertex][i].second == text[pos]) {
			addWord(text, pos + 1, tree[vertex][i].first);
			return;
		}
	}
	tree[vertex].push_back(CPair(vCount, text[pos]));
	vCount++;
	addWord(text, pos + 1, vCount - 1);	
}

void createPrefTree() {
	for(int i = 0; i < textCount; i++) {
		addWord(textArr[i], 0, 0);
	}
}

int createOrder(int vtx, int orderNum) {
	preOrder[vtx] = orderNum;
	for(int i = 0; i < (int)tree[vtx].size(); i++) {
		orderNum = createOrder(tree[vtx][i].first, orderNum); 
	}
	postOrder[vtx] = orderNum;
	return orderNum + 1;
}

void printPrefTree() {
	for(int i = 0; i < vCount; i++) {
//		cout << i << " ";
//		cout << "[" << preOrder[i] << ", " << postOrder[i] << "]: "; 
		for(int j = 0; j < (int)tree[i].size(); j++) {
//			cout << "(" << tree[i][j].first << ", " << tree[i][j].second << ") ";
		}
//		cout << "\n";
	}
}

void countHashDfs(int textNum, int pos, int vtx) {
	int textSize = textArr[textNum].size();
	int textPos = textSize - 1 - pos;
	IPair hash;
	if(textPos < 0) {
		hash = IPair(0, 0);
	}else {
		hash.first = hashArr1[textNum][textPos];	
		hash.second = hashArr2[textNum][textPos];		
	}
	hashMap[hashMapCount++] = HPair(hash, postOrder[vtx]);
	if(pos == textSize) {
		return;
	}
	for(int i = 0; i < (int)tree[vtx].size(); i++) {
		if(tree[vtx][i].second == textArr[textNum][pos]) {
			countHashDfs(textNum, pos + 1, tree[vtx][i].first);			
		}
	}
}

void countHashMap() {
	for(int i = 0; i < textCount; i++) {
		countHashDfs(i, 0, 0);
	}
	sort(hashMap, hashMap + hashMapCount);
}

IPair countHash(string text, int index) {
	int itCount = text.size() - 1 - index;
	if(itCount == 0) {
		return IPair(0, 0);
	}
	IPair result = IPair(text[text.size() - 1], text[text.size() - 1]);
	for(int i = 1; i < itCount; i++) {
		int index = text.size() - 1 - i;
		result.first = (result.first + (LType)pow1[i] * text[index]) % P1_MOD;
		result.second = (result.second + (LType)pow2[i] * text[index]) % P2_MOD;
	}
	return result;	
}

int countInterval(string text, int splitIndex, int fromInd, int toInd) {
	IPair hash = countHash(text, splitIndex);	 
	HPair fromPair = HPair(hash, fromInd);
	HPair toPair = HPair(hash, toInd);
	HPair *fromPtr = lower_bound(hashMap, hashMap + hashMapCount, fromPair);
	HPair *toPtr = upper_bound(hashMap, hashMap + hashMapCount, toPair);
	return (toPtr - fromPtr);
}

int countResult(string text, int splitIndex, int pos, int vtx) {
	if(pos == splitIndex) {
		return countInterval(text, splitIndex, preOrder[vtx], postOrder[vtx]);
	}
	for(int i = 0; i < (int)tree[vtx].size(); i++) {
		if(text[pos] == tree[vtx][i].second) {
			return countResult(text, splitIndex, pos + 1, tree[vtx][i].first);
		} 
	}
	return 0;
}

int main() {
	readData();
	createPrefTree();
	createOrder(0, 0);
	printPrefTree();
	countHashArr();
	countHashMap();
	for(int i = 0; i < patternCount; i++) {
		int splitIndex = 0;
		for(int j = 0; j < (int)patternArr[i].size(); j++) {
			if(patternArr[i][j] == '*') {
				splitIndex = j;
				break;
			}
		}
		cout << countResult(patternArr[i], splitIndex, 0, 0) << "\n";
	}	
	return 0;
}
