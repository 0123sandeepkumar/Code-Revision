#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell {
    int value;
    int row;
    int col;

    Cell(int v, int r, int c) : value(v), row(r), col(c) {}

    bool operator>(const Cell& other) const {
        return value > other.value;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;

    for (int i = 0; i < n; ++i) {
        minHeap.push(Cell(matrix[i][0], i, 0));
    }

    int count = 0;
    int result = 0;

    while (!minHeap.empty()) {
        Cell cell = minHeap.top();
        minHeap.pop();
        result = cell.value;
        ++count;

        if (count == k) {
            break;
        }

        if (cell.col < n - 1) {
            minHeap.push(Cell(matrix[cell.row][cell.col + 1], cell.row, cell.col + 1));
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    cout << "The " << k << "th smallest element is: " << kthSmallest(matrix, k) << endl;

    return 0;
}
