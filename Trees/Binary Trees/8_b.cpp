// Traversals in binary trees

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
class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = NULL;
    }
    bool printLevel(Node* root, int level) {
        if (root == nullptr) return false;
        if (level == 1) {
            cout << root->data << " ";
            return true;
        }
        bool left = printLevel(root->left, level - 1);
        bool right = printLevel(root->right, level - 1);
        return left || right;
    }
    void levelorder(Node* root) {
        int level = 1;
        while (printLevel(root, level)) level++;
    }
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
} bt;
int main() {
    Node* root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(14);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(16);
    cout << "Inorder traversal : ";
    bt.levelorder(root);
    cout << "\nPreorder traversal : ";
    bt.preorder(root);
    cout << "\nPostorder traversal : ";
    bt.postorder(root);
    cout << "\nInorder traversal : ";
    bt.inorder(root);
    cout << endl;
}