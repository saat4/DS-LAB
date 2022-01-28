#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};
class BST {
public:
    Node *root = NULL;
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
    // traversal
    void inorder(Node *r) {
        if (r == NULL) {
            return;
        }
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    // height
    int height(Node *r) {
        if (r == NULL) {
            return 0;
        } else {
            return 1 + max(height(r->left), height(r->right));
        }
    }
    // second min
    int secondMin(Node *r) {
    }
    // second max
    int secondMax(Node *r) {
    }
} bst;
int main() {
    Node *t = bst.addNode(NULL, 10);
    t = bst.addNode(t, 6);
    t = bst.addNode(t, 15);
    t = bst.addNode(t, 3);
    t = bst.addNode(t, 8);
    t = bst.addNode(t, 20);
    bst.inorder(t);
    cout << endl;
    cout << "height : " << bst.height(t) << endl;
    cout << "second min : " << bst.secondMin(t) << endl;
    cout << "second max : " << bst.secondMax(t) << endl;
}
