#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'a', 'a', 'c'};

    int idx = 0;
    for(int i=0; i<chars.size(); i++) {
        char ch = chars[i];
        int count = 0;
        
        while(i < chars.size() && chars[i] == ch) {
            count++;
            i++;
        }

        if(count == 1) {
            chars[idx++] = ch; 
        } else {
            chars[idx++] = ch;
            string str = to_string(count);
            for(char digit: str) {
                chars[idx++] = digit;
            }
        }

        i--;
    }

    for(int i=0; i<idx; i++) {
        cout << chars[i] << " ";
    }

    return 0;
}