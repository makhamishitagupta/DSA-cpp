#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (board[r][c] == word[0] && backtrack(board, r, c, 0, word))
                {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool backtrack(vector<vector<char>> &board, int r, int c, int i, string &word)
    {
        int rows = board.size();
        int cols = board[0].size();

        // Base case: all characters matched
        if (i == word.length())
        {
            return true;
        }

        // Out of bounds or mismatch
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[i])
        {
            return false;
        }

        // Save current character and mark as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 directions
        bool found = backtrack(board, r + 1, c, i + 1, word) ||
                     backtrack(board, r - 1, c, i + 1, word) ||
                     backtrack(board, r, c + 1, i + 1, word) ||
                     backtrack(board, r, c - 1, i + 1, word);

        // Restore original character
        board[r][c] = temp;

        return found;
    }
};
int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};

    string word = "ABCCED";

    Solution sol;
    if (sol.exist(board, word))
    {
        cout << "Word found in board!" << endl;
    }
    else
    {
        cout << "Word not found in board." << endl;
    }

    return 0;
}
