#include<iostream>
#include<vector>
#include<unordered_map>
using namespace  std;

int main() {
    vector<int> array = {5, 2, 11, 7, 15};
    int target = 9;

    unordered_map<int, int> m;
    vector<int> ans;

    for(int i=0; i<array.size(); i++) {
        int first = array[i];
        int second = target - first;

        if(m.find(second) != m.end()) {
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }

        m[first] = i;

    }

    for(int i=0; i<2; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}