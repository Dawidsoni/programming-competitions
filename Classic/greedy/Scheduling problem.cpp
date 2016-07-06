#include<stdio.h>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

class Vertex {
    Vertex * parent;
    int rank;
public:
    int hFree;
    Vertex() : parent(this), rank(0), hFree(INT_MAX) {}
    static Vertex * find(Vertex * roz) {
        if(roz->parent != roz) {
            roz->parent = find(roz->parent);
        }
        return roz->parent;
    }
    static void unionSets(Vertex * z1, Vertex * z2) {
        Vertex * rep1 = find(z1);
        Vertex * rep2 = find(z2);
        if(rep1->rank > rep2->rank) {
            rep2->parent = rep1;
        }else {
            rep1->parent = rep2;
            if(rep1->rank == rep2->rank) rep2->rank++;
        }
    }
};

Vertex forest[100000];
int taskCount;
typedef pair<int, int> IPair;
IPair arr[100000];
int penalty, maxInd;
int sum;
int minLeft;

int main() {
    scanf("%d", &taskCount);
    for(int i = 0; i < taskCount; i++) {
        scanf("%d%d", &penalty, &maxInd);
        arr[i] = IPair(penalty, maxInd);
    }
    sort(arr, arr + taskCount, greater<IPair> ());
    for(int i = 0; i < taskCount; i++) {
        maxInd = arr[i].second;
        Vertex * rep = Vertex::find(&forest[maxInd]);
        if(rep->hFree == INT_MAX) {
            minLeft = maxInd - 1;
            Vertex * left = Vertex::find(&forest[maxInd - 1]);
            Vertex * right = Vertex::find(&forest[maxInd + 1]);
            if(left->hFree != INT_MAX) {
                minLeft = left->hFree;
                Vertex::unionSets(rep, left);
            }
            if(right->hFree != INT_MAX) {
                Vertex::unionSets(rep, right);
            }
            Vertex::find(rep)->hFree = minLeft;
        }else if(rep->hFree == 0){
            sum += arr[i].first;
        }else {
            maxInd = minLeft = rep->hFree - 1;
            Vertex * left = Vertex::find(&forest[maxInd]);
            Vertex::unionSets(rep, &forest[maxInd + 1]);
            if(left->hFree != INT_MAX) {
                minLeft = left->hFree;
                Vertex::unionSets(rep,left);
            }
            Vertex::find(rep)->hFree = minLeft;
        }
    }
    printf("%d",sum);
    return 0;
}
