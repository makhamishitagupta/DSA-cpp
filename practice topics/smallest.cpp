#include <iostream>
#include <limits>
using namespace std;

int main()
{
    int array[5];
    int n;
    n = sizeof(array) / sizeof(int);
    cout << "enter the elts of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int small = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] < small)
        {
            small = array[i];
        }
    }

    cout << "smallest elt in the array is " << small << endl;

    return 0;
}
