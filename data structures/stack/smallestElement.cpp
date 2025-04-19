#include <stack>
#include <iostream>
#include <vector>

using namespace std;
// identify smaller and is on left
int main()
{
    vector<int> arr = {3, 1, 0, 8, 6};
    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for (int i = 0; i <= arr.size() - 1; i++)
    {
        while (s.size() > 0 && s.top() >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}