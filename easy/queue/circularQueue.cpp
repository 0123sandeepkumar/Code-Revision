#include <bits/stdc++.h>

using namespace std;

class CircularQueue {
private:
    std::vector<int> data;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size) {
        capacity = size + 1; // One extra slot to distinguish between full and empty states
        data.resize(capacity);
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue is full. Enqueue operation failed." << std::endl;
            return;
        }
        data[rear] = item;
        rear = (rear + 1) % capacity;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Dequeue operation failed." << std::endl;
            return -1; // You can choose how to handle this case
        }
        int item = data[front];
        front = (front + 1) % capacity;
        return item;
    }
};

int main() {
    CircularQueue queue(4);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << queue.dequeue() << std::endl; // Output: 1

    queue.enqueue(4);
    queue.enqueue(5); // This will fail as the queue is full

    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";
    }
    std::cout << std::endl; // Output: 2 3

    return 0;
}
