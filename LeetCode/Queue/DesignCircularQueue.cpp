class MyCircularQueue {
    int* arr;
    int front;
    int rear,n;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        n = k;
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if((rear+1)%n == front){

            return false;
        }
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = value;
        }
        else{
            rear = (rear+1)%n;
            arr[rear] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if(front == -1 && rear == -1){
            return false;
        }else if(rear==front){
            front = -1;
            rear = -1;
        }
        else{
            front = (front+1)%n;
        }
        return true;
    }
    
    int Front() {
        if(front == -1 && rear == -1){
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if(front == -1 && rear == -1){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((rear+1)%n == front){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */