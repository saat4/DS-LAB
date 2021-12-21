// SINGLY LINKED LIST
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
    void display() {
        cout << data << " ";
    }
};
class SLL {
public:
    Node *hptr = NULL;
    void insertAtEnd(int d) {
        Node *temp = new Node(d);
        if (hptr == NULL) {
            hptr = temp;
        } else {
            Node *ptr = hptr;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    void display() {
        Node *t = hptr;
        cout << "Elements are : ";
        while (t != NULL) {
            t->display();
            t = t->next;
        }
        cout << endl;
    }
    void deletenode(int v) {
        Node *ptr = hptr;
        Node *prev = NULL;
        while (ptr != NULL) {
            if (ptr->data == v) {
                if (prev == NULL) {
                    hptr = ptr->next;
                } else {
                    prev->next = ptr->next;
                }
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
};

int main() {
    SLL l;
    int x, ch, ele, pos;
    cout << "\nSINGLY LINKED LIST OPERATIONS" << endl;
    while (1) {
        cout << "\n1)Insert At End\n2)Delete node\n3)Display\n4)Exit" << endl;
        cout << "Enter choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter a value : ";
                cin >> x;
                l.insertAtEnd(x);
                break;
            case 2:
                cout << "Enter a value : ";
                cin >> ele;
                l.deletenode(ele);
                break;
            case 3:
                l.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

// SINGLY LINKED LIST OPERATIONS

// 1)Insert At End
// 2)Delete node
// 3)Display
// 4)Exit
// Enter choice : 1
// Enter a value : 5

// 1)Insert At End
// 2)Delete node
// 3)Display
// 4)Exit
// Enter choice : 1
// Enter a value : 10

// 1)Insert At End
// 2)Delete node
// 3)Display
// 4)Exit
// Enter choice : 1
// Enter a value : 15

// 1)Insert At End
// 2)Delete node
// 3)Display
// 4)Exit
// Enter choice : 3
// Elements are : 5 10 15

// 1)Insert At End
// 2)Delete node
// 3)Display
// 4)Exit
// Enter choice : 2
// Enter a value : 10

// 1)Insert At End
// 2)Delete node
// 3)Display
// 4)Exit
// Enter choice : 3
// Elements are : 5 15

// 1)Insert At End
// 2)Delete node
// 3)Display
// 4)Exit
// Enter choice : 4