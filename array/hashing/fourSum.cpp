#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
    vector<int> arr = {-2, -1, -1, 1, 1, 2, 2};
    int target = 0;
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;
    for(int i=0; i<arr.size() - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue; // Skip duplicate `i`
        for(int j=i+1; j<arr.size(); j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue; // Skip duplicate `j`
            int k = j+2, l = arr.size()-1;

            while(k < l) {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];

                if(sum > target) l--;
                else if(sum < target) k++;
                else {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    while(k<l && arr[k] == arr[k-1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                }
            }
        }
    }

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}