#include <iostream>
#include <vector>
using namespace std;

// ----------------------
// Memoization (Top-Down)
// ----------------------
int fibMemo(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);

    return dp[n];
}

// ----------------------
// Tabulation (Bottom-Up)
// ----------------------
int fibTab(int n)
{
    if (n <= 1)
        return n;

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// ----------------------
// Space Optimization
// ----------------------
int fibSpace(int n)
{
    if (n <= 1)
        return n;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// ----------------------
// Main Function
// ----------------------
int main()
{
    int n;
    cin >> n;

    // Memoization
    vector<int> dp(n + 1, -1);
    cout << "Memoization: " << fibMemo(n, dp) << endl;

    // Tabulation
    cout << "Tabulation: " << fibTab(n) << endl;

    // Space Optimization
    cout << "Space Optimized: " << fibSpace(n) << endl;

    return 0;
}


