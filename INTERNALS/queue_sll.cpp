// queue using SLL
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
    void display() {
        cout << data << " ";
    }
};
class Queue {
public:
    Node* front = NULL;
    Node* rear = NULL;
    void enqueue(int d) {
        Node* temp = new Node(d);
        if (front == NULL) {
            front = temp;
            rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
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
        Node* t = front;
        cout << "Elements are : ";
        while (t != NULL) {
            t->display();
            t = t->next;
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int x, ch, ele;
    cout << "\nQUEUE OPERATIONS" << endl;
    while (1) {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter element to be inserted : ";
                cin >> ele;
                q.enqueue(ele);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Wrong choice" << endl;
        }
    }
}

// QUEUE OPERATIONS

// 1. Enqueue 2. Dequeue 3. Display 4. Exit
// Enter your choice : 1 Enter element to be inserted : 5

// 1. Enqueue 2. Dequeue 3. Display 4. Exit
// Enter your choice : 1 Enter element to be inserted : 10

// 1. Enqueue 2. Dequeue 3. Display 4. Exit
// Enter your choice : 1 Enter element to be inserted : 15

// 1. Enqueue 2. Dequeue 3. Display 4. Exit
// Enter your choice : 3 Elements are : 5 10 15

// 1. Enqueue 2. Dequeue 3. Display 4. Exit
// Enter your choice : 2

// 1. Enqueue 2. Dequeue 3. Display 4. Exit
// Enter your choice : 3 Elements are : 10 15

// 1. Enqueue 2. Dequeue 3. Display 4. Exit
// Enter your choice : 4