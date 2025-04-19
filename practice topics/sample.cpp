#include<iostream>
using namespace std;

int main(){
    int n;
    int found=0;
    cout<<"enter the number";
    cin>>n;
    for(int i=1; i<=n; i++){
        if(n%i==0){
            found++;
        }
    }

    if(found==2){
        cout<<"prime number";
    }else{
        cout<<"not a prime number";
    }
    
    
    return 0;
}