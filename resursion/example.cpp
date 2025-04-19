#include<iostream>
#include<vector>
using namespace std;

void printNums(int n) {
    if(n==1) {
        cout << "1" << endl;
        return;
    }

    cout << n << " ";
    printNums(n-1);
}

bool isSortedArray(vector<int>& arr, int n) {
    if(n == 0 || n == 1) return true;

    return arr[n-1] >= arr[n-2] && isSortedArray(arr, n-1);
}

bool binarySearch(vector<int>& arr, int target, int st, int end) {
    int n = arr.size();

    if(st <= end) {
        int mid = st + (end - st)/2;

        if(arr[mid] == target) return true;
        else if(arr[mid] > target) return binarySearch(arr, target, st, mid - 1);
        else return binarySearch(arr, target, st + 1, mid);
    }

    return -1;
}

int fabonacci(int n) {
    if(n == 0 || n == 1) return 1;

    return fabonacci(n-1) + fabonacci(n-2);
}

int main() {


    return 0;
}