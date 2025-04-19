#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int m = matrix.size(), n = matrix[0].size();

    int startRow = 0, startCol = 0, endRow = m - 1, endCol = n - 1;
    vector<int> ans;

    while(startRow <= endRow && startCol <= endCol) {
        // top
        for(int j=startCol; j<=endCol; j++) {
            ans.push_back(matrix[startRow][j]);
        }

        // right
        for(int i=startRow + 1; i<=endRow; i++) {
            ans.push_back(matrix[i][endCol]);
        }

        // bottom
        for(int j=endCol - 1; j>=startCol; j--) {
            if(startRow == endRow) {
                break;
            }
            ans.push_back(matrix[endRow][j]);
        }

        // left
        for(int i=endRow - 1; i>=startRow; i--) {
            if(startCol == endCol) {
                break;
            }
            ans.push_back(matrix[i][startCol]);
        }

        startRow++; endRow--; startCol++; endCol--;
    }

    for(int i=0; i<(n*m); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
