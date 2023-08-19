#include <iostream>
#include <vector>
using namespace std;

class GameOfLife {
public:
    GameOfLife(int rows, int cols) : rows(rows), cols(cols) {
        grid.resize(rows, std::vector<bool>(cols, false));
    }

    void setCell(int row, int col, bool value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            grid[row][col] = value;
        }
    }

    bool getCell(int row, int col) const {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return grid[row][col];
        }
        return false;
    }

    void evolve() {
        std::vector<std::vector<bool>> nextGrid(rows, std::vector<bool>(cols, false));

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int neighbors = countAliveNeighbors(row, col);

                if (grid[row][col]) {
                    // Any live cell with 2 or 3 live neighbors survives.
                    nextGrid[row][col] = (neighbors == 2 || neighbors == 3);
                } else {
                    // Any dead cell with exactly 3 live neighbors becomes a live cell.
                    nextGrid[row][col] = (neighbors == 3);
                }
            }
        }

        grid = nextGrid;
    }

    void printGrid() const {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                std::cout << (grid[row][col] ? "*" : " ");
            }
            std::cout << std::endl;
        }
    }

private:
    int countAliveNeighbors(int row, int col) const {
        int count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (getCell(row + i, col + j)) {
                    ++count;
                }
            }
        }
        return count;
    }

    int rows;
    int cols;
    std::vector<std::vector<bool>> grid;
};

int main() {
    GameOfLife game(10, 10);

    // Initialize the initial state of the grid
    game.setCell(3, 4, true);
    game.setCell(3, 5, true);
    game.setCell(3, 6, true);

    std::cout << "Initial state:" << std::endl;
    game.printGrid();

    for (int i = 0; i < 5; ++i) {
        game.evolve();
        std::cout << "Generation " << i + 1 << ":" << std::endl;
        game.printGrid();
    }

    return 0;
}
