// Counts Subsets with Sum K
#include <bits/stdc++.h>
using namespace std;

// memorization approach
int solve(vector<int> &arr, int n, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (n == 0)
        return 0;

    if (dp[n][k] != -1)
        return dp[n][k];

    if (arr[n - 1] <= k)
    {
        return dp[n][k] = solve(arr, n - 1, k - arr[n - 1], dp) + solve(arr, n - 1, k, dp);
    }
    else
    {
        return dp[n][k] = solve(arr, n - 1, k, dp);
    }
}

// tabulation approach
int solveTabulation(vector<int> &arr, int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int k = 3;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    cout << "Count of subsets with sum " << k << " is: " << solve(arr, n, k, dp) << endl;

    return 0;
}