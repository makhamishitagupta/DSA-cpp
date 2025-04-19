#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target)
{
    // brute-approach
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}

vector<int> pairSumOptimal(vector<int> nums, int target)
{
    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum > target)
            j--;
        if (pairSum < target)
            i++;
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 5;
    vector<int> result = pairSumOptimal(nums, target);

    // Print the result
    // if (result.empty())
    // {
    //     cout << "No pairs found!" << endl;
    // }
    // else
    // {
    //     for (int i = 0; i < result.size(); i += 2)
    //     {
    //         cout << "Pair: (" << result[i] << ", " << result[i + 1] << ") answer the index of array\n";
    //     }
    // }

    cout << "Pair: (" << result[0] << ", " << result[1] << ") answer is in the form of index of array\n";
    return 0;
}