// CLL
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next, *prev;
    Node(int d) {
        data = d;
        prev = next = NULL;
    }
};
class CLL {
public:
    Node *head, *tail;
    CLL() {
        head = tail = NULL;
    }
    void addAtTail() {
        int d;
        cout << "Enter element to insert at end : ";
        cin >> d;
        Node *temp = new Node(d);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void deleteNode() {
        int d;
        cout << "Enter element to delete : ";
        cin >> d;
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
                return;
            }
            temp = temp->next;
        }
    }
};
int main() {
    CLL cll;
    int x, ch, ele;
    while (1) {
        cout << "\nCIRCULAR LINKED LIST OPERATIONS" << endl;
        cout << "1) Insertion\n2) Deletion\n3) Display\n4) Exit\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cll.addAtTail();
                break;
            case 2:
                cll.deleteNode();
                break;
            case 3:
                cll.display();
                break;
            case 4:
                cout << "Exit" << endl;
                exit(0);
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
// Enter element to insert at end : 5

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 1
// Enter element to insert at end : 10

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 1
// Enter element to insert at end : 15

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 3
// 5 10 15

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 2
// Enter element to delete : 10

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 3
// 5 15

// CIRCULAR LINKED LIST OPERATIONS
// 1) Insertion
// 2) Deletion
// 3) Display
// 4) Exit
// Enter your choice : 4
// Exit