// Write a program that implement stack (its operations) using Linked List.
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
class Stack {
public:
    Node *top;
    int len;
    Stack() {
        top = NULL;
        len = 0;
    }
    void push(int d) {
        Node *temp = new Node(d);
        temp->next = top;
        top = temp;
        len++;
    }
    int pop() {
        Node *temp = top;
        top = top->next;
        len--;
        int d = temp->data;
        delete temp;
        return d;
    }
    void display() {
        Node *temp = top;
        cout << "Stack is : ";
        while (temp != NULL) {
            temp->display();
            temp = temp->next;
        }
        cout << endl;
    }
    int peek() {
        return top->data;
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    cout << "Popped element is : " << s.pop() << endl;
    s.display();
    cout << "Peek element is : " << s.peek() << endl;
    return 0;
}


// Stack is : 40 30 20 10 
// Popped element is : 40
// Stack is : 30 20 10
// Peek element is : 30