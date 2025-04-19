#include <iostream>
using namespace std;

// A subsequence is a sequence that appears in the same relative order as the original string, 
//but not necessarily consecutively. You can delete some characters (or none), but you cannot change 
//the order of the remaining characters.

bool isSubsequence(string s, string t) {
    int i = 0, j = 0;

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++; // match found, move to next character in s
        }
        j++; // always move in t
    }

    return i == s.length(); // all characters in s were matched
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    if (isSubsequence(s, t)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
