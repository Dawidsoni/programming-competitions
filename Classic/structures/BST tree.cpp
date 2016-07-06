#include<stdio.h>
#include<climits>
using namespace std;

class Vertex {
public:
    Vertex() : parent(NULL), left(NULL), right(NULL) {}
    Vertex(int val_, Vertex * par_, Vertex * lew, Vertex * right_) : val(val_), parent(par_), left(lew), right(right_) {}
    int val;
    Vertex * parent, * left, * right;
};

Vertex * root = NULL;
int count, vert;

Vertex * insertV(int val) {
    if(root == NULL) {
        root = new Vertex(val,NULL,NULL,NULL);
        return root;
    }
    Vertex * ptr = root;
    while(true) {
        if(ptr->val < val) {
            if(ptr->right == NULL) {
                Vertex * newV = new Vertex(val, ptr, NULL, NULL);
                ptr->right = newV;
                return newV;
            }
            ptr = ptr->right;
        }else {
            if(ptr->left == NULL) {
                Vertex * newV = new Vertex(val, ptr, NULL, NULL);
                ptr->left = newV;
                return newV;
            }
            ptr = ptr->left;
        }
    }
}



void wypisz(Vertex * ptr = root) {
    if(ptr->left != NULL) wypisz(ptr->left);
    printf("%d ", ptr->val);
    if(ptr->val == 13 && ptr->right != NULL) printf("rozny");
    if(ptr->right != NULL) wypisz(ptr->right);
}

Vertex * minEl(Vertex * ptr = root) {
    while(ptr->left != NULL) {
        ptr = ptr->left;
    }
    return ptr;
}

Vertex * maxEl(Vertex * ptr = root) {
    while(ptr->right != NULL) {
        ptr = ptr->right;
    }
    return ptr;
}

Vertex * successor(Vertex * ptr = root) {
    if(ptr->right != NULL) {
        return minEl(ptr->right);
    }
    Vertex * parent = ptr->parent;
    if(parent == NULL) return parent;
    while(parent != NULL && parent->left != ptr) {
        ptr = parent;
        parent = ptr->parent;
    }
    return parent;
}

Vertex * precedor(Vertex * ptr = root) {
    if(ptr->left != NULL) {
        return maxEl(ptr->left);
    }
    Vertex * parent = ptr->parent;
    while(parent != NULL && parent->right != ptr) {
        ptr = parent;
        parent = ptr->parent;
    }
    return parent;
}

void insertV(Vertex * akt_syn, Vertex * newV) {
    Vertex * parent = akt_syn->parent;
    if(parent != NULL) {
        if(newV != NULL) newV->parent = parent;
        if(parent->left == akt_syn) parent->left = newV;
        else parent->right = newV;
    }else {
        root = newV;
        root->parent = NULL;
    }
}

void deleteV(Vertex * ptr = root) {
    if(ptr->left == NULL) { 
        insertV(ptr, ptr->right);
    }else if(ptr->left != NULL && ptr->right == NULL) { 
        insertV(ptr, ptr->left);
    }else {
        Vertex * nast = successor(ptr);
        if(nast->parent == ptr) { 
            insertV(ptr, nast);
            nast->left = ptr->left;
            ptr->left->parent = nast;
        }else { 
            insertV(nast, nast->right);
            insertV(ptr, nast);
            nast->left = ptr->left;
            ptr->left->parent = nast;
            nast->right = ptr->right;
            ptr->right->parent = nast;
        }
    }
    delete ptr;
}

Vertex * ptr[100000];

int main() {
    scanf("%d", &count);
    for(int i = 0; i < count; i++) {
        scanf("%d", &vert);
        ptr[i] = insertV(vert);
    }
    return 0;
}
