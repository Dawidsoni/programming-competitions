#include<iostream>
#include<algorithm>
using namespace std;

class Edge {
public:
    int dist, v1, v2;
    Edge() {}
    Edge(int v1_, int v2_, int dist_) : dist(dist_), v1(v1_), v2(v2_) {}
};

bool operator < (const Edge & e1, const Edge & e2) {
    if(e1.dist < e2.dist) return true;
    return false;
}

class Vertex {
    Vertex * parent;
    int rank;
public:
    int vNum;
    Vertex() : parent(this), rank(0) {}
    Vertex(int numV_) : parent(this), rank(0), vNum(numV_) {}
    Vertex * find() {
        if(parent != this) {
            parent = parent->find();
        }
        return parent;
    }
    static void unionSets(Vertex * vert1, Vertex * vert2) {
        Vertex * v1Rep = vert1->find();
        Vertex * v2Rep = vert2->find();
        if(v1Rep->rank > v2Rep->rank) {
            v2Rep->parent = v1Rep;
        }else {
            v1Rep->parent = v2Rep;
            if(v1Rep->rank == v2Rep->rank) {
                v2Rep->rank++;
            }
        }
    }
};

Edge edge[1000000];
Vertex vertex[1000000];
int eCount, v1, v2, dist, vCount, result = 0;

int main() {
    cin >> vCount >> eCount;
    vCount++;
    for(int i = 0; i < vCount; i++) {
        vertex[i].vNum = i;
    }
    for(int i = 0; i < eCount; i++) {
        cin >> v1 >> v2 >> dist;
        edge[i] = Edge(v1, v2, dist);
    }
    sort(edge, &edge[eCount]);
    for(int i = 0; i < eCount; i++) {
        Vertex * vert1 = &vertex[edge[i].v1];
        Vertex * vert2 = &vertex[edge[i].v2];
        if(vert1->find() != vert2->find()) {
           Vertex::unionSets(&vertex[edge[i].v1], &vertex[edge[i].v2]);
           result += edge[i].dist;
        }
    }
    cout << result;
    return 0;
}
