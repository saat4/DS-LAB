// Queue
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
class Queue {
public:
    Node *front, *rear;
    Queue() {
        front = rear = NULL;
    }
    void enqueue(int d) {
        Node* n = new Node(d);
        if (front == NULL) {
            front = rear = n;
        } else {
            rear->next = n;
            rear = n;
        }
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
    void display() {
        Node* n = front;
        cout << "Elements are : ";
        while (n != NULL) {
            cout << n->data << ' ';
            n = n->next;
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int ch, d, x;
    while (1) {
        cout << "\n1. Enqueue    2. Dequeue    3. Display    4. Exit\nEnter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter element to insert : ";
                cin >> d;
                q.enqueue(d);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
