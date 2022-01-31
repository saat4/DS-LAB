// height of binary tree

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
class BinaryTree {
public:
    Node *root;
    BST() {
        root = NULL;
    }
    void inorder(Node *r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    int height(Node *r) {
        if (r == NULL) return 0;
        return 1 + max(height(r->left), height(r->right));
    }
} bt;
int main() {
    Node *root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(14);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(16);
    cout << "Inorder traversal : ";
    bt.inorder(root);
    cout << "\nHeight of the tree is : " << bt.height(root);
}