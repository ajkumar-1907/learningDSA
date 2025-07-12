#include<iostream>
#include<queue>
using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }


    bool pushFront(int x)
    {
        if (isFull())
            return false;

        if (isEmpty())
            front = rear = 0;
        else if (front == 0)
            front = size - 1;
        else
            front--;

        arr[front] = x;
        return true;
    }


    bool pushRear(int x)
    {
        if (isFull())
            return false;

        if (isEmpty())
            front = rear = 0;
        else if (rear == size - 1)
            rear = 0;
        else
            rear++;

        arr[rear] = x;
        return true;
    }


    int popFront()
    {
        if (isEmpty())
            return -1;

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;

        return ans;
    }


    int popRear()
    {
        if (isEmpty())
            return -1;

        int ans = arr[rear];
        arr[rear] = -1;

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;

        return ans;
    }


    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }


    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    // Check if deque is empty
    bool isEmpty()
    {
        return (front == -1);
    }

    // Check if deque is full
    bool isFull()
    {
        return ((front == 0 && rear == size - 1) ||
                (rear == (front - 1 + size) % size));
    }


    void display()
    {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deque contents: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    // Destructor
    ~Deque()
    {
        delete[] arr;
    }
};


int main()
{
    Deque dq(5); // Capacity is 5

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushFront(2);
    dq.pushRear(30);

    dq.display();

    cout << "Pop front: " << dq.popFront() << endl;
    cout << "Pop rear: " << dq.popRear() << endl;

    dq.display();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    cout << (dq.isFull() ? "Deque is full" : "Deque is not full") << endl;
    cout << (dq.isEmpty() ? "Deque is empty" : "Deque is not empty") << endl;

    return 0;
}
