#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
    string name;
    Node *next;
    Node *down;

    public: 
        Node(string name) {
            this->name = name;
            next = NULL;
            down = NULL;
        }
    
    friend class Graph;
};

class Graph {
    Node *head = NULL;
    public:

    void addNode(string s1, string s2) {
        if(head == NULL) {
            Node *node1 = new Node(s1);
            Node *node2 = new Node(s2);
            head = node1;
            node1 -> next = node2;
        }
        else {
            Node *currentNode = head, *prevNode = NULL;
            bool found = false;
            
            while(currentNode != NULL) {
                if(currentNode -> name == s1) {
                    found = true;
                    Node *currentListNode = currentNode;
                    while(currentListNode -> next != NULL) {
                        currentListNode = currentListNode -> next;
                    }
                    Node *node2 = new Node(s2);
                    currentListNode -> next = node2;
                    break;
                }

                prevNode = currentNode;
                currentNode = currentNode -> down;
            }

            if(!found) {
                Node *node1 = new Node(s1);
                Node *node2 = new Node(s2);
                prevNode -> down = node1;
                node1 -> next = node2;
            }
        }
    }

    void BFS(string startNode) {
        Node* currentNode = head;
        queue<string> q;
        vector<string> visited;
    
        bool nodeExists = false;
    
        // Check if startNode exists and initialize BFS
        while (currentNode != nullptr) {
            if (currentNode->name == startNode) {
                nodeExists = true;
                visited.push_back(startNode);
                q.push(startNode);
                break;
            }
            currentNode = currentNode->down;
        }
    
        if (!nodeExists) {
            cout << "Given node not in the graph" << endl;
            return;
        }
    
        // BFS traversal
        while (!q.empty()) {
            string node = q.front();
            q.pop();
            cout << node << " ";
    
            // Find the node in the adjacency list again
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->name == node) {
                    Node* adj = temp->next; // neighbors
                    while (adj != nullptr) {
                        if (find(visited.begin(), visited.end(), adj->name) == visited.end()) {
                            visited.push_back(adj->name);
                            q.push(adj->name);
                        }
                        adj = adj->next;
                    }
                    break;
                }
                temp = temp->down;
            }
        }
    }
    
};

int main() {

    Graph g;
    g.addNode("A","B");
    g.addNode("B", "C");
    g.addNode("A", "C");
    g.addNode("C","A");
    g.BFS("A");
    return 0;
}