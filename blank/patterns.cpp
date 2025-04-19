#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"number of rows: ";
    cin>>n;
    //square pattern
    // for(int i=1; i<=n; i++){
    //     char ch = 'A';
    //     for(int j=1; j<=n; j++){
    //         cout<<ch;
    //         ch++;
    //     }
    //     cout<<endl;
    // }

    //trianlge pattern
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=i; j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    //reverse triangle pattern
    // for(int i=1; i<=n; i++){
    //     for(int j=i; j>0; j--){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    //}

    //floyds triangle pattern
    // int num=0;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=i; j++){
    //         cout<<num<<"\t";
    //         num++;
    //     }
    //     cout<<endl;
    // }

    //inverted triangle
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<i; j++){
    //         cout<<"  ";
    //     }
    //     for(int j=0; j<n-i; j++){
    //         cout<<i+1<<" ";
    //     }

    //     cout<<endl;
    // }

    //pyramid pattern
    //  for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i-1; j++){
    //         cout<<"  ";
    //     }
    //     for(int j=1; j<=i+1; j++){
    //         cout<<j<<" ";
    //     }
    //     for(int j=i; j>0; j--){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    //  }

    //hollow diamond pattern
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n-i-1; j++){
    //         cout<<" ";
    //     }
    //     cout<<"*";
    //     for(int j=0; j<(2*i)-1; j++){
    //         cout<<" ";
    //     }
    //     if(i!=0)
    //     cout<<"*";
    //     cout<<endl;
    // }
    // for(int i=0; i<n-1; i++){
    //     for(int j=0; j<i+1; j++){
    //         cout<<" ";
    //     }
    //     cout<<"*";
        
    //     if(i!=n-2){
    //         for(int j=0; j<2*(n-i)-5; j++){
    //             cout<<" ";
    //         }
    //         cout<<"*";
    //     }
        
    //     cout<<endl;
    // }

    //butterfly pattern
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        for(int j=0; j<2*(n-i-1); j++){
            cout<<"  ";
        }
        for(int j=0; j<i+1; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        for(int j=n; j>i; j--){
            cout<<"* ";
        }
        for(int j=0; j<i*2; j++){
            cout<<"  ";
        }
        for(int j=n; j>i; j--){
            cout<<"* ";
        }

        cout<<endl;
    }



    return 0;
}