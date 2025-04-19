#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int bruteForce(vector<int>& arr, int k) {
    int count = 0;
    int n = arr.size();

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(sum == k) count++;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {9, 4, 20, 3, 10, 5};
    int k = 33;
    int ans = bruteForce(arr, k);
    cout << "Number of sub array: " << ans;


    return 0;
}