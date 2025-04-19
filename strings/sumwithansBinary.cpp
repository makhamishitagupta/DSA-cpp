#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    // Iterate through both strings from the least significant bit
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0'; // Add bit from a if available
        if (j >= 0) sum += b[j--] - '0'; // Add bit from b if available

        // Append the binary digit to result
        result += (sum % 2) + '0';
        carry = sum / 2; // Update carry
    }

    // Reverse the result since it was built backwards
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a, b;
    cout << "Enter binary string a: ";
    cin >> a;
    cout << "Enter binary string b: ";
    cin >> b;

    string sum = addBinary(a, b);
    cout << "Sum of binary strings: " << sum << endl;

    return 0;
}
