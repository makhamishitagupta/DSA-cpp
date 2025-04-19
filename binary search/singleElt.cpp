#include <iostream>
using namespace std;

int main()
{
    int array[] = {3, 3, 7, 7, 10, 11, 11};
    int n = sizeof(array) / sizeof(int);
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + ((end - start) / 2);
        if (mid == 0 && array[0] != array[1])
        {
            cout << "Single elt is at index " << mid << " of value " << array[mid];
            break;
        }
        if (mid == 0 && array[n - 1] != array[n - 2])
        {
            cout << "Single elt is at index " << mid << " of value " << array[mid];
            break;
        }
        if (array[mid - 1] != array[mid] && array[mid] != array[mid + 1])
        {
            cout << "Single elt is at index " << mid << " of value " << array[mid];
            break;
        }

        if (mid % 2 == 0)
        {
            if (array[mid - 1] == array[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        else
        {
            if (array[mid - 1] == array[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return 0;
}