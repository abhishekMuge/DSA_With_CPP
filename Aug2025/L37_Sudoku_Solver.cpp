#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

private:
    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (board[row][col] == '.')
                { // empty cell
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(board, row, col, ch))
                        {
                            board[row][col] = ch; // place digit

                            if (solve(board)) // recursive call
                                return true;

                            board[row][col] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number possible
                }
            }
        }
        return true; // solved
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            // Check row
            if (board[row][i] == ch)
                return false;

            // Check column
            if (board[i][col] == ch)
                return false;

            // Check 3x3 sub-box
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == ch)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution solver;
    solver.solveSudoku(board);

    cout << "Solved Sudoku:\n";
    for (auto &row : board)
    {
        for (auto &ch : row)
            cout << ch << " ";
        cout << "\n";
    }

    return 0;
}

/*
How it Works
1. Backtracking Algorithm
  -> Find an empty cell (.).
  -> Try placing numbers 1–9.
  -> If a number is valid (row, column, subgrid check), place it.
  -> Recurse to solve the next cell.
  -> If stuck, backtrack (reset to .) and try another number.

2. Validity Check
  -> Ensures no duplicate in row, column, and 3×3 box.

3. Termination
  -> If all cells are filled correctly, the board is solved.

*/
