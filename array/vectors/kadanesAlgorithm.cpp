#include <iostream>
#include <limits>
using namespace std;

void printSubarray(int array[], int n)
{
    // subarray
    for (int start = 0; start < n; start++)
    {
        for (int end = start; end < n; end++)
        {
            for (int i = start; i <= end; i++)
            {
                cout << array[i];
            }
            cout << " ";
        }

        cout << endl;
    }
}

int maxSubarraySum(int array[], int n)
{                   // using brute force approch
    int maxSum = 0; // need to keep INT_MIN
    for (int start = 0; start < n; start++)
    {
        int currentSum = 0;
        for (int end = start; end < n; end++)
        {
            currentSum += array[end];
            maxSum = max(currentSum, maxSum);
        }
    }
    return maxSum;
}

int maxSubSum(int array[], int n)
{
    // using kandanes algorithm
    int currentSum = 0, maxSum = -10;
    for (int i = 0; i < n; i++)
    {
        currentSum += array[i];
        maxSum = max(currentSum, maxSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;
    printSubarray(array, n);
    cout << "Maximum subarray sum is " << maxSubarraySum(array, n) << endl;
    cout << "Maximum subarray sum is " << maxSubSum(array, n) << endl;

    return 0;
}