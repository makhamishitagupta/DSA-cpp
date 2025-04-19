#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // No carry, return the result
            }
            digits[i] = 0; // If digit is 9, set it to 0 and continue the loop
    }

    // If all digits were 9, we need an extra digit at the front
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
     // Input number as digits in a vector
    cout << "Enter the number of digits: ";
    int n;
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    // Call the plusOne function
    vector<int> result = plusOne(digits);

    // Output the result
    cout << "Result after adding one: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}