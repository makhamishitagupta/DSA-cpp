/* Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are 
located along a straight line at positions x1 ... xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become 
aggressive towards each other once put into a stall. To prevent the cows from hurting each other, 
FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as
large as possible. What is the largest minimum distance? */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it is possible to place C cows with at least 'distance' apart
bool isPossible(vector<int>& stalls, int n, int c, int distance) {
    int count = 1; // Place the first cow in the first stall
    int last_position = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_position >= distance) {
            count++; // Place the next cow
            last_position = stalls[i];
            if (count == c) return true; // All cows are placed
        }
    }

    return false; // Not possible to place all cows
}

// Function to find the largest minimum distance
int largestMiniDist(vector<int>& stalls, int n, int c) {
    // Sort stall positions
    sort(stalls.begin(), stalls.end());

    int start = 1;                        // Minimum possible distance
    int end = stalls[n - 1] - stalls[0];  // Maximum possible distance
    int ans = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(stalls, n, c, mid)) {
            ans = mid;        // Update answer
            start = mid + 1;  // Try for a larger distance
        } else {
            end = mid - 1;    // Try for a smaller distance
        }
    }

    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};
    int n = 5, c = 3;

    cout << largestMiniDist(stalls, n, c) << endl;

    return 0;
}
