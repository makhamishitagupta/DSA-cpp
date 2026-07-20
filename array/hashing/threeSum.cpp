#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

// question given an integer nums, return all unique the triplets such tht sum of 3 numbers is 0

vector<vector<int>> bruteForceMethod(vector<int>& num) {
    // TC => O(n^3 * log(unique triplets))    SC => O(2*uniqueTriplets)
    int n = num.size();
    vector<vector<int>> ans;
    set<vector<int>> s;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(num[i] + num[j] + num[k] == 0) {
                    vector<int> trip = {num[i], num[j], num[k]};
                    sort(trip.begin(), trip.end());

                    if(s.find(trip) == s.end()) {
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }

    return ans;
}

vector<vector<int>> hashing(vector<int>& num) {
    // logic: a + b + c = 0 => a + b = -c = target
    // O(n^2)

    set<vector<int>> uniqueSet;
    int n = num.size();

    for(int i=0; i<n; i++) {
        set<int> s;
        int target = -num[i];
        for(int j = i+1; j<n; j++) {
            int toFind = target - num[j];  
            if(s.find(toFind) != s.end()) {  
                vector<int> triplet = {num[i], num[j], toFind};
                sort(triplet.begin(), triplet.end());
                uniqueSet.insert(triplet);
            }

            s.insert(num[j]);
        }
    }

    vector<vector<int>> ans(uniqueSet.begin(), uniqueSet.end());

    return ans;
}

vector<vector<int>> twoPointer(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i=0; i<nums.size(); i++) {
        int j = i + 1, k = nums.size() - 1;

        if(i>0 && nums[i] == nums[i-1]) continue;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum > 0) k--;
            else if(sum < 0) j++;
            else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                while(j<k && nums[j] == nums[j-1]) j++;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result0 = bruteForceMethod(arr);
    for(int i=0; i<result0.size(); i++) {
        for(int j=0; j<result0[0].size(); j++) {
            cout << result0[i][j] << " ";
        }
        cout << endl;
    }

    cout << "----------------------" << endl;

    vector<vector<int>> result1 = hashing(arr);
    for(int i=0; i<result1.size(); i++) {
        for(int j=0; j<result1[0].size(); j++) {
            cout << result1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "----------------------" << endl;

    vector<vector<int>> result2 = twoPointer(arr);
    for(int i=0; i<result2.size(); i++) {
        for(int j=0; j<result2[0].size(); j++) {
            cout << result2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}