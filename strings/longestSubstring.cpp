// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<iostream>
#include<string>
#include<set>
using namespace std;

int lengthOfLongestSubstring(string str) {
    int left = 0;
    set<char> s;
    int ans=0;

    for(int ryt=0; ryt<str.size(); ryt++) {
        while(s.find(str[ryt]) != s.end()) {
            s.erase(str[left]);
            left++;
        }

        s.insert(str[ryt]);

        ans = max(ans, ryt-left+1);
    }

    return ans;
}

int main() {
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}