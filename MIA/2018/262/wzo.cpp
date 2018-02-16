#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_NUM = 60;
const int MAX_SIZE = 300000;

typedef pair<int, int> IPair;

int arrCount, num;
vector<IPair> indArr[MAX_NUM];
int result; 

void combineVec(vector<IPair> & indVec, int arrInd) {
    for(int i = 0; i < (int)indVec.size(); i++) {
        vector<IPair>::iterator it = lower_bound(indVec.begin(), indVec.end(), IPair(indVec[i].second + 1, -1));
        while(it != indVec.end() && it->first == indVec[i].second + 1) {
            indArr[arrInd].push_back(IPair(indVec[i].first, it->second));
            it++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> arrCount;
    for(int i = 0; i < arrCount; i++) {
        cin >> num;
        indArr[num].push_back(IPair(i, i)); 
    }
    for(int i = 1; i < MAX_NUM; i++) {
        if(indArr[i].size() > 0) {
            result = i;
        }   
        sort(indArr[i].begin(), indArr[i].end());
//        for(int j = 0; j < indArr[i].size(); j++) {
//            cout << "(" << indArr[i][j].first << ", " << indArr[i][j].second << ") ";
//        }
//        cout << "\n";
        combineVec(indArr[i], i + 1); 
    }
    cout << result << "\n";
    return 0;
}
