// Second minimum element in a binary tree

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
    int secondMin(Node *root) {
        if (root == NULL) return -1;
        int data = helper(root, root->data);
        if (data == INT_MAX) return -1;
        return data;
    }
    int helper(Node *node, int mindata) {
        if (node == NULL) return INT_MAX;
        if (node->data > mindata) return node->data;
        int left = helper(node->left, mindata);
        int right = helper(node->right, mindata);
        return min(left, right);
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
    cout << "\nSecond minimum element is : " << bt.secondMin(root) << endl;
}