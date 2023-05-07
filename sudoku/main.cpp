#include <iostream>
#include <vector>
#include "sudoku.hpp"
#include "generator.hpp"
#include "solve.hpp"
#include "validSudoku.hpp"

int main() {
    Sudoku s; // intialize sudkou class obj
    std::vector<std::vector<int>> solvedBoard = s.generate_board(); // generate board using sudoku class generate_board function

    std::cout << "Generated Board:" << "\n"; // print the generated board
    for (const auto &r : solvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }

        std::cout << "\n";
    }
    std::cout << "\n";

    std::vector<std::vector<int>> unsolvedBoard = s.make_playable(solvedBoard, 45); // make the board "playable", i.e. degenerate it

    std::cout << "Degenerated Board:" << "\n"; // print the playing board
    for (const auto &r : unsolvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    s.solve(unsolvedBoard); // solve the playing board

    std::cout << "Solved Board:" << "\n"; // output the solved playing board
    for (const auto &r : unsolvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << s.is_valid(unsolvedBoard) << "\n"; // double checks if solved playing board is valid

    return 0;
}