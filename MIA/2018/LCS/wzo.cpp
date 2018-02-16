#include <iostream>
#include <vector>
using namespace std;

int seqCount, seqSize, elem, result;
int posArr[60][2100];
vector<int> graph[2100];
int maxPath[2100];

int dfs(int vertex) {
    if(maxPath[vertex] > 0) {
        return maxPath[vertex];
    }
    int result = 1;
    for(int i = 0; i < (int)graph[vertex].size(); i++) {
        result = max(result, dfs(graph[vertex][i]) + 1);
    }
    maxPath[vertex] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> seqCount >> seqSize;
    for(int i = 0; i < seqCount; i++) {
        for(int j = 0; j < seqSize; j++) {
            cin >> elem;
            posArr[i][elem] = j;
        }
    }
    for(int i = 1; i <= seqSize; i++) {
        for(int j = 1; j <= seqSize; j++) {
            for(int k = 0; k < seqCount; k++) {
                if(posArr[k][i] >= posArr[k][j]) {
                    break;
                }
                if(k + 1 == seqCount) {
                    graph[i].push_back(j);
                }
            }
        }
    }
    for(int i = 1; i <= seqSize; i++) {
        result = max(result, dfs(i));
    }
    cout << result << "\n";
    return 0;
}
