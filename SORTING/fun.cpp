/* WAP to create Binary Search tree for given numbers, 
   find the second maximum, second minimum element in that tree,
   Print the elements in Post order Traversal
*/

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
    void inorder(Node *r) {
        if (r == NULL) {
            return;
        }
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    void secondLargestandSmallest(Node *r) {
        if (r == NULL) return;
        static int count = 0;
        secondLargestandSmallest(r->right);
        count++;
        if (count == 2) {
            cout << "second maximum element: " << r->data << endl;
        }
        if (count == n - 1) {
            cout << "second minimum element: " << r->data << endl;
        }
        secondLargestandSmallest(r->left);
    }
} bst;
int main() {
    int arr[n];
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node *t = bst.addNode(NULL, arr[0]);
    for (int i = 1; i < n; i++) {
        t = bst.addNode(t, arr[i]);
    }
    bst.secondLargestandSmallest(t);
    cout << "post are traversal elements: ";
    bst.inorder(t);
    cout << endl;
}
