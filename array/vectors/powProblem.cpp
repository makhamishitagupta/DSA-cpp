#include <iostream>
using namespace std;
// not understood
int main()
{
    // BINARY EXPONENTIATION
    // N(DECIMAL)-> HAVE (Log n(nase 2))+1 digits in BINARY FORM
    double x;
    int n;
    cout << "enter the numbers: " << " ";
    cin >> x >> n;
    if (n == 0)
        return 1.0;
    if (x == 0)
        return 0.0;
    if (x == 1)
        return 1.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;

    double originalNum = x;
    long binaryForm = n;
    if (n < 0)
    {
        x = 1 / x;
        binaryForm = -binaryForm;
    }
    double ans = 1;
    while (binaryForm > 0)
    {
        if (binaryForm % 2 == 1)
        {
            ans *= x;
        }
        x *= x;
        binaryForm /= 2;
    }

    cout << originalNum << "^" << n << " is equal to " << ans << endl;

    return 0;
}