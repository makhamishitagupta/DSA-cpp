/*
🔷 Problem 2: Fractional Knapsack
Given weights and values of items and a capacity W, find the maximum value
that can be obtained by taking full or fractional items based on value/weight ratio.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Item
{
public:
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

bool cmp(Item a, Item b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

class FractionalKnapsack
{
public:
    double getMaxValue(Item arr[], int n, int W)
    {
        sort(arr, arr + n, cmp);
        double totalValue = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (W >= arr[i].weight)
            {
                W -= arr[i].weight;
                totalValue += arr[i].value;
            }
            else
            {
                totalValue += arr[i].value * ((double)W / arr[i].weight);
                break;
            }
        }
        return totalValue;
    }
};

int main()
{
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    FractionalKnapsack obj;
    cout << "Maximum value: " << obj.getMaxValue(items, 3, W) << "\n";
    return 0;
}
