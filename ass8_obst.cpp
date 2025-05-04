#include <bits/stdc++.h>
#define MAX 20
using namespace std;

class Node {
    int key;
    Node *left, *right;
    
    public:
    Node() {
        key = 0; 
        left = right = NULL;
    }

    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

class OBST {
    double C[MAX][MAX]; //cost
    double W[MAX][MAX]; //weight
    int R[MAX][MAX];    //roots of OBST
    double q[MAX]; //to store access probablities of dummy keys
    double p[MAX]; //to store access probablities of actual keys

    int n; //number of keys
    int keys[MAX]; 
    Node *root;  

    public:
    OBST() {
        root = NULL;
    }

    void calculate_W_C_R() {
        double x, min;
        int i, j;
        for(i = 0; i<=n; i++) {
            W[i][i] = q[i];
            for(j = i+1; j<=n; j++) {
                W[i][j] = W[i][j-1] + p[j] + q[j];
            }
        }
    }


};

int main() {

    
    return 0;
}