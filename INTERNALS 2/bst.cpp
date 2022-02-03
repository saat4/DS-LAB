// post order
// second min
// second max
// BST

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
    void display() {
        cout << data << " ";
    }
};
class BST {
public:
    Node* rptr = NULL;
    Node* insert(Node* root, int d) {
        if (root == NULL) {
            root = new Node(d);
            return root;
        }
        if (d < root->data) {
            root->left = insert(root->left, d);
        } else if (d > root->data) {
            root->right = insert(root->right, d);
        }
        return root;
    }
    void postorder(Node* p) {
        if (p == NULL) return;
        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
    int getsecondmin(Node* a) {
        while (a->left->left != NULL) a = a->left;
        return a->data;
    }
    int getsecondmax(Node* a) {
        while (a->right->right != NULL) a = a->right;
        return a->data;
    }
} bst;
int main() {
    Node* t = bst.insert(NULL, 5);
    t = bst.insert(t, 2);
    t = bst.insert(t, 4);
    t = bst.insert(t, 7);
    t = bst.insert(t, 1);
    t = bst.insert(t, 9);
    t = bst.insert(t, 8);
    t = bst.insert(t, 3);
    t = bst.insert(t, 6);
    cout << "postorder : ";
    bst.postorder(t);
    cout << endl;
    cout << bst.getsecondmax(t);
    cout << endl;
    cout << bst.getsecondmin(t);
}