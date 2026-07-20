#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
#include <map>
using namespace std;

int main() {
    int a;

    cin >> a;

    if(a%2==0) {
        cout << "even";
    } else {
        cout << "odd";
    }

    return 0;
}