#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Vertex {
public:
    Vertex() : left(NULL), right(NULL) {}
    Vertex(int w, char s) : weight(w), symb(s), left(NULL), right(NULL) {}
    int weight;
    char symb;
    Vertex * left, * right;    
    friend bool operator < (const Vertex & w1, const Vertex & w2) {
        if(w1.weight < w2.weight) return false;
        return true;
    }
};

string text;
int tCount[70];
int nCount;
priority_queue<Vertex> minQueue;
Vertex * root;

void printResult(Vertex * ptr = root, string code = "") {
    if(ptr->left == NULL && ptr->right == NULL) cout << ptr->symb << " code: " << code << endl;
    if(ptr->left != NULL) printResult(ptr->left, code + "0");
    if(ptr->right != NULL) printResult(ptr->right, code + "1");
}

int main() {
    cin >> text;
    for(int i = 0; i < (int)text.size(); i++) {
        tCount[text[i] - 'A']++;
    }
    for(int i = 0; i < 70; i++) {
        if(tCount[i] != 0) {
           minQueue.push(Vertex(tCount[i], i + 'A'));
        }
    }
    while(minQueue.size() > 1) {
        Vertex vert1 = minQueue.top();
        minQueue.pop();
        Vertex vert2 = minQueue.top();
        minQueue.pop();
        Vertex * ptr1 = new Vertex(vert1);
        Vertex * ptr2 = new Vertex(vert2);
        Vertex newV(ptr1->weight + ptr2->weight, 'a');
        newV.left = ptr1;
        newV.right = ptr2;
        minQueue.push(newV);
    }
    root = new Vertex(minQueue.top());
    printResult();
    return 0;
}
