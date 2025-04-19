#include <iostream>
using namespace std;

// 2 pointer approch
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = 5;
    int end = 4;
    int start = 0;
    // for (int i = 0; i < n / 2; i++)
    // {
    //     swap(a[i], a[end]);
    //     end--;
    // }

    // 2point approch
    while (start < end)
    {
        swap(a[start], a[end]);
        start++;
        end--;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}