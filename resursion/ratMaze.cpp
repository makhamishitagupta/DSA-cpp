#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC => O(4^(n^2))
// SC => O(n^2) => for visted matrix
// SC => O(1) => without visted matrix

void helper(vector<vector<int>>& mat, int r, int c, string path, vector<string>& ans, vector<vector<bool>>& visit) {
    int n = mat.size();

    // Out of bounds or hitting a wall (0) or revisiting a cell
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || visit[r][c]) 
        return;

    // Reached the destination
    if (r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    visit[r][c] = true;  // Mark as visited
    // can also do without visited as mat[r][c] = -1 => means it is visited

    helper(mat, r+1, c, path + "D", ans, visit);   // Down
    helper(mat, r-1, c, path + "U", ans, visit);   // Up
    helper(mat, r, c-1, path + "L", ans, visit);   // Left
    helper(mat, r, c+1, path + "R", ans, visit);   // Right

    visit[r][c] = false;  // Unmark (backtrack)
    // mat[r][c] = 1 => means it is unvisited (backtrack)
}

vector<string> findPath(vector<vector<int>>& mat) {
    int n = mat.size();

    if (mat[0][0] == 0) return {};  // No possible path if start is blocked

    vector<string> ans;
    string path = "";

    vector<vector<bool>> visit(n, vector<bool>(n, false));

    helper(mat, 0, 0, path, ans, visit);

    return ans;
}

int main() {
    vector<vector<int>> mat = {{1, 0, 0, 0}, 
                               {1, 1, 0, 1}, 
                               {1, 1, 0, 0}, 
                               {0, 1, 1, 1}};

    vector<string> ans = findPath(mat);
    
    if (ans.empty()) {
        cout << "No path found!" << endl;
    } else {
        for (string path : ans) {
            cout << path << endl;
        }
    }

    return 0;
}
