// BST
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
    cout << "Enter number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node *t = bst.addNode(NULL, arr[0]);
    for (int i = 1; i < n; i++) {
        t = bst.addNode(t, arr[i]);
    }
    cout << "Elements are : ";
    bst.inorder(t);
    cout << endl;
    cout << "Height is " << bst.height(t) << endl;
    bst.secondLargestandSmallest(t);
}