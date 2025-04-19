#include<iostream>
#include<vector>
using namespace std;

// time complexity O(n+m)
int main() {
    //sorted in rows and sorted in columns individually
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}};
    int target = 5;

    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = n - 1; // corner element of the matix which can be consider similar to mid

    while(r < m && c >= 0) {
        if(target == matrix[r][c]){
            cout << "found" << endl;
            break;
        } else if(target < matrix[r][c])
            c--;
        else
            r++;
    }

    return 0;
}