#include <iostream>
#include <vector>
using namespace std;
// using binary search
int main()
{
    vector<int> vec = {3, 4, 5, 6, 7, 0, 1, 2};
    int n = vec.size();
    int target = 0;
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] == target)
            cout << "found at " << mid;

        if (vec[start] < vec[mid])
        {
            // left sorted
            if (vec[start] <= target && target <= vec[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            // right sorted
            if (vec[mid] <= target && target <= vec[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

        return 0;
}