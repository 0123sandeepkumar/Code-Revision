#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
    if (index == word.length()) {
        return true; // The whole word is found
    }

    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '#') {
        return false; // Out of bounds or the current cell is already visited
    }

    if (board[row][col] != word[index]) {
        return false; // The current cell does not match the next character of the word
    }

    char originalChar = board[row][col];
    board[row][col] = '#'; // Mark the cell as visited to avoid reusing it

    // Recursively search for the next character in all four directions
    bool found = dfs(board, word, row - 1, col, index + 1) ||
                 dfs(board, word, row + 1, col, index + 1) ||
                 dfs(board, word, row, col - 1, index + 1) ||
                 dfs(board, word, row, col + 1, index + 1);

    board[row][col] = originalChar; // Restore the original character

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board[0].empty() || word.empty()) {
        return false; // Empty board or word, or both
    }

    int rows = board.size();
    int cols = board[0].size();

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (dfs(board, word, row, col, 0)) {
                return true;
            }
        }
    }

    return false; // Word not found in the board
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";
    bool found = exist(board, word);

    if (found) {
        cout << "The word \"" << word << "\" exists in the board." << endl;
    } else {
        cout << "The word \"" << word << "\" does not exist in the board." << endl;
    }

    return 0;
}
