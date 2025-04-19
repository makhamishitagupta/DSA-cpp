#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &vec, int n){
    int i = 0;
    int j = n-1;
    while(i <= j){
        swap(vec[i], vec[j]);
        i++;
        j--;
    }
}

void nextPermutation(vector<int> &vec, int n) {
    // O(n)
    int pivot = -1;
    for(int i = n-2; i>=0; i--) {
        if(vec[i] < vec[i+1]){
            pivot = i;
            break;
        }
    }

    if (pivot == -1) {
        reverseArray(vec, n);
        return;
    }

    for(int i = n-1; i>pivot; i--){
        if(vec[i] > vec[pivot]) {
            swap(vec[i], vec[pivot]);
            break;
        }
    }

    int i = pivot + 1;
    int j = n-1;
    while(i <= j){
        swap(vec[i], vec[j]);
        i++;
        j--;
    }
}

int main() {
    vector<int> vec = {1, 2, 3};
    int n=3;
    nextPermutation(vec, n);
    for(int i=0; i<n; i++){
        cout << vec[i] << " ";
    }


    return 0;
}