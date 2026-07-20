#include <bits/stdc++.h>
using namespace std;

int naive(vector<int> &height)
{
    // TC => O(n*n)
    // SC => O(1)
    int n = height.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int left_max = 0, right_max = 0;

        // Find the maximum height to the left of index i
        for (int j = 0; j <= i; j++)
        {
            left_max = max(left_max, height[j]);
        }

        // Find the maximum height to the right of index i
        for (int j = i; j < n; j++)
        {
            right_max = max(right_max, height[j]);
        }

        // Water trapped at index i
        sum += min(left_max, right_max) - height[i];
    }

    return sum;
}

int better(vector<int> &height) // prefixArray method
{
    // TC => O(n)
    // SC => O(n)
    int n = height.size();
    if (n == 0)
        return 0; // Edge case

    vector<int> left_max(n, 0), right_max(n, 0);
    int ans = 0;

    left_max[0] = height[0];
    for (int i = 1; i < n; i++)
        left_max[i] = max(left_max[i - 1], height[i]);

    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right_max[i] = max(right_max[i + 1], height[i]);

    for (int i = 0; i < n; i++)
        ans += min(left_max[i], right_max[i]) - height[i];

    return ans;
}

int optimal(vector<int> &height) // Two Pointer approach
{
    // TC => O(n)
    // SC => O(1)

    int n = height.size();
    int left_max = -1, right_max = -1;
    int l = 0, r = n - 1;
    int ans = 0;

    while (l < r)
    {
        left_max = max(left_max, height[l]);
        right_max = max(right_max, height[r]);
        if (left_max < right_max)
        {
            ans += left_max - height[l];
            l++;
        }
        else
        {
            ans += right_max - height[l];
            ans += right_max - height[r];
        }
    }

    return ans;
}

int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << "Trapped Water: " << naive(height) << endl;
    cout << "Trapped Water: " << better(height) << endl;
    cout << "Trapped Water: " << optimal(height) << endl;
    return 0;
}
