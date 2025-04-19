#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int firstUnique(string s) {
    queue<char> q;
    unordered_map<char, int> m;

    for(int i=0; i<s.size(); i++) {
        if(m.find(s[i]) == m.end()) {
            q.push(i);
        }

        m[s[i]]++;

        while(q.size()>0 && m[s[q.front()]] > 1) {
            q.pop();
        }
    }

    return q.size() > 0 ? q.front() : -1;
}

int main() {
    string s = "level";
    cout << "First unique character: " << firstUnique(s) << endl;
    s = "aabbccdd";
    cout << "First unique character: " << firstUnique(s) << endl;

    return 0;
}