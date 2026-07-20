#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    vector<int> v = {5, 3, 9, 1, 3, 7};

    cout << "🔹 SORTING & REVERSING\n";
    sort(v.begin(), v.end());    // Time: O(n log n), Space: O(1)
    reverse(v.begin(), v.end()); // Time: O(n), Space: O(1)

    cout << "🔹 MAX / MIN\n";
    *max_element(v.begin(), v.end()); // Time: O(n), Space: O(1)
    *min_element(v.begin(), v.end()); // Time: O(n), Space: O(1)

    cout << "🔹 COUNTING & SEARCHING\n";
    count(v.begin(), v.end(), 3);         // Time: O(n), Space: O(1)
    find(v.begin(), v.end(), 7);          // Time: O(n), Space: O(1)
    binary_search(v.begin(), v.end(), 9); // Time: O(log n), Space: O(1) [requires sorted]

    cout << "🔹 CONDITIONS (all_of, any_of, none_of)\n";
    all_of(v.begin(), v.end(), [](int x)
           { return x > 0; }); // O(n)
    any_of(v.begin(), v.end(), [](int x)
           { return x % 2 == 0; }); // O(n)
    none_of(v.begin(), v.end(), [](int x)
            { return x < 0; }); // O(n)

    cout << "🔹 LOWER / UPPER BOUND\n";
    lower_bound(v.begin(), v.end(), 4); // Time: O(log n), Space: O(1)
    upper_bound(v.begin(), v.end(), 4); // Time: O(log n), Space: O(1)

    cout << "🔹 ACCUMULATE / TRANSFORM\n";
    accumulate(v.begin(), v.end(), 0); // Time: O(n), Space: O(1)
    transform(v.begin(), v.end(), v.begin(), [](int x)
              { return x * 2; }); // Time: O(n)

    cout << "🔹 FILL / IOTA\n";
    fill(v.begin(), v.end(), 7); // Time: O(n), Space: O(1)
    iota(v.begin(), v.end(), 1); // Time: O(n), Space: O(1)

    cout << "🔹 ROTATE / COPY_IF / PARTITION\n";
    rotate(v.begin(), v.begin() + 1, v.end()); // Time: O(n), Space: O(1)
    copy_if(v.begin(), v.end(), back_inserter(v), [](int x)
            { return x % 2 == 0; }); // Time: O(n), Space: O(k)
    partition(v.begin(), v.end(), [](int x)
              { return x % 2 == 0; }); // Time: O(n), Space: O(1)

    cout << "🔹 UNIQUE / REMOVE / PERMUTATION\n";
    unique(v.begin(), v.end());           // Time: O(n), Space: O(1)
    remove(v.begin(), v.end(), 2);        // Time: O(n), Space: O(1)
    next_permutation(v.begin(), v.end()); // Time: O(n), Space: O(1)
    prev_permutation(v.begin(), v.end()); // Time: O(n), Space: O(1)

    return 0;
}
