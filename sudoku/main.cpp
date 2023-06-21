#include "sudoku.hpp"
#include <iostream>
#include <vector>

// function to print board in digestible manor
void printBoard(const std::vector<std::vector<int>> &board)
{
    for (const auto &row : board)
    {
        for (const auto &i : row)
        {
            std::cout << i << " ";
        }

        std::cout << "\n";
    }

    std::cout << "\n";
}

int main()
{
    Sudoku s; // intialize sudkou class obj
    s.generate_board();

    printBoard(s.getBoard().data);

    s.make_playable(40);

    printBoard(s.getBoard().data);

    s.solve();

    printBoard(s.getBoard().data);

    std::cout << s.is_valid() << "\n";

    return 0;
}