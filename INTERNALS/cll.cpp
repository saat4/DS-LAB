// Write a program to perform the following operations on circular linked list.:
// i) Creation ii) Insertion iii) Deletion iv) Traversal v) Count of nodes

#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
    void display() {
        cout << data << " ";
    }
};
class CLL {
public:
    Node *head, *tail;
    CLL() {
        head = NULL;
        tail = NULL;
    }
    void insert(int d) {
        Node *temp = new Node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void display() {
        Node *temp = head;
        cout << "List is : ";
        while (temp != NULL) {
            temp->display();
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteNode(int d) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data == d) {
                if (temp == head) {
                    head = temp->next;
                    head->prev = NULL;
                } else if (temp == tail) {
                    tail = temp->prev;
                    tail->next = NULL;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                break;
            }
            temp = temp->next;
        }
    }
};
int main() {
    CLL cll;
    int x, ch, ele;
    while (ch != 4) {
        cout << "\nCIRCULAR LINKED LIST OPERATIONS" << endl;
        cout << "1) Insertion\n2) Deletion\n3) Display\n4) Exit\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter element to be inserted : ";
                cin >> ele;
                cll.insert(ele);
                break;
            case 2:
                cout << "Enter element to be deleted : ";
                cin >> ele;
                cll.deleteNode(ele);
                break;
            case 3:
                cll.display();
                break;
            case 4:
                break;
        }
    }
}

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 1
// Enter element to be inserted : 5

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 1
// Enter element to be inserted : 10

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 1
// Enter element to be inserted : 15

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 3
// List is : 15 10 5

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 2
// Enter element to be deleted : 10

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 3
// List is : 15 5

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 4