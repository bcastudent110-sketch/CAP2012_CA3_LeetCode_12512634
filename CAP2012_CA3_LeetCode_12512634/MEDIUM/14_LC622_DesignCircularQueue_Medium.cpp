#include <iostream>
using namespace std;

class MyCircularQueue {
public:
    int arr[1000];
    int front;
    int rear;
    int count;
    int size;

    MyCircularQueue(int k) {
        front = 0;
        rear = -1;
        count = 0;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;
        count++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % size;
        count--;

        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};

int main() {
    MyCircularQueue q(3);

    cout << q.enQueue(1) << endl;
    cout << q.enQueue(2) << endl;
    cout << q.enQueue(3) << endl;

    // Queue full hai, isliye false (0)
    cout << q.enQueue(4) << endl;

    cout << "Rear: " << q.Rear() << endl;

    q.deQueue();

    q.enQueue(4);

    cout << "Rear: " << q.Rear() << endl;

    return 0;
}