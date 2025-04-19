#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

int optimizedUnodered_set(vector<int>& arr) {
    //TC => O(n) SC => O(n)
    unordered_set<int> ans;
    for(int val : arr) {
        if(ans.find(val) != ans.end()) {
            return val;
        }

        ans.insert(val);
    }
    return -1;
}

int optimizedByLL(vector<int>& arr) {
    // assuming the array as linked list and at the place of cycle the duplicate exists
    // element => nextNode   idx => node
    //using slow-fast pointer

    int slow = arr[0], fast = arr[0]; // pointing to 1st element

    do {
        slow = arr[slow]; //+1
        fast = arr[arr[fast]]; //+2
    } while(fast != slow); 

    slow = arr[0];

    while (slow != fast) {
        slow = arr[slow]; //+1
        fast = arr[fast]; //+1
    }

    return slow;
    
}

int main() {
    vector<int> array = {3, 1, 4, 2, 3};
    cout << optimizedUnodered_set(array) << endl;
    cout << optimizedByLL(array) << endl;

    return 0;
}