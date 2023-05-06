#include "generator.hpp"
#include "validSudoku.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

bool validMove(const std::vector<std::vector<int>>& board, int val, int row, int col) {
    if (std::find(board[row].begin(), board[row].end(), val) != board[row].end()) {
        return false;
    }

    for (const auto &r : board) {
        if (val == r[col]) {
            return false;
        }
    }

    for (int m = (std::floor(row / 3)) * 3; m < (std::floor(row / 3)) * 3 + 3; m++) {
        for (int n = (std::floor(col / 3) * 3); n < (std::floor(col / 3)) * 3 + 3; n++) {
            if (row != m && col != n && board[m][n] == val) {
                return false;
            }
        }
    }

    return true;
}

std::vector<int> findEmptyCell(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

bool solve(std::vector<std::vector<int>>& board) {
    std::vector<int> emptyCell = findEmptyCell(board);

    if (emptyCell[0] == -1 && emptyCell[1] == -1) {
        return true;
    }

    int row = emptyCell[0];
    int col = emptyCell[1];

    for (int num = 1; num < 10; num++) {
        if (validMove(board, num, row, col)) {
            board[row][col] = num;

            if (solve(board)) {
                return true;
            }
        }

        board[row][col] = 0;
    }

    return false;

}  

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