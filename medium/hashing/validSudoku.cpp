#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::unordered_set<std::string> seen; // Used to store unique representations of numbers in rows, columns, and subgrids
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char num = board[i][j];
            if (num != '.') {
                std::string rowKey = "row" + std::to_string(i) + num;
                std::string colKey = "col" + std::to_string(j) + num;
                std::string subgridKey = "subgrid" + std::to_string(i / 3) + std::to_string(j / 3) + num;
                
                if (seen.find(rowKey) != seen.end() ||
                    seen.find(colKey) != seen.end() ||
                    seen.find(subgridKey) != seen.end()) {
                    return false; // Duplicate number found
                }
                
                seen.insert(rowKey);
                seen.insert(colKey);
                seen.insert(subgridKey);
            }
        }
    }
    
    return true;
}

int main() {
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    bool result = isValidSudoku(board);
    if (result) {
        std::cout << "The Sudoku board is valid." << std::endl;
    } else {
        std::cout << "The Sudoku board is not valid." << std::endl;
    }
    
    return 0;
}
