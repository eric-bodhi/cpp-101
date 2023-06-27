#include "sudoku.hpp"
#include "grid.hpp"
#include <algorithm>
#include <iterator>
#include <optional>
#include <random>
#include <vector>

Sudoku::Sudoku(const grid &initialBoard) : board(initialBoard)
{
}

void Sudoku::generate_board()
{
    int base = 3;
    int side = base * base;

    std::vector<int> rBase(base);
    std::iota(rBase.begin(), rBase.end(), 0);
    std::vector<int> rows = generateSequence(rBase);
    std::vector<int> cols = generateSequence(rBase);
    std::vector<int> nums(side);
    std::iota(nums.begin(), nums.end(), 1);

    nums = shuffle(nums);

    for (int r = 0; r < rows.size(); r++)
    {
        for (int c = 0; c < cols.size(); c++)
        {
            this->board.place(r, c, nums[pattern(rows[r], cols[c], base)]);
        }
    }
}

void Sudoku::make_playable(int num_blanks)
{
    std::vector<int> indices(81);
    std::iota(indices.begin(), indices.end(), 0);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    for (int i = 0; i < num_blanks; ++i)
    {
        int index = indices[i];
        this->board.place(index / 9, index % 9, 0);
    }
}

bool Sudoku::solve()
{
    std::optional<std::pair<int, int>> emptyCell =
        this->findEmptyCell(); // finds the first empty cell

    if (!emptyCell.has_value())
    {
        return true;
    }

    auto [row, col] = emptyCell.value(); // unpacks emptyCell

    // finds which number that is able to be placed at row, col (empty cell)
    for (int num = 1; num < 10; num++)
    {
        if (this->validMove(num, row, col))
        {
            this->board.place(row, col,
                              num); // if found then place the num at row, col

            if (this->solve())
            { // recursively continue
                return true;
            }
        }

        this->board.place(row, col, 0); // if it doesn't work out (false) then turn
                                        // it back to 0 and backtrack
    }

    return false;
}

bool Sudoku::validMove(int val, int row, int col) const
{
    // checks if val is already in rows
    if (std::find(this->board.data[row].begin(), this->board.data[row].end(), val) !=
        this->board.data[row].end())
    {
        return false;
    }

    // checks if val is already in cols
    for (const auto &r : this->board.data)
    {
        if (val == r[col])
        {
            return false;
        }
    }

    // checks if val is in the 3x3 row, col is in
    for (int m = (std::floor(row / 3)) * 3; m < (std::floor(row / 3)) * 3 + 3; m++)
    {
        for (int n = (std::floor(col / 3) * 3); n < (std::floor(col / 3)) * 3 + 3; n++)
        {
            if (row != m && col != n && this->board.get(m, n) == val)
            {
                return false;
            }
        }
    }

    return true;
}

std::optional<std::pair<int, int>> Sudoku::findEmptyCell() const
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (this->board.get(i, j) == 0)
            {
                return std::optional<std::pair<int, int>>(std::make_pair(i, j));
            }
        }
    }

    return std::nullopt;
}

bool Sudoku::is_valid() const
{
    // combines all 4 functions to find if board is valid or not
    return ((this->validRows() && this->validCols() && this->validSquares()));
}

grid Sudoku::getBoard() const
{
    return this->board;
}

// checks if rows are valid (according to sudoku)
bool Sudoku::validRows() const
{
    for (const auto &row : this->board.data)
    {
        if (!hasDuplicates(row))
        {
            return false;
        }
    }

    return true;
}

// checks if cols are valid (according to sudoku)
bool Sudoku::validCols() const
{
    std::vector<std::vector<int>> columns(9, std::vector<int>(9));

    for (int c = 0; c < 9; c++)
    {
        for (int r = 0; r < 9; r++)
        {
            columns[c][r] = this->board.get(r, c);
        }
    }

    for (const auto &col : columns)
    {
        if (!hasDuplicates(col))
        {
            return false;
        }
    }

    return true;
}

// checks if squares are valid (according to sudoku)
bool Sudoku::validSquares() const
{
    for (int i = 3; i < 10; i += 3)
    {
        for (int j = 3; j < 10; j += 3)
        {
            std::vector<int> square;

            for (int k = 0; k < 3; ++k)
            {
                square.insert(square.end(), this->board.data[i - 3 + k].begin() + (j - 3),
                              this->board.data[i - 3 + k].begin() + j);
            }

            if (!hasDuplicates(square))
            {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku::hasDuplicates(const std::vector<int> &unit) const
{
    std::vector<int> seen;

    for (const auto &i : unit)
    {
        if (std::find(seen.begin(), seen.end(), i) == seen.end())
        {
            seen.push_back(i);
        }

        else
        {
            return false;
        }
    }

    return true;
}

std::vector<int> shuffle(const std::vector<int> &v)
{
    std::vector<int> result = v;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(result.begin(), result.end(), g);
    return result;
}

// returns the sudoku baseline solution
int pattern(int r, int c, int base)
{
    int side = base * base;
    return (base * (r % base) + r / base + c) % side;
}

std::vector<int> generateSequence(std::vector<int> const &base)
{
    std::vector<int> sequence;
    sequence.reserve(base.size() * base.size());

    for (const auto g : shuffle(base))
    {
        for (const auto x : shuffle(base))
        {
            sequence.push_back(g * base.size() + x);
        }
    }

    return sequence;
}