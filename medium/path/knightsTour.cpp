#include <iostream>
#include <vector>

const int N = 8; // Chessboard size

// Possible moves for the knight
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, const std::vector<std::vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

void printSolution(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

bool knightTourUtil(int x, int y, int moveCount, std::vector<std::vector<int>>& board) {
    if (moveCount == N * N) {
        return true; // All squares visited
    }

    for (int i = 0; i < 8; ++i) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        
        if (isValid(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;
            if (knightTourUtil(nextX, nextY, moveCount + 1, board)) {
                return true;
            }
            board[nextX][nextY] = -1; // Backtrack
        }
    }

    return false;
}

bool solveKnightTour() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, -1));
    int startRow = 0, startCol = 0;
    
    // Starting position
    board[startRow][startCol] = 0;
    
    if (knightTourUtil(startRow, startCol, 1, board)) {
        printSolution(board);
        return true;
    } else {
        std::cout << "Solution does not exist.\n";
        return false;
    }
}

int main() {
    solveKnightTour();
    return 0;
}
