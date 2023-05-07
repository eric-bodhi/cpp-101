#include <iostream>
#include <vector>
#include "sudoku.hpp"
#include "generator.hpp"
#include "solve.hpp"
#include "validSudoku.hpp"

int main() {
    Sudoku s;
    std::vector<std::vector<int>> solvedBoard = s.generate_board();

    std::cout << "Generated Board:" << "\n";
    for (const auto &r : solvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }

        std::cout << "\n";
    }
    std::cout << "\n";

    std::vector<std::vector<int>> unsolvedBoard = s.make_playable(solvedBoard, 45);

    std::cout << "Degenerated Board:" << "\n";
    for (const auto &r : unsolvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    s.solve(unsolvedBoard);

    std::cout << "Solved Board:" << "\n";
    for (const auto &r : unsolvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    std::cout << s.is_valid(unsolvedBoard) << "\n";

    return 0;
}