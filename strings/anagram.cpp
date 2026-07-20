#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    string s = "anagram";
    string t = "nagaram";

    // method 1
    unordered_map<char, int> charCount;

    for (char ch : s)
    {
        charCount[ch]++;
    }

    for (char ch : t)
    {
        if (charCount.find(ch) == charCount.end() || charCount[ch] == 0)
        {
            cout << "The strings are not anagrams." << endl;
            return 0;
        }
        charCount[ch]--;
    }

    cout << "The strings are anagrams." << endl;

    // methid 2 using ascii values
    vector<int> counter(26, 0);
    for (char ch : s)
    {
        counter[ch - 'a']++;
    }

    for (char ch : t)
    {
        if (counter[ch - 'a'] == 0)
        {
            cout << "The strings are not anagrams." << endl;
            return 0;
        }

        counter[ch - 'a']--;
    }

    cout << "The strings are anagrams." << endl;

    // method 3
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t)
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    // method 4
    if (s.length() != t.length())
    {
        cout << "The strings are not anagrams." << endl;
        return 0;
    }

    unordered_map<char, int> sCount, tCount;
    for (int i = 0; i < s.length(); i++)
    {
        sCount[s[i]]++;
        tCount[t[i]]++;
    }
    if (sCount == tCount)
    {
        cout << "The strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}