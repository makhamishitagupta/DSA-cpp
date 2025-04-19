#include <iostream>
#include <vector>
using namespace std;

vector<int> array(vector<int> a)
{
    // brute froce approach O(n*n);
    int n = a.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            product *= a[j];
        }
        ans.push_back(product);
    }
    return ans;
}

vector<int> arrayOptimal(vector<int> a)
{
    int n = a.size();
    vector<int> ans(n, 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    // prefix
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * a[i - 1];
    }
    // suffix
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * a[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = prefix[i] * suffix[i];
    }
    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    cout << "brute froce approach" << endl;
    for (int i : array(a))
    {
        cout << i << " ";
    }
    cout << endl
         << "optimal method" << endl;
    for (int i : arrayOptimal(a))
    {
        cout << i << " ";
    }

    return 0;
}