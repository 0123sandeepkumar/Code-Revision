#include <iostream>
#include <queue>

class MovingAverage {
private:
    std::queue<int> window;
    int windowSize;
    int sum;

public:
    MovingAverage(int size) {
        windowSize = size;
        sum = 0;
    }

    double next(int val) {
        if (window.size() == windowSize) {
            sum -= window.front();
            window.pop();
        }

        window.push(val);
        sum += val;

        return static_cast<double>(sum) / window.size();
    }
};

int main() {
    MovingAverage movingAverage(3);

    int values[] = {1, 10, 3, 5};
    for (int val : values) {
        double average = movingAverage.next(val);
        std::cout << "Moving average: " << average << std::endl;
    }

    return 0;
}
