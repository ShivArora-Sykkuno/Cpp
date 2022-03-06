#include <bits/stdc++.h>
using namespace std;

bool ifRepeating(vector<vector<char>> &board, int row, int col)
{

    unordered_set<char> s;
    for (int i = row; i < row + 3; i++)
    {
        for (int j = col; j < col + 3; j++)
        {
            if (board[i][j] != '.')
            {
                if (s.count(board[i][j]) == 1)
                    return true;
                else
                    s.insert(board[i][j]);
            }
        }
    }
    return false;
}
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int i, j;

        for (i = 0; i < 9; i++)
        {
            unordered_set<char> s;
            for (j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (s.count(board[i][j]) == 1)
                        return false;
                    else
                        s.insert(board[i][j]);
                }
            }
        }

        for (i = 0; i < 9; i++)
        {
            unordered_set<char> s;
            for (j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    if (s.count(board[j][i]) == 1)
                        return false;
                    else
                        s.insert(board[j][i]);
                }
            }
        }

        // checking in 3X3 boxes
        for (i = 0; i < 9; i += 3)
        {
            for (j = 0; j < 9; j += 3)
            {
                // checking if the box with first element i,j has repeating characters
                if (ifRepeating(board, i, j))
                    return false;
            }
        }

        return true;
    }
};