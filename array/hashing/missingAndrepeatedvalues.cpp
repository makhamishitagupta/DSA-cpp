#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size();
    int a, b;  // a => repeated && b => missing number

    int expSum = (n*n*((n*n) + 1))/2;
    int actualSum = 0;

    for(int i = 0; i<n; i++) {
        for(int j=0; j<n; j++) {
            actualSum += grid[i][j];
            if(s.find(grid[i][j]) != s.end()) { //if it exit already
                a = grid[i][j];
            }

            s.insert(grid[i][j]);
        }
    }

    b = expSum + a - actualSum;

    cout << a << ", " << b << endl;    

    return 0;
}