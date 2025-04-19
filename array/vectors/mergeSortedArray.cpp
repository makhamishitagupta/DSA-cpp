#include<iostream>
#include<vector>
using namespace std;

void mergeSortingArray(vector<int> &vec1, vector<int> &vec2, int m, int n) {
    int idx = n+m-1;
    int i = n-1, j = m-1;
    while(i>=0 && j>=0) {
        if(vec1[i] <= vec2[j]){
            vec1[idx--] = vec2[j--];
            // j--;
            // idx--;
        }else{
            vec1[idx--] = vec1[i--];
            // i--;
            // idx--;
        }
    }

    while(j >= 0) {
        vec1[idx--] = vec2[j--];
    }
}

int main(){
    vector<int> vec1 = {1, 2, 3, 0, 0, 0};
    vector<int> vec2 = {2, 5, 6};
    int n = 3, m = 3;
    mergeSortingArray(vec1, vec2, m, n);
    for(int i=0; i<n+m; i++){
        cout << vec1[i] << " ";
    }

    return 0;
}