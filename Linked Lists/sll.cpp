// Write a program to perform the following operations on singly linked list:
// i) Creation ii) Insertion iii) Deletion iv) Traversal v) length of the linked list

#include <iostream>
using namespace std;
int len = 0;
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
    // creation
    Node* head;
    SLL() {
        head = NULL;
    }
    // insertion
    void insert(int d) {
        Node* n = new Node(d);
        if (head == NULL) {
            cout << "List is empty" << endl;
            head = n;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = n;
        }
        len++;
    }
    // deletion
    void deleteNode(int d) {
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            Node* temp = head;
            Node* prev = NULL;
            while (temp->data != d) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == head) {
                head = head->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            len--;
        }
        len--;
    }
    // traversal
    void display() {
        Node* temp = head;
        if (head == NULL) {
            cout << "List is empty" << endl;
        } else {
            cout << "List is : ";
            while (temp != NULL) {
                temp->display();
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main() {
    SLL s;
    // creation
    cout << "Linked List created" << endl;
    // insertion
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    // traversal
    s.display();
    // deletion
    s.deleteNode(20);
    s.display();
    // length
    cout << "Length is : " << len << endl;
}

// Linked List created
// List is empty
// List is : 10 20 30 40 
// List is : 10 30 40
// Length is : 2