#include <iostream>
#include <queue>
#include <utility> 
using namespace std;

class MyStack {
public:
   
    queue<int> q1, q2; 

    void push(int x) {
        // Push element x onto stack
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        // Removes the element on the top of the stack and returns it
        if (q2.empty()) return -1; // Stack is empty
        int top = q2.front();
        q2.pop();
        return top;
    }

    int top() {
        // Get the top element
        if (q2.empty()) return -1; // Stack is empty
        return q2.front();
    }

    bool empty() {
        // Returns whether the stack is empty
        return q2.empty();
    }
};

int main(){
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.top() << endl; // Should print 3
    cout << "Popped element: " << stack.pop() << endl; // Should print 3
    cout << "Top element after pop: " << stack.top() << endl; // Should print 2
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Should print No
    stack.pop(); // Pop 2
    stack.pop(); // Pop 1
    cout << "Is stack empty after popping all elements? " << (stack.empty() ? "Yes" : "No") << endl; // Should print Yes
    stack.pop(); // Attempt to pop from empty stack, should handle gracefully
    cout << "Popped element from empty stack: " << stack.pop() << endl; // Should print -1 or some error message
    cout << "Top element from empty stack: " << stack.top() << endl; // Should print -1 or some error message

    return 0;
}