#include <iostream>
#include <stack>
#include <stdexcept>

class QueueUsingStacks {
private:
    std::stack<int> stackEnqueue;
    std::stack<int> stackDequeue;

    void transfer() {
        while (!stackEnqueue.empty()) {
            stackDequeue.push(stackEnqueue.top());
            stackEnqueue.pop();
        }
    }

public:
    void enqueue(int item) {
        stackEnqueue.push(item);
    }

    int dequeue() {
        if (stackDequeue.empty()) {
            if (stackEnqueue.empty()) {
                throw std::runtime_error("Queue is empty");
            }
            transfer();
        }
        int front = stackDequeue.top();
        stackDequeue.pop();
        return front;
    }

    int peek() {
        if (stackDequeue.empty()) {
            if (stackEnqueue.empty()) {
                throw std::runtime_error("Queue is empty");
            }
            transfer();
        }
        return stackDequeue.top();
    }

    bool isEmpty() {
        return stackEnqueue.empty() && stackDequeue.empty();
    }

    int size() {
        return stackEnqueue.size() + stackDequeue.size();
    }
};

int main() {
    QueueUsingStacks queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << queue.dequeue() << std::endl;  // Output: 1
    std::cout << queue.peek() << std::endl;     // Output: 2

    queue.enqueue(4);
    std::cout << queue.size() << std::endl;     // Output: 3

    std::cout << queue.dequeue() << std::endl;  // Output: 2
    std::cout << queue.isEmpty() << std::endl;  // Output: 0 (false)
    std::cout << queue.dequeue() << std::endl;  // Output: 3
    std::cout << queue.isEmpty() << std::endl;  // Output: 1 (true)

    return 0;
}
