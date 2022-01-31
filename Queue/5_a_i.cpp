// implement queue using arrays
#include <bits/stdc++.h>
using namespace std;
class Queue {
public:
    int queue[100], n = 100, front = -1, rear = -1;
    void enqueue() {
        if (rear == n - 1) {
            cout << "Queue is full" << endl;
            return;
        } else {
            if (front == -1) {
                front = 0;
            }
            int val;
            cout << "Enter the element to be inserted: ";
            cin >> val;
            rear++;
            queue[rear] = val;
        }
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow" << endl;
            return;
        } else {
            cout << "Element deleted is: " << queue[front] << endl;
            front++;
        }
    }
    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue is :";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    Queue q;
    int ch;
    do {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (ch != 4);
}
