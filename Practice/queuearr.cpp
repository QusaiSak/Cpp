#include <bits/stdc++.h>
using namespace std;

class queuearr {
    int* arr;
    int front, rear, capacity;

public:
    queuearr() {
        capacity = 1000; 
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    void push(int x) {
        if (rear == capacity - 1) { 
            cout << "Queue overflow\n";
            return;
        }
        if (front == -1) { 
            front = 0;
        }
        rear++;
        arr[rear] = x;
    }

    void pop() {
        if (front == -1 || front > rear) {
            cout << "Queue underflow\n";
            return;
        }
        front++;
    }

    int peek() {
        if (front == -1 || front > rear) { 
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    ~queuearr() { 
        delete[] arr;
    }
};

int main() {
    queuearr q;
    q.push(1);
    q.push(2);
    cout << q.peek() << endl; 
    q.pop();
    cout << q.peek() << endl;
    cout << q.isEmpty() << endl;
    q.pop();
    cout << q.isEmpty() << endl;
    return 0;
}
