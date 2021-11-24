// Write a program to perform the following operations on doubly linked list :
// i) Creation ii) Insertion iii) Deletion iv) Traversal v) Print the list in reverse

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
class DLL {
public:
    Node *head, *tail;
    DLL() {
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
    void display() {
        Node *temp = head;
        cout << "List is : ";
        while (temp != NULL) {
            temp->display();
            temp = temp->next;
        }
        cout << endl;
    }
    void reverseDisplay() {
        Node *temp = tail;
        cout << "Reverse display : ";
        while (temp != NULL) {
            temp->display();
            temp = temp->prev;
        }
        cout << endl;
    }
};
int main() {
    DLL dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.insert(40);
    dll.display();
    dll.deleteNode(20);
    dll.display();
    dll.reverseDisplay();
    return 0;
}


// List is : 40 30 20 10 
// List is : 40 30 10
// Reverse display : 10 30 40