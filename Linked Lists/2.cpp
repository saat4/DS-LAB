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
    void count() {
        Node *temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << endl;
        cout << "Count of nodes is : " << count << endl;
    }
};
int main() {
    CLL cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);
    cll.display();
    cll.deleteNode(10);
    cll.display();
    cll.count();
    return 0;
}

// List is : 40 30 20 10 
// List is : 40 30 20
// 
// Count of nodes is : 3