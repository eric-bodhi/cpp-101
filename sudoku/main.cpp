#include <iostream>
#include <vector>
#include "sudoku.hpp"
#include "generator.hpp"
#include "solve.hpp"
#include "validSudoku.hpp"

void printBoard(const std::vector<std::vector<int>> &board) {
    for (const auto &row : board) {
        for (const auto &i : row) {
            std::cout << i << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}

int main() {
    Sudoku s; // intialize sudkou class obj
    s.generate_board();

    printBoard(s.getBoard());

    s.make_playable(40);

    printBoard(s.getBoard());

    s.solve();

    printBoard(s.getBoard());

    std::cout << s.is_valid() << "\n";

    return 0;
}