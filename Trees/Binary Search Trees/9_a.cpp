// check if tree is a BST or not

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
    int isBST(Node* root) {
        if (root == NULL) return 1;
        if (root->left != NULL && root->left->data > root->data) return 0;
        if (root->right != NULL && root->right->data < root->data) return 0;
        if (!isBST(root->left) || !isBST(root->right)) return 0;
        return 1;
    }
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
} sol;
int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    cout << "Inorder traversal : ";
    sol.inorder(root);
    cout << endl;
    if (sol.isBST(root)) {
        cout << "Is BST";
    } else {
        cout << "Not a BST";
    }
}
