#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
    if (index == word.length()) {
        return true; // Word found
    }
    
    int numRows = board.size();
    int numCols = board[0].size();
    
    if (row < 0 || row >= numRows || col < 0 || col >= numCols || board[row][col] != word[index]) {
        return false; // Out of bounds or mismatch
    }
    
    char originalChar = board[row][col];
    board[row][col] = '#'; // Mark the current cell as visited
    
    // Explore adjacent cells
    bool found = dfs(board, word, row + 1, col, index + 1) ||
                 dfs(board, word, row - 1, col, index + 1) ||
                 dfs(board, word, row, col + 1, index + 1) ||
                 dfs(board, word, row, col - 1, index + 1);
    
    board[row][col] = originalChar; // Restore the original character
    
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int numRows = board.size();
    int numCols = board[0].size();
    
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            if (board[row][col] == word[0] && dfs(board, word, row, col, 0)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    
    string word = "ABCCED";
    
    if (exist(board, word)) {
        cout << "Word exists in the grid." << endl;
    } else {
        cout << "Word does not exist in the grid." << endl;
    }
    
    return 0;
}
