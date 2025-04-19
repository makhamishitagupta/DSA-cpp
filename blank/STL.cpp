#include <iostream>
#include <list>
#include <deque>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
int main()
{
    // list
    list<int> l = {1, 2, 3};
    l.push_back(10);
    l.push_front(10);
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "-----------------------------" << endl;

    // deque
    deque<int> d = {1, 2, 3};
    d.push_back(10);
    d.push_front(10);
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "-----------------------------" << endl;

    // pair
    pair<int, int> p = {3, 5};
    cout << p.first << " " << p.second << endl;
    cout << "-----------------------------" << endl;

    // pairs in vector
    vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};
    for (auto i : vec) // for (pair<int, int> i : vec)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << "-----------------------------" << endl;

    // stack
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "top = " << s.top() << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << "-----------------------------" << endl;

    // queue
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << "-----------------------------" << endl;

    // map
    map<string, int> m;
    m["tv"] = 100;
    m["laptop"] = 100;
    m["phone"] = 50;

    m.insert({"camera", 25});
    m.emplace("dresses", 120);
    for (auto i : m) // will be arranged in key ascending order
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    cout << "-----------------------------" << endl;

    // set
    set<int> set_;
    set_.insert(3);
    set_.insert(2);
    set_.insert(4);
    set_.insert(1);
    set_.insert(6);
    set_.insert(6);
    set_.insert(6);

    cout << set_.size() << endl;
    for (auto val : set_)
    { // we will get unique elements in sorted order i.e asecending order
        cout << val << " ";
    }
    cout << endl;
    cout << "-----------------------------" << endl;

    return 0;
}