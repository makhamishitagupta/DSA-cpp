#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2; // Two stacks to implement the queue

    void push(int x) {
        // Push element x to the back of queue
        s1.push(x);
    }

    int pop() {
        // Removes the element from the front of queue and returns it
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1; // Queue is empty
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        // Get the front element
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1; // Queue is empty
        return s2.top();
    }

    bool empty() {
        // Returns whether the queue is empty
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    cout << "Front element: " << queue.peek() << endl; // Should print 1
    cout << "Popped element: " << queue.pop() << endl; // Should print 1
    cout << "Front element after pop: " << queue.peek() << endl; // Should print 2
    cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Should print No
    queue.pop(); // Pop 2
    queue.pop(); // Pop 3
    cout << "Is queue empty after popping all elements? " << (queue.empty() ? "Yes" : "No") << endl; // Should print Yes
    queue.pop(); // Attempt to pop from empty queue, should handle gracefully
    cout << "Popped element from empty queue: " << queue.pop() << endl; // Should print -1 or some error message
    cout << "Front element from empty queue: " << queue.peek() << endl; // Should print -1 or some error message

    return 0;
}