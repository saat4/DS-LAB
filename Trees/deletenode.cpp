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
class BST {
public:
    Node *root = NULL;
    Node *addNode(Node *r, int d) {
        if (r == NULL) {
            Node *nptr = new Node(d);
            return nptr;
        } else if (r->data > d) {
            r->left = addNode(r->left, d);
            return r;
        } else {
            r->right = addNode(r->right, d);
            return r;
        }
    }
    Node *search(Node *r, int val) {
        if (r == NULL) return NULL;
        if (r->data == val) return r;
        if (r->data > val) return search(r->left, val);
        return search(r->right, val);
    }
    void inorder(Node *r) {
        if (r == NULL) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }
    void deleteNode(Node *r, int d) {
        if (r == NULL) return;
        Node *dptr = search(r, d);
        if (dptr != NULL) {
            Node *pptr = getparent(r, dptr);
            if (dptr->left == NULL && dptr->right == NULL) {
                if (pptr->left == dptr) {
                    pptr->left = NULL;
                } else {
                    pptr->right = NULL;
                }   
                delete dptr;
            } else {
                if (dptr->left == NULL || dptr->right == NULL) {
                    Node *pptr = getparent(r, dptr);
                    if (pptr->left == dptr) {
                        if (dptr->right != NULL) {
                            pptr->left = dptr->right;
                        } else {
                            pptr->left = dptr->left;
                        }
                    } else {
                        if (dptr->right != NULL) {
                            pptr->right = dptr->right;
                        } else {
                            pptr->right = dptr->left;
                        }
                    }
                } else {
                    Node *inos = getmin(dptr->right);
                    deleteNode(r, inos->data);
                    dptr->data = inos->data;
                }
            }
        }
    }
    Node *getmin(Node *r) {
        if (r == NULL) return NULL;
        if (r->left == NULL) return r;
        return getmin(r->left);
    }
    Node *getparent(Node *r, Node *dptr) {
        if (r == NULL) return NULL;
        if (r->left == dptr || r->right == dptr) return r;
        if (r->data > dptr->data) return getparent(r->left, dptr);
        return getparent(r->right, dptr);
    }
};
int main() {
    BST bst;
    Node *t = bst.addNode(NULL, 10);
    t = bst.addNode(t, 6);
    t = bst.addNode(t, 7);
    t = bst.addNode(t, 15);
    t = bst.addNode(t, 8);
    t = bst.addNode(t, 12);
    t = bst.addNode(t, 14);
    t = bst.addNode(t, 9);
    cout << "Before deletion" << endl;
    bst.inorder(t);
    cout << endl;
    cout << "After deletion" << endl;
    bst.deleteNode(t, 7);
    bst.inorder(t);
    cout << endl;
    int a;
    cout << "Enter element to search : ";
    cin >> a;
    Node *res = bst.search(t, a);
    if (res != NULL) {
        cout << "Found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
}
