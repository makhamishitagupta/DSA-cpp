#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // time complexity O(log n)
    vector<int> vec = {0, 3, 8, 9, 5, 2};
    int n = vec.size();
    int start = 1, end = n - 2; // can also s=0, e=n-1 -> changed because 0,n-1 is cannot be peak
    while (start <= end)
    {
        int mid = (start + end) / 2; // mid = start+(end-start)/2
        if (vec[mid - 1] < vec[mid] && vec[mid] > vec[mid + 1])
        {
            cout << mid << endl;
            break;
        }
        else if (vec[mid - 1] < vec[mid])
            start = mid + 1;
        else // if (vec[mid] > vec[mid + 1])
            end = mid - 1;
    }

    return 0;
}