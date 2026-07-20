#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class Stack_LL {
    list<int> ll;
public:

    void push(int val) {
        ll.push_front(val);
    }

    void pop() {
        ll.pop_front();
    }

    int top() {
        return ll.front();
    }

    bool empty() {
        return ll.size() == 0;
    }

};

class Stack_vector {
    vector<int> v;
public:

    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        v.pop_back();
    }

    int top() {
        return v[v.size() - 1];
    }

    bool empty() {
        return v.size() == 0;
    }

};

int main() {
    Stack_vector s;

    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    Stack_LL sl;

    sl.push(10);
    sl.push(20);
    sl.push(30);

    while(!sl.empty()) {
        cout << sl.top() << " ";
        sl.pop();
    }

    stack<int> ss;

    ss.push(10);
    ss.push(20);
    ss.push(30);

    while(!ss.empty()) {
        cout << ss.top() << " ";
        ss.pop();
    }

    return 0;
}