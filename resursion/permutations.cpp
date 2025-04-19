#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//TC => O(n!*n)
//SC => O(n!) => for storing ans

void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    if(idx == nums.size()) {
        ans.push_back(nums);
        return;
    }


    for(int i=idx; i<nums.size(); i++) {
        swap(nums[idx], nums[i]); //idx place => ith element choice
        getPerms(nums, idx+1, ans);

        swap(nums[idx], nums[i]); //backtracking
    }
}

vector<vector<int>> permutations(vector<int>& nums) {
    vector<vector<int>> ans;
    getPerms(nums, 0, ans);

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permutations(nums);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0; 
}


// Start: nums = [1, 2, 3]

// 1st Level (idx=0)
//  ├── Swap(0,0) → [1,2,3] → getPerms(idx=1)
//  │   ├── Swap(1,1) → [1,2,3] → getPerms(idx=2)
//  │   │   ├── Swap(2,2) → [1,2,3] → Permutation Found: [1,2,3]
//  │   │   ├── Backtrack Swap(2,2) → [1,2,3]
//  │   │
//  │   ├── Swap(1,2) → [1,3,2] → getPerms(idx=2)
//  │   │   ├── Swap(2,2) → [1,3,2] → Permutation Found: [1,3,2]
//  │   │   ├── Backtrack Swap(2,2) → [1,3,2]
//  │   │
//  │   ├── Backtrack Swap(1,2) → [1,2,3]
//  │
//  ├── Swap(0,1) → [2,1,3] → getPerms(idx=1)
//  │   ├── Swap(1,1) → [2,1,3] → getPerms(idx=2)
//  │   │   ├── Swap(2,2) → [2,1,3] → Permutation Found: [2,1,3]
//  │   │   ├── Backtrack Swap(2,2) → [2,1,3]
//  │   │
//  │   ├── Swap(1,2) → [2,3,1] → getPerms(idx=2)
//  │   │   ├── Swap(2,2) → [2,3,1] → Permutation Found: [2,3,1]
//  │   │   ├── Backtrack Swap(2,2) → [2,3,1]
//  │   │
//  │   ├── Backtrack Swap(1,2) → [2,1,3]
//  │
//  ├── Swap(0,2) → [3,2,1] → getPerms(idx=1)
//  │   ├── Swap(1,1) → [3,2,1] → getPerms(idx=2)
//  │   │   ├── Swap(2,2) → [3,2,1] → Permutation Found: [3,2,1]
//  │   │   ├── Backtrack Swap(2,2) → [3,2,1]
//  │   │
//  │   ├── Swap(1,2) → [3,1,2] → getPerms(idx=2)
//  │   │   ├── Swap(2,2) → [3,1,2] → Permutation Found: [3,1,2]
//  │   │   ├── Backtrack Swap(2,2) → [3,1,2]
//  │   │
//  │   ├── Backtrack Swap(1,2) → [3,2,1]
//  │
//  ├── Backtrack Swap(0,2) → [1,2,3]
