#include <stack>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> num1 = {4, 1, 2};
    vector<int> num2 = {1, 3, 4, 2};
    // num1 is subset of num2
    unordered_map<int, int> m; // num2[i], nextGreaterElt
    stack<int> s;

    for (int i = num2.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= num2[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            m[num2[i]] = -1;
        }
        else
        {
            m[num2[i]] = s.top();
        }

        s.push(num2[i]);
    }

    vector<int> ans;
    for (int i = 0; i < num1.size(); i++)
        ans.push_back(m[num1[i]]);

    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}