#include<iostream>
#include<queue>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:

    CircularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }


    bool enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)) {
            // Queue is full
            return false;
        } else if (front == -1) {
            // First element
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0; // Wrap around
        } else {
            rear++;
        }

        arr[rear] = value;
        return true;
    }


    int dequeue() {
        if (front == -1) {
            // Queue is empty
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0; // Wrap around
        } else {
            front++;
        }

        return ans;
    }


    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue contents: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~CircularQueue() {
        delete[] arr;
    }
};


int main() {
    CircularQueue q(5); // Size of queue is 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // This may fail as the queue becomes full
    q.display();


    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();


    q.enqueue(60);
    q.enqueue(70);
    q.display();

    return 0;
}
