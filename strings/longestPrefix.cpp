#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> str = {"flower", "flow", "flight"};
    string prefix = str[0];
    int prefixLen = prefix.size();

    for (int i = 1; i < str.size(); i++)
    {
        while (prefixLen > str[i].length() || prefix != str[i].substr(0, prefixLen))
        {
            prefixLen--;

            if (prefixLen == 0)
            {
                cout << "No Prefix";
                break;
            }

            prefix = prefix.substr(0, prefixLen);
        }
    }

    cout << prefix << endl;

    return 0;
}