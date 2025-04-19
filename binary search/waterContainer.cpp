#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> height)
{
    // brute force approach
    int n = height.size();
    int max_area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            /*
                int width = j-i;
                int height = min(height[i], height[j]);
                int currentWater = w*h;
                max_area = max(maxWater, currentWater);
            */
            max_area = max(max_area, min(height[i], height[j]) * (j - i));
        }
    }
    return max_area;
}

int maxAreaOptimal(vector<int> heights)
{
    // optimal method with 2 pointer approch
    int n = heights.size();
    int left = 0, right = n - 1, maxWater = 0;
    while (left < right)
    {
        int width = right - left;
        int height = min(heights[left], heights[right]);
        int currentWater = width * height;
        maxWater = max(maxWater, currentWater);
        heights[left] < heights[right] ? left++ : right--;
    }
    return maxWater;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = height.size();
    int max_area = maxArea(height);
    cout << "MAXIMUM AREA IS(brute force approach)" << max_area << endl;
    cout << "MAXIMUM AREA IS (optimal method with 2 pointer approch)" << maxAreaOptimal(height) << endl;
    return 0;
}