#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> summaryRangeMINE(vector<int> &nums) {
    vector<string> ans;
    if(nums.empty()) return ans;

    int i=0, j=0;
    while(j < nums.size()){
        if(j == nums.size() - 1 || nums[j+1] != nums[j] + 1){
            if(i != j) {
                string temp = to_string(nums[0]) + "->" + to_string(nums[j]);
                ans.push_back(temp);
            } else {
                string temp = to_string(nums[j]);
                ans.push_back(temp);
            }
            i = j+1;
        }
        j++;
    }

    return ans;
}

vector<string> summaryRangeCGPT(vector<int> &nums) {
    vector<string> ans;
    if (nums.empty()) return ans;

    int i = 0;
    while (i < nums.size()) {
        int start = nums[i];
        // Move `j` to the end of the current range
        while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
            i++;
        }
        int end = nums[i];
        if (start == end) {
            ans.push_back(to_string(start));
        } else {
            ans.push_back(to_string(start) + "->" + to_string(end));
        }
        i++;
    }

    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 6, 7, 9, 11, 12, 13};
    vector<string> result = summaryRangeMINE(nums);

    for(string range: result){
        cout << range << " ";
    }


    return 0;
}