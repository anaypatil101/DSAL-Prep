#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

    public:
    Node(int d) {
        data = d;
        left = right = NULL;
    }

    Node() {
        data = 0;
        left = right = NULL;
    }
    friend class BST;
};

class BST {
    Node *root = NULL;

    public:
    void insert(int d) {
        if(root == NULL) {
            root = new Node(d);
        }
        else {
            //find the insert location
            Node *curr = root, *prev;
            while(curr != NULL) {
                if(d > curr -> data) {
                    prev = curr;
                    curr = curr -> right;
                }
                else if(d < curr -> data) {
                    prev = curr; 
                    curr = curr -> left;
                }
                else {
                    cout << d << " is already present in the BST";
                    return;
                }
            }

            Node *newNode = new Node(d);
            if(d > prev -> data) {
                prev -> right = newNode;
            }
            else {
                prev -> left = newNode;
            }
        }
    }

    bool search(int d) {
        if(root == NULL) {
            return false;
        }
        Node *curr = root;

        while(curr != NULL) {
            if(d > curr -> data) {
                curr = curr -> right;
            }
            else if(d < curr -> data) {
                curr = curr -> left;
            }
            else {
                return true;
            }
        }
        return false;
        }

        void preorder() {
            cout << "Preorder Traversal: "; 
            stack<Node*> st1;
            Node *temp = root;
            while(!st1.empty() || temp != NULL) {
                if(temp != NULL) {
                    st1.push(temp);
                    cout << temp -> data << " ";
                    temp = temp -> left;
                }
                else {
                    temp = st1.top(); st1.pop();
                    temp = temp -> right;
                }
            }
        }

        void inorder() {
            cout << "Preorder Traversal: "; 
            stack<Node*> st1;
            Node *temp = root;
            while(!st1.empty() || temp != NULL) {
                if(temp != NULL) {
                    st1.push(temp);
                    temp = temp -> left;
                }
                else {
                    temp = st1.top(); st1.pop();
                    cout << temp -> data << " ";
                    temp = temp -> right;
                }
            }
        }

        void postorder() {
            stack<Node*> st1, st2;
            st1.push(root);
            while(!st1.empty()) {
                Node *temp = st1.top(); st1.pop();
                st2.push(temp);

                if(temp -> left) st1.push(temp -> left);
                if(temp -> right) st1.push(temp -> right);
            }

            while(!st2.empty()) {
                cout << st2.top() -> data << " ";
                st2.pop();                                                                  
            }
        }

        Node* swapNodes(Node *node) {
            if(node == NULL) return NULL;
            if(node -> left && node -> right) {
                int temp = node -> left -> data;
                node -> left -> data = node -> right -> data;
                node -> right -> data = temp;
            }
            swapNodes(node -> left);
            swapNodes(node -> right);
        }
    };

int main() {
    

    return 0;
}