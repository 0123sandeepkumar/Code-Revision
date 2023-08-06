#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> regularStack;
    std::stack<int> minStack;

public:
    void push(int val) {
        regularStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (!regularStack.empty()) {
            if (regularStack.top() == minStack.top()) {
                minStack.pop();
            }
            regularStack.pop();
        }
    }

    int top() {
        if (!regularStack.empty()) {
            return regularStack.top();
        }
        throw std::runtime_error("Stack is empty.");
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        throw std::runtime_error("Stack is empty.");
    }
};
