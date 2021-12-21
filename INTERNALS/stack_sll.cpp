// implement push and pop stack operations using a SLL
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
class Stack {
public:
    Node* top;
    Stack() {
        top = NULL;
    }
    void push(int d) {
        Node* temp = new Node(d);
        if (top == NULL) {
            top = temp;
        } else {
            temp->next = top;
            top = temp;
        }
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void display() {
        Node* t = top;
        cout << "Elements are : ";
        while (t != NULL) {
            t->display();
            t = t->next;
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    int x, ch, ele;
    cout << "\nSTACK OPERATIONS" << endl;
    while (1) {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter element to be pushed : ";
                cin >> ele;
                s.push(ele);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                return 0;
            default:
                cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

// STACK OPERATIONS

// 1. Push
// 2. Pop
// 3. Display
// 4. Exit
// Enter your choice : 1
// Enter element to be pushed : 5

// 1. Push
// 2. Pop
// 3. Display
// 4. Exit
// Enter your choice : 1
// Enter element to be pushed : 10

// 1. Push
// 2. Pop
// 3. Display
// 4. Exit
// Enter your choice : 1
// Enter element to be pushed : 15

// 1. Push
// 2. Pop
// 3. Display
// 4. Exit
// Enter your choice : 3
// Elements are : 15 10 5

// 1. Push
// 2. Pop
// 3. Display
// 4. Exit
// Enter your choice : 2

// 1. Push
// 2. Pop
// 3. Display
// 4. Exit
// Enter your choice : 3
// Elements are : 10 5

// 1. Push
// 2. Pop
// 3. Display
// 4. Exit
// Enter your choice : 4