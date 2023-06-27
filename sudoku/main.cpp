#include "sudoku.hpp"
#include "test.hpp"

int main()
{
    Sudoku s; // intialize sudkou class obj
    s.generate_board();

    s.getBoard().printBoard();

    s.make_playable(40);

    s.getBoard().printBoard();

    s.solve();

    s.getBoard().printBoard();

    test();

    return 0;
}