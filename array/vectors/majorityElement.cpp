#include <iostream>
using namespace std;
#include <algorithm>

int majorityElt(int array[], int n)
{
    // burte force algorithm o(n^2)
    for (int i = 0; i < n; i++)
    {
        int freq = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[i] == array[j])
            {
                freq++;
            }
        }
        if (freq > (n / 2))
        {
            return array[i];
        }
    }
    return 0;
}

int majorityEltOptimal(int array[], int n)
{
    sort(array, array + n);
    // for (int i = 0; i < n; i++)
    // {
    //     int freq = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (array[i] != array[j])
    //             break;
    //         freq++;
    //     }
    //     if (freq > (n / 2))
    //         return array[i];
    // }
    int freq = 1, ans = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] == array[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = array[i];
        }
        if (freq > (n / 2))
            return ans;
    }
}

int majorityEltMoores(int array[], int n)
{
    // moore's voting algorithm
    int freq = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = array[i];
        }
        if (ans == array[i])
            freq++;
        else
            freq--;
    }
    return ans;
}

int main()
{
    int array[] = {1, 2, 2, 1, 1};
    int n = 5;
    cout << "MAJORITY ELEMENT: " << majorityElt(array, n) << endl;
    cout << "MAJORITY ELEMENT: " << majorityEltOptimal(array, n) << endl;
    cout << "MAJORITY ELEMENT: " << majorityEltMoores(array, n) << endl;

    return 0;
}