#include "generator.h"
#include "validSudoku.h"
#include "solve.h"

int main() {
    std::vector<std::vector<int>> solvedBoard = generate_board();

    std::cout << "Generated Board:" << "\n";

    for (const auto &r : solvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    std::vector<std::vector<int>> unsolvedBoard = makePlayable(solvedBoard, 45);

    std::cout << "Degenerated Board:" << "\n";

    for (const auto &r : unsolvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";

    solve(unsolvedBoard);

    std::cout << "Solved Board:" << "\n";

    for (const auto &r : unsolvedBoard) {
        for (const auto &c : r) {
            std::cout << c << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";

    std::cout << validSudoku(unsolvedBoard) << "\n";

    return 0;
}
