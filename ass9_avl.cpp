#include <bits/stdc++.h>
using namespace std;

class Node {
    int key;
    string value;
    int height;
    Node *left, *right;

    public:
    Node() {
        left = right = NULL;
        height = 1;
    }
    friend class AVL;
};

class AVL {
    Node *root = NULL;

    int getHeight(Node *node) {
        return 1 + max( getHeight(node -> left), getHeight(node -> right) );
    }

    int getBalanceFactor(Node *node) {
        if(node == NULL)  
            return NULL;

        return getHeight(node -> left) - getHeight(node -> right);
    }

    void updateHeight(Node *node) {
        node -> height = getHeight(node);
    }

    Node* LLRotation(Node *node) {
        Node *newRoot = node -> left;
        newRoot -> right = node;
        node -> left = NULL;

        //very imp (might forget this)
        updateHeight(node);
        updateHeight(newRoot);
    }

    Node *RRotation(Node *node) {
        Node *newRoot = node -> right;
        newRoot -> left = node;
        node -> right = NULL;

        //imp 
        updateHeight(node);
        updateHeight(newRoot);
    }
};


int main() {



    return 0;
}