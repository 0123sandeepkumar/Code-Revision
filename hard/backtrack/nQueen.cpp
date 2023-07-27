#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solveNQueensUtil(vector<vector<int>>& board, int row, int N, vector<vector<string>>& solutions) {
    if (row == N) {
        vector<string> solution;
        for (int i = 0; i < N; ++i) {
            string rowStr = "";
            for (int j = 0; j < N; ++j) {
                rowStr += (board[i][j] == 1) ? "Q" : ".";
            }
            solution.push_back(rowStr);
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueensUtil(board, row + 1, N, solutions);
            board[row][col] = 0; // Backtrack if the current placement leads to a dead-end
        }
    }
}

vector<vector<string>> solveNQueens(int N) {
    vector<vector<string>> solutions;
    vector<vector<int>> board(N, vector<int>(N, 0));
    solveNQueensUtil(board, 0, N, solutions);
    return solutions;
}

int main() {
    int N = 4; // Change N to the desired board size
    vector<vector<string>> solutions = solveNQueens(N);
    for (int i = 0; i < solutions.size(); ++i) {
        cout << "Solution " << i + 1 << ":" << endl;
        for (const string& row : solutions[i]) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
