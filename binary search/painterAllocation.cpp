/* There is fence which consists of 
 wooden blocks with each block having a number written on it represented by an array 
. The painter is also given two numbers 
 and 
 . He is given the task to paint the fence using at most 
 colors. But there are certain conditions which the painter must follow while painting:

He has to paint the fence in sequential manner from left to right i.e, first paint the first block then second block and so on without leaving any block not being painted. 
He will also use colors in sequential manner i.e, first paint with 1st color,then with 2nd color and so on. Note that he can paint any number of blocks sequentially with a single color and a color once used cannot be reused.
The sum of numbers written on blocks painted with same color must lie between 
 and 
 ( both inclusive ).
    The painter wants to know in how many ways can he paint the fence.Since the answer can be large, find the answer 
*/

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int maxAllowedtime){
    int painters = 1, time = 0;
    for(int i=0; i<n; i++){
        if(arr[i] + time <= maxAllowedtime){
            time += arr[i];
        }else{
            painters++;
            time = arr[i];
        }
    }
    return painters <= m? true: false;
}

int main(){
    vector<int> arr = {40, 30, 10, 20};
    int n = arr.size();
    int m = 2;
    
    int sum = 0, maxVal = -1;
    for(int i=0; i<n; i++){
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int start = maxVal, end = sum, ans = -1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if(isPossible(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }

    cout << "Minimum time required is equal to " << ans <<endl;

    return 0;
}