#include <iostream>
#include <vector>

bool existHelper(std::vector<std::vector<char>>& board, std::string word, int row, int col, int index) {
    if (index == word.length()) {
        return true; // All characters of the word have been found
    }

    int m = board.size();
    int n = board[0].size();

    if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[index]) {
        return false; // Out of bounds or mismatch
    }

    char original = board[row][col];
    board[row][col] = '#'; // Mark as visited

    bool found = existHelper(board, word, row + 1, col, index + 1) ||
                 existHelper(board, word, row - 1, col, index + 1) ||
                 existHelper(board, word, row, col + 1, index + 1) ||
                 existHelper(board, word, row, col - 1, index + 1);

    board[row][col] = original; // Restore the character

    return found;
}

bool exist(std::vector<std::vector<char>>& board, std::string word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == word[0] && existHelper(board, word, i, j, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int m, n;
    std::cout << "Enter the number of rows (m): ";
    std::cin >> m;
    std::cout << "Enter the number of columns (n): ";
    std::cin >> n;

    std::vector<std::vector<char>> board(m, std::vector<char>(n));
    std::cout << "Enter the board characters:" << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> board[i][j];
        }
    }

    std::string word;
    std::cout << "Enter the word to search for: ";
    std::cin >> word;

    bool found = exist(board, word);
    if (found) {
        std::cout << "Word found in the board!" << std::endl;
    } else {
        std::cout << "Word not found in the board." << std::endl;
    }

    return 0;
}
