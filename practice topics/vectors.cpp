#include <iostream>
#include <vector>
using namespace std;

int unique(vector<int> &nums)
{
    int ans = 0;
    for (int i : nums)
    {
        ans = ans ^ i;
    }

    return ans;
}

int main()
{
    vector<int> vec = {1, 2, 4, 2, 4};
    vec.push_back(10);

    for (int i : vec) // for each loop
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    cout << "begin: " << *(vec.begin()) << endl;
    cout << "end: " << *(vec.end()) << endl;
    // iterators
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    // vector<int>::reverse_iterator it;
    for (auto it = vec.rbegin(); it != vec.rend(); it++)
    {
        cout << *(it) << " ";
    }
    cout << endl;

    // cout << unique(vec) << endl;

    return 0;
}