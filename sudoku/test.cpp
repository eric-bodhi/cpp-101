#include "grid.hpp"
#include "sudoku.hpp"
#include <iostream>

bool testValidator()
{
    grid example1({{5, 3, 4, 6, 7, 8, 9, 1, 2},
                   {6, 7, 2, 1, 9, 5, 3, 4, 8},
                   {1, 9, 8, 3, 4, 2, 5, 6, 7},
                   {8, 5, 9, 7, 6, 1, 4, 2, 3},
                   {4, 2, 6, 8, 5, 3, 7, 9, 1},
                   {7, 1, 3, 9, 2, 4, 8, 5, 6},
                   {9, 6, 1, 5, 3, 7, 2, 8, 4},
                   {2, 8, 7, 4, 1, 9, 6, 3, 5},
                   {3, 4, 5, 2, 8, 6, 1, 7, 9}});

    Sudoku s1(example1);

    grid example2({{1, 2, 3, 4, 5, 6, 7, 8, 9},
                   {4, 5, 6, 7, 8, 9, 1, 2, 3},
                   {7, 8, 9, 1, 2, 3, 4, 5, 6},
                   {2, 3, 4, 5, 6, 7, 8, 9, 1},
                   {5, 6, 7, 8, 9, 1, 2, 3, 4},
                   {8, 9, 1, 2, 3, 4, 5, 6, 7},
                   {3, 4, 5, 6, 7, 8, 9, 1, 2},
                   {6, 7, 8, 9, 1, 2, 3, 4, 5},
                   {9, 1, 2, 3, 4, 5, 6, 7, 8}});

    Sudoku s2(example2);

    return (s1.is_valid() && s2.is_valid());
}

bool testGenerator()
{
    if (!testValidator())
    {
        return false;
    }

    Sudoku s;
    s.generate_board();

    return s.is_valid();
}

bool testSolver()
{
    Sudoku s;
    s.generate_board();
    s.make_playable(40);
    s.solve();

    return s.is_valid();
}

void test()
{
    // test 10 generations of generator and solver
    bool generator = true;
    bool validator = testValidator();
    bool solver = true;

    for (int i = 1; i < 11; i++)
    {
        generator = testGenerator();
        solver = testSolver();

        if (!generator || !solver)
        {
            break;
        }
    }

    auto conversion = [](bool input) -> std::string
    {
        if (input)
        {
            return "Working";
        }

        return "Not working";
    };

    std::cout << "Validator Status: " << conversion(validator) << "\n";
    std::cout << "Generator status: " << conversion(generator) << "\n";
    std::cout << "Solver status: " << conversion(solver) << "\n";
}