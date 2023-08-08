#include <iostream>
#include <queue>

class StackUsingQueues {
private:
    std::queue<int> q1, q2;

public:
    void push(int value) {
        q1.push(value);
    }

    void pop() {
        if (q1.empty()) {
            std::cout << "Stack is empty. Cannot pop.\n";
            return;
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        std::swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            std::cout << "Stack is empty.\n";
            return -1; // Return a suitable value
        }

        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topValue = q1.front();
        q2.push(topValue);
        std::swap(q1, q2);

        return topValue;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top element: " << stack.top() << "\n";
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << "\n";

    return 0;
}
