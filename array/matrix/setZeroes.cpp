#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zeroAtCol = false;
        bool zeroAtRow = false;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Check if the first column contains any zero
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                zeroAtCol = true;
                break;
            }
        }

        // Check if the first row contains any zero
        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] == 0) {
                zeroAtRow = true;
                break;
            }
        }

        // Use the first row and first column as markers
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // Set the elements to zero based on the markers in the first column
        for (int r = 1; r < rows; r++) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < cols; c++) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Set the elements to zero based on the markers in the first row
        for (int c = 1; c < cols; c++) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < rows; r++) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Handle the first row if it has a zero
        if (zeroAtRow) {
            for (int c = 0; c < cols; c++) {
                matrix[0][c] = 0;
            }
        }

        // Handle the first column if it has a zero
        if (zeroAtCol) {
            for (int r = 0; r < rows; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};

int main() {
    Solution sol;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 1}
    };

    // Call the setZeroes function
    sol.setZeroes(matrix);

    // Print the modified matrix
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
