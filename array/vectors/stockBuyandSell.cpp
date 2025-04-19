#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // return max profits
    int prices[] = {7, 1, 5, 3, 6, 4};
    int bestSell = prices[0], bestBuy = prices[0], maxProfit = 0;
    for (int i = 1; i < 6; i++)
    {
        if (prices[i] > bestBuy)
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        bestBuy = min(bestBuy, prices[i]);
    }

    cout << "Maximum profit is " << maxProfit << endl;

    return 0;
}