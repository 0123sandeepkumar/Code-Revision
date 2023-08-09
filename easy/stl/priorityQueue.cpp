#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    // Insertion
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    std::cout << "Priority queue elements after insertion:" << std::endl;
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;

    // Re-insertion
    pq.push(15);
    pq.push(25);

    std::cout << "Priority queue elements after re-insertion:" << std::endl;
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;

    // Insertion of negative values
    pq.push(-5);
    pq.push(-15);

    std::cout << "Priority queue elements after insertion of negative values:" << std::endl;
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;

    return 0;
}
