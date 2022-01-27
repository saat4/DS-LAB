#include <iostream>
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
    void inorder(Node *r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
};
int main() {
    BST bst;
    Node *t = bst.addNode(NULL, 10);
    t = bst.addNode(t, 6);
    t = bst.addNode(t, 7);
    t = bst.addNode(t, 15);
    t = bst.addNode(t, 8);
    t = bst.addNode(t, 12);
    t = bst.addNode(t, 14);
    t = bst.addNode(t, 9);
    bst.inorder(t);
    cout << endl;
}
