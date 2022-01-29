#include <bits/stdc++.h>
using namespace std;
int n;
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
    Node *root;
    BST() {
        root = NULL;
    }
    Node *addNode(Node *r, int d) {
        if (r == NULL) {
            r = new Node(d);
            return r;
        }
        if (d < r->data) {
            r->left = addNode(r->left, d);
        } else if (d > r->data) {
            r->right = addNode(r->right, d);
        }
        return r;
    }
    void inorder(Node *r) {  // traversal
        if (r == NULL) {
            return;
        }
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    void reverseInorder(Node *r) {
        if (r == NULL) {
            return;
        }
        reverseInorder(r->right);
        cout << r->data << " ";
        reverseInorder(r->left);
    }
    int height(Node *r) {  // height
        if (r == NULL) {
            return 0;
        } else {
            return 1 + max(height(r->left), height(r->right));
        }
    }
    void secondLargestandSmallest(Node *r) {
        if (r == NULL) return;
        static int count = 0;
        secondLargestandSmallest(r->right);
        count++;
        if (count == 2) {
            cout << "Second Largest : " << r->data << endl;
        }
        if (count == n - 1) {
            cout << "Second Smallest : " << r->data << endl;
        }
        secondLargestandSmallest(r->left);
    }
} bst;
int main() {
    // Node *t = bst.addNode(NULL, 10);
    // t = bst.addNode(t, 4);
    // t = bst.addNode(t, 12);
    // t = bst.addNode(t, 3);
    // t = bst.addNode(t, 8);
    // t = bst.addNode(t, 11);
    // t = bst.addNode(t, 13);
    cout << "Enter number of elements : ";
    cin >> n;
    int r, arr[n];
    cout << "Enter root : ";
    cin >> r;
    Node *t = bst.addNode(NULL, r);
    cout << "Enter remaining " << n - 1 << " elements : ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        t = bst.addNode(t, arr[i]);
    }
    cout << "Elements are : ";
    bst.inorder(t);
    cout << endl;
    cout << "Height is " << bst.height(t) << endl;
    bst.secondLargestandSmallest(t);
}