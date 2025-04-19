#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    // Sort the array to group identical elements together
    sort(nums.begin(), nums.end());
    // Iterate through the array in steps of 2
    for(int i = 1; i < nums.size(); i += 2) {
        // If a mismatch is found, return the single number
        if(nums[i] != nums[i-1])
            return nums[i-1];
    }
    // If no mismatch is found, return the last element
    return nums[nums.size() - 1];
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = singleNumber(nums);
    cout << "The single number is: " << result << endl;

    return 0;
}
