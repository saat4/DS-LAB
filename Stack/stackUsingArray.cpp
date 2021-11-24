// Write a program that implement stack (its operations) using Arrays
#include <iostream>
using namespace std;
class Stack {
public:
    int *arr;
    int top, capacity, len;
    Stack(int l) {
        capacity = l;
        arr = new int[l];
        top = -1;
    }
    void push(int x) {
        arr[++top] = x;
        len++;
    }
    int pop() {
        int x = arr[top];
        top--;
        len--;
        return x;
    }
    int peek() {
        return arr[top];
    }
    void display() {
        cout << "Stack is : ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    cout << "Popped element is : " << s.pop() << endl;
    cout << "Top element is : " << s.peek() << endl;
    s.display();
}


// Stack is : 40 30 20 10 
// Popped element is : 40
// Top element is : 30
// Stack is : 30 20 10