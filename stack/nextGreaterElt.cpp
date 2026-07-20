#include <stack>
#include <iostream>
#include <vector>

using namespace std;

// SC => O(n)
// TC => O(n)
int main() {
    stack<int> s;
    vector<int> arr = {6, 8, 0, 10, 1, 3};
    vector<int> ans(arr.size(), 0);

    for(int i = arr.size() - 1; i>=0; i--) {
        while(s.size() > 0 && s.top() <= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for(int i : ans) {
        cout << i << " ";
    }

    return 0;
}