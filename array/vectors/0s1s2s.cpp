#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bruteForce(vector<int>& vec, int n) {
    sort(vec.begin(), vec.end());
    //O(nlog n)
}

void optimized(vector<int>& vec, int n) {
    //O[n]
    int count0 = 0, count1 = 0, count2 = 0;
    for(int i=0; i<n; i++){
        if(vec[i] == 0) count0++;
        if(vec[i] == 1) count1++;
        if(vec[i] == 2) count2++;
    }
    int idx = 0;
    for(int i=0; i<count0; i++){
        vec[idx++] = 0;
    }
    for(int i=0; i<count1; i++){
        vec[idx++] = 1;
    }
    for(int i=0; i<count2; i++){
        vec[idx++] = 2;
    }
}

void optimal(vector<int>& vec, int n) {
    //DUTCH NATIONAL FLAG ALGORITHM 

    int mid = 0, high = n-1, low = 0;

    /* 0s -> 0 to low-1
       1s -> low to mid-1
       2s -> high+1 to n-1
       unsorted elements are in between mid to high
    */

    while(mid <= high) {
        if(vec[mid] == 0) {
            swap(vec[low], vec[mid]);
            low++;
            mid++;
        } else if(vec[mid] == 1) mid++;
        else if(vec[mid] == 2) {
            swap(vec[mid], vec[high]);
            high--;
        }
    }
}

int main(){
    vector<int> vec = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    int n = vec.size();
    optimized(vec, n);
    for(int i = 0; i<n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    optimal(vec, n);
    for(int i = 0; i<n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}