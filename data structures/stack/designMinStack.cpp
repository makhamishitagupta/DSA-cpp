#include <stack>
#include <iostream>
#include <vector>

using namespace std;

// MinStack using O(2n) space
class MinStack {
public:
    stack<pair<int, int>> s; // (value, minimum value)
    
    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            s.push({val, min(val, s.top().second)});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

// Optimized minStack using O(n) space
class minStack {
public:
    stack<long long int> s;
    long long int minVal;

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        } else {
            if (val < minVal) {
                s.push(2LL * val - minVal);
                minVal = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.top() < minVal) {
            minVal = 2 * minVal - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.top() < minVal) {
            return minVal;
        }
        return s.top();
    }

    int getMin() { // Renamed from minVal() to getMin()
        return minVal;
    }
};

int main() {
    MinStack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "MinStack Min Value: " << s.getMin() << endl;

    minStack s1;
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout << "minStack Min Value: " << s1.getMin() << endl;

    return 0;
}
