#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> sum(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<vector<int>> ans;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (dp[i][j] > 0)
            {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 5};
    vector<vector<int>> result = sum(arr);
    for (const auto &pair : result)
    {
        cout << "i: " << pair[0] << ", j: " << pair[1] << endl;
    }
    cout << "Total combinations: " << result.size() << endl;

    return 0;
}