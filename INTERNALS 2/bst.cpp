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
    // second largest
    void secondLargestUtil(Node *r, int &c) {
        if (r == NULL || c >= 2) return;
        secondLargestUtil(r->right, c);
        c++;
        if (c == 2) {
            cout << "2nd largest element is " << r->data << endl;
            return;
        }
        secondLargestUtil(r->left, c);
    }
    void secondLargest(Node *r) {
        int c = 0;
        secondLargestUtil(r, c);
    }
    // second smallest
    void secondSmallestUtil(Node *r, int &c) {
        if (r == NULL || c >= 2) return;
        secondSmallestUtil(r->left, c);
        c++;
        if (c == 2) {
            cout << "2nd smallest element is " << r->data << endl;
            return;
        }
        secondSmallestUtil(r->right, c);
    }
    void secondSmallest(Node *r) {
        int c = 0;
        secondSmallestUtil(r, c);
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
    int n, r;
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter root : ";
    cin >> r;
    Node *t = bst.addNode(NULL, r);
    cout << "Enter elements of BST : ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
        t = bst.addNode(t, arr[i]);
    }
    bst.inorder(t);
    cout << endl;
    cout << "Height is " << bst.height(t) << endl;
    bst.secondLargest(t);
    bst.secondSmallest(t);
}