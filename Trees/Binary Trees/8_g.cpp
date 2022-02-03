// check if a tree is symmetric or not

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
class Solution {
public:
    bool isSymmetric(Node* X, Node* Y) {
        if (X == NULL && Y == NULL) return true;
        return (X != NULL && Y != NULL) && isSymmetric(X->left, Y->right) && isSymmetric(X->right, Y->left);
    }
    bool isSymmetric(Node* root) {
        if (root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
} s;
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->left->left = new Node(6);
    cout << "Inorder traversal : ";
    s.inorder(root);
    cout << endl;
    if (s.isSymmetric(root)) {
        cout << "Symmetric";
    } else {
        cout << "Not symmetric";
    }
}
