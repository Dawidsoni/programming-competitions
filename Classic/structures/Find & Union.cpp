#include<iostream>
using namespace std;

class Vertex {
    Vertex * parent;
    int rank;
public:
    int val;
    
    Vertex(int val_) : parent(this), rank(0), val(val_) {}
  
    Vertex() : parent(this), rank(0), val(0) {}
    
    Vertex * find(Vertex * vert) {
        if(vert != vert->parent) {
            vert->parent = find(vert->parent);
        }
        return vert->parent;
    }
    
    void unionSets(Vertex * x, Vertex * y) {
        Vertex * repX = find(x);
        Vertex * repY = find(y);
        if(repX->rank > repY->rank) {
            repY->parent = repX;
        }else {
            repX->parent = repY;
            if(repX->rank == repY->rank) {
                repY->rank++;
            }
        }
    }
};




int main() {
    Vertex forest[1000];
    for(int i=0;i<1000;i++)
        forest[i].val = i + 1;
    return 0;
}
