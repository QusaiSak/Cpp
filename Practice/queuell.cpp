#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int d) {
        data = d;
        next = NULL;
    }
};

class queue {
    node* front;
    node* rear;

public:
    queue() {
        front = rear = NULL;
    }

    void enqueue(int val) {
        node* n = new node(val);
        if (rear == NULL) {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }

    int dequeue() {
        if (front == NULL) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int val = front->data;
        node* toDelete = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete toDelete;
        return val;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    queue q;
    q.enqueue(1);
    cout << q.peek() << endl;
    q.dequeue();
    q.enqueue(2);
    cout << q.peek() << endl;
    cout << q.isEmpty() << endl;
    q.dequeue();
    cout << q.isEmpty() << endl;
    return 0;
}
