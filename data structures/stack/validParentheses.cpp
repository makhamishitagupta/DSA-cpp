#include <stack>
#include <iostream>
#include <string>

using namespace std;

// TC => O(n)
// SC => O(n)
bool isBalanced(string str) {
    stack<char> st;
    
    for(char ch : str) {
        if(ch == '(' || ch == '[' || ch == '{') {
            st.push(ch); // Push opening bracket
        } else {
            if(st.empty()) return false; // Closing bracket without matching opening bracket
            
            char top = st.top();
            if((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}')) {
                st.pop(); // Valid match, pop from stack
            } else {
                return false; // Mismatched brackets
            }
        }
    }

    return st.empty(); // If stack is empty, it's balanced
}

int main() {
    string str = "({[]}[])";
    
    if(isBalanced(str)) cout << "true" << endl;
    else cout << "false" << endl;

    return 0;
}
