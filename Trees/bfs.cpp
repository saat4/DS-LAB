// BFS
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
    void display() {
        cout << data << " ";
    }
};
class BST {
public:
    Node *root;
    BST() {
        root = NULL;
    }
    Node *addNode(Node *r, int d) {
        if (r == NULL) {
            Node *nptr = new Node(d);
            return nptr;
        } else if (r->data > d) {
            r->left = addNode(r->left, d);
            return r;
        } else {
            r->right = addNode(r->right, d);
            return r;
        }
    }
    int search(Node *r, int val) {
        if (r == NULL) return -1;
        if (r->data == val) return 1;
        if (r->data > val) return search(r->left, val);
        return search(r->right, val);
    }
    void inorder(Node *r) {
        if (r == NULL) {
            return;
        } else {
            inorder(r->left);
            r->display();
            inorder(r->right);
        }
    }
    void levelorder(Node *root) {
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                Node *fptr = q.front();
                cout << fptr->data << " ";
                q.pop();
                if (fptr->left) q.push(fptr->left);
                if (fptr->right) q.push(fptr->right);
            }
            cout << endl;
        }
        cout << endl;
    }
};
int main() {
    BST bst;
    Node *t = bst.addNode(NULL, 10);
    t = bst.addNode(t, 4);
    t = bst.addNode(t, 12);
    t = bst.addNode(t, 3);
    t = bst.addNode(t, 8);
    t = bst.addNode(t, 11);
    t = bst.addNode(t, 13);
    bst.levelorder(t);
}