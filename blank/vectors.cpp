#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30};

    cout << "🔹 BASICS\n";
    v.size();     // Time: O(1)
    v.capacity(); // Time: O(1)
    v.front();    // Time: O(1)
    v.back();     // Time: O(1)
    v.at(1);      // Time: O(1)
    v.empty();    // Time: O(1)

    cout << "🔹 INSERT / REMOVE\n";
    v.push_back(40);         // Amortized O(1)
    v.pop_back();            // O(1)
    v.insert(v.begin(), 15); // O(n)
    v.erase(v.begin());      // O(n)

    cout << "🔹 RESIZE / ASSIGN / RESERVE\n";
    v.resize(5, 99);  // Time: O(n) if expanding
    v.assign(4, 100); // Time: O(n)
    v.reserve(10);    // Time: O(n) if reallocation occurs

    cout << "🔹 SWAP / SHRINK / CLEAR\n";
    v.swap(v);         // Time: O(1)
    v.shrink_to_fit(); // Time: O(n)
    v.clear();         // Time: O(n) (destructors called)

    cout << "🔹 ADVANCED\n";

    vector<pair<int, string>> vp;
    vp.emplace_back(1, "one");         // O(1)
    vp.push_back(make_pair(2, "two")); // O(1)

    vector<string> names = {"Alice", "Charlie"};
    names.emplace(names.begin() + 1, "Bob"); // O(n)

    int *ptr = v.data(); // Time: O(1)

    for (auto it = v.rbegin(); it != v.rend(); ++it)
        *it; // Reverse iteration: O(n)

    vector<bool> vb = {true, false, true}; // Bit-packed specialization, access may be slower than O(1) in some STL implementations

    return 0;
}
