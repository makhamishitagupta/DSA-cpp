#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &arr, int n, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (n == 0)
        return false;

    if (dp[n][target] != -1)
        return dp[n][target];

    if (arr[n - 1] <= target)
        return dp[n][target] = solve(arr, n - 1, target - arr[n - 1], dp) || solve(arr, n - 1, target, dp);
    else
        return dp[n][target] = solve(arr, n - 1, target, dp);
}

// tabulation approach
bool solveTabulation(vector<int> &arr, int n, int target)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][target];
}

// subset sum problem using dp -> return true or false if there is a subset with sum equal to target
int mian()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int target = 9;

    vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, -1));
    if (solve(arr, 5, target, dp))
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";

    return 0;
}