#include<iostream>
#include<set>
using namespace std;

class odcinek {
public:
    int x1,x2,y1,y2;
    odcinek(int x_, int y_,int x_2, int y_2) : x1(x_), y1(y_), x2(x_2), y2(y_2) {}
    odcinek() {}
};

class obj_x {
public:
    bool operator()(const odcinek & a, const odcinek & b) {
        if(a.x1<b.x1) return true;
        return false;
    }
};

class obj_y {
public:
    bool operator()(const odcinek & a, const odcinek & b) {
        if(a.y<b.y) return true;
        return false;
    }
};

multiset<odcinek,obj_x> wedlug_x;
multiset<odcinek,obj_y> wedlug_y;
odcinek tablica[100000];

int main() {
    ios_base::sync_with_stdio(0);
    return 0;
}
