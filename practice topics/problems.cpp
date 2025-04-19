#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

void swapMaxMin(int arr[], int n)
{
    int small = arr[0];
    int large = arr[0];
    int l = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        if (small > arr[i])
        {
            small = arr[i];
            s = i;
        }
        if (large < arr[i])
        {
            large = arr[i];
            l = i;
        }
    }

    swap(arr[l], arr[s]);
}

void unique(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j] && i != j)
            {
                flag = -1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    cout << "sum = " << sum(arr, n) << endl;
    cout << "elments after swaping: " << endl;
    swapMaxMin(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "unique elements are: " << endl;
    unique(arr, n);
    return 0;
}