// SLL
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
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
    Node* head;
    SLL() {
        head = NULL;
    }
    void insertatend(int d) {
        Node* temp = new Node(d);
        if (head == NULL) {
            head = temp;
        } else {
            Node* temp2 = head;
            while (temp2->next != NULL) {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }
    void deletenode(int x) {
        Node* ptr = head;
        Node* prev = NULL;
        while (ptr != NULL) {
            if (ptr->data == x) {
                if (prev == NULL) {
                    head = ptr->next;
                } else {
                    prev->next = ptr->next;
                }
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
    void display() {
        Node* n = head;
        cout << "Elements are : ";
        while (n != NULL) {
            n->display();
            n = n->next;
        }
        cout << endl;
    }
};
int main() {
    SLL s;
    int ch, d, x;
    while (1) {
        cout << "\n1. Insert element\n2. Delete element\n3. Display\n4. Exit\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter element to insert at the end : ";
                cin >> d;
                s.insertatend(d);
                break;
            case 2:
                cout << "Enter element to delete : ";
                cin >> x;
                s.deletenode(x);
                break;
            case 3:
                s.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
