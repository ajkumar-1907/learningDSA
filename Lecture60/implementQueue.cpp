#include <iostream>
#include<queue>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size)
            cout << "Queue is Full" << endl;
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (qfront == rear)
            return -1;
        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear) {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        if (qfront == rear)
            return -1;
        return arr[qfront];
    }

    ~Queue() {
        delete[] arr;
    }
};

// Sample usage
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.enqueue(40);
    cout << "Front element: " << q.front() << endl;

    cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;

    return 0;
}
