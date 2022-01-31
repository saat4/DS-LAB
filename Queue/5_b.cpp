#include <bits/stdc++.h>
using namespace std;
class Stack {
public:
    int *arr, top, capacity;
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }
    bool isfull() {
        return top == capacity - 1;
    }
    bool isempty() {
        return top == -1;
    }
    void push(int d) {
        if (isfull()) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = d;
    }
    int pop() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }
};
class Queue {
public:
    Stack *s1, *s2;
    Queue(int capacity) {
        s1 = new Stack(capacity);
        s2 = new Stack(capacity);
    }
    bool isfull() {
        return s1->isfull() && s2->isfull();
    }
    bool isempty() {
        return s1->isempty() && s2->isempty();
    }
    void enqueue(int d) {
        if (isfull()) {
            cout << "Queue is full" << endl;
            return;
        }
        s1->push(d);
    }
    int dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        if (s2->isempty()) {
            while (!s1->isempty()) {
                s2->push(s1->pop());
            }
        }
        return s2->pop();
    }
};
int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
}