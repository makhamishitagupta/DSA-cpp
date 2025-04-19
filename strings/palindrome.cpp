#include <iostream>
#include <string>
#include <cctype> // For isalnum and tolower
using namespace std;

int main() {
    string s = "Ac3?e3c&a";
    cout << "Original string: " << s << endl;

    int start = 0, end = s.length() - 1;
    bool isPalindrome = true;

    while (start < end) {
        // Skip non-alphanumeric characters
        while (start < end && !isalnum(s[start])) start++;
        while (start < end && !isalnum(s[end])) end--;

        // Compare characters (case-insensitive)
        if (tolower(s[start]) != tolower(s[end])) {
            isPalindrome = false;
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
