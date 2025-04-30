#include <bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *left, *right;

    public:
    Node(int d) {
        data = d;
        left = right = NULL;
    }

    friend class BT;
};

class BT {
    Node *root;

    public:
    BT() {
        root = NULL;
    }

    Node* buildTree() {
        cout << "\nData (-1:NULL) : ";
        int d;
        cin >> d;

        if(d == -1) {
            return nullptr;
        }

        Node *node = new Node(d);
        cout << "Enter the value of node to the left of " << d << ":";
        node -> left = buildTree();
        cout << "Enter the value of node to the right of " << d << ":";
        node -> right = buildTree();

        return node;
    }

    void preorder(Node *node) {
        if (node == NULL)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node *node) {
        if (node == NULL)
            return;

        preorder(node->left);
        cout << node->data << " ";
        preorder(node->right);
    }

    void ipreorder(Node *node) {
        cout << "Preorder Traversal:" << endl;
        stack<Node*> st;
        while(!st.empty() || node != NULL) {
            if(node != NULL) {
                cout << node -> data << " ";
                st.push(node);
                node = node -> left;
            }
            else {
                node = st.top();
                st.pop();
                node = node -> right;
            }
        }
    }

    void iinorder(Node *node) {
        cout << "Inorder Traversal:" << endl;
        stack<Node*> st;
        while(!st.empty() || node != NULL) {
            if(node != NULL) {
                st.push(node);
                node = node -> left;
            }
            else {
                node = st.top();
                st.pop();
                cout << node -> data << " ";
                node = node -> right;
            }
        }
    }

    void ipostorder(Node *node) {
        if(node == nullptr) {
            return;
        }

        stack<Node*> st1, st2;
        st1.push(node);

        while(!st1.empty()) {
            Node *temp = st1.top();
            st1.pop();
            st2.push(temp);

            if(temp -> left) st1.push(temp -> left);
            if(temp -> right) st1.push(temp -> right);
        }

        while(!st2.empty()) {
            cout << st2.top() -> data << " ";
            st2.pop();
        }
    }

        int findHeight(Node *root) {
            if(root == nullptr) return 0;
            
            int lh = findHeight(root -> left);
            int rh = findHeight(root -> right);
            return 1 + max(lh, rh);
        }

        void deleteTree(Node *root) {
            if(root == NULL) return;

            deleteTree(root -> left);
            deleteTree(root -> right);

            cout << "Deleting Node: " << root -> data;
            delete root;
        }

        void swapNodes(Node *root) {
            if(root == NULL) {
                return;
            }

            if(root -> left && root -> right) {
                int temp = root -> left -> data;
                root -> left -> data = root -> right -> data;
                root -> right -> data = temp;
            }
        }
    

    int countLeaf(Node *root) {
        if(root == NULL) {
            return 0;
        }
        else if(root -> left == NULL && root -> right == NULL) {
            return 1;
        }
        else {
            return countLeaf(root -> left) + countLeaf(root -> right);
        }
    }
    
    Node* cloneTree(Node *root) {
        if(root == NULL) return NULL;

        Node *newRoot = new Node(root -> data);
        newRoot -> left = cloneTree(root -> left);
        newRoot -> right = cloneTree(root -> right);

        return newRoot;
    }
};

int main() {
    BT tree;
    Node *root = tree.buildTree();
    tree.ipreorder(root);
    tree.swapNodes(root);
    tree.preorder(root);


    return 0;
}
