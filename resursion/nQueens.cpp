#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string>& board, int row, int column, int n) { 
    // Check vertical column
    for (int i = 0; i < row; i++) {
        if (board[i][column] == 'Q') return false;
    }

    // Check left diagonal
    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Check right diagonal
    for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';  // Place Queen
            nQueens(board, row + 1, n, ans);  // Recur for next row
            board[row][j] = '.';  // Backtrack
        }
    }
}

vector<vector<string>> solveQueens(int n) {
    vector<string> board(n, string(n, '.'));  // Initialize n×n board with '.'
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> ans = solveQueens(n);
    
    for (auto &solution : ans) {
        for (auto &row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
 
    return 0;
}


// Start with empty board:
// ....
// ....
// ....
// ....

// Row 0 → Try placing Queen:
// - Place Q at (0,0), recurse to Row 1:
// Q...
// ....
// ....
// ....

//   Row 1 → Try placing Queen:
//   - Place Q at (1,2), recurse to Row 2:
//   Q...
//   ..Q.
//   ....
//   ....

//     Row 2 → Try placing Queen:
//     - Place Q at (2,3), recurse to Row 3:
//     Q...
//     ..Q.
//     ...Q
//     ....

//       Row 3 → Try placing Queen:
//       - Place Q at (3,1), valid solution:
//       Q...
//       ..Q.
//       ...Q
//       .Q..
      
//       **Store this solution in `ans`.**
//       **Backtrack:** Remove last Queen and try new positions in Row 3.
