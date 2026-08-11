// A ninja has planned a n-day training schedule. Each day he has to perform one of three activities - running, stealth training, or fighting practice. The same activity cannot be done on two consecutive days and the ninja earns a specific number of merit points, based on the activity and the given day.Given a n x 3-sized matrix, where matrix[i][0], matrix[i][1], and matrix[i][2], represent the merit points associated with running, stealth and fighting practice, on the (i+1)th day respectively. Return the maximum possible merit points that the ninja can earn.
// Example 1
// Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
// Output: 210
// Explanation:
// Day 1: fighting practice = 70
// Day 2: stealth training = 50
// Day 3: fighting practice = 90
// Total = 70 + 50 + 90 = 210
// This gives the optimal points.

#include <bits/stdc++.h>
using namespace std;

// memorization approach
int solve(vector<vector<int>> &matrix, int day, int last, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxPoints = 0;
        for (int activity = 0; activity < 3; activity++)
        {
            if (activity != last)
            {
                maxPoints = max(maxPoints, matrix[day][activity]);
            }
        }

        return maxPoints;
    }

    int maxPoints = 0;
    for (int activity = 0; activity < 3; activity++)
    {
        if (dp[day][activity] != -1)
        {
            return dp[day][activity];
        }

        if (activity != last)
        {
            int points = matrix[day][activity] + solve(matrix, day - 1, activity, dp);
            maxPoints = max(maxPoints, points);
        }
    }

    dp[day][last] = maxPoints;
    return maxPoints;
}

// tabulation approach
int solveT(vector<vector<int>> &matrix, int n)
{
    vector<vector<int>> dp(matrix.size(), vector<int>(4, 0)); // Initialize dp with 0

    for (int activity = 0; activity < 3; activity++)
    {
        dp[0][activity] = matrix[0][activity];
    }

    for (int i = 0; i < n; i++)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int activity = 0; activity < 3; activity++)
            {
                if (activity != last)
                {
                    dp[i][activity] = max(dp[i][activity], matrix[i][activity] + (i > 0 ? dp[i - 1][last] : 0));
                }
            }
        }
    }

    int maxPoints = 0;
    for (int activity = 0; activity < 3; activity++)
    {
        maxPoints = max(maxPoints, dp[n - 1][activity]);
    }

    return maxPoints;
}

int main()
{
    vector<vector<int>> matrix = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    vector<vector<int>> dp(matrix.size(), vector<int>(4, -1)); // Initialize dp with -1

    int n = matrix.size();
    int ans = solve(matrix, n - 1, -1, dp); // Start from the last day with no last activity

    cout << ans << endl;

    cout << solveT(matrix, n) << endl;

    return 0;
}