#include <iostream>
using namespace std;

int lineraSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i + 1;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int target = 3;

    cout << lineraSearch(arr, n, target) << endl;
}
