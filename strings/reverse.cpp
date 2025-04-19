#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s = " Hello World";
    reverse(s.begin(), s.end());

    string ans = "";
    for(int i=0; i<s.size(); i++) {
        string word = "";
        while(i < s.size() && s[i] != ' ') {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());
        if(word.length() > 0) {
            ans += " " + word;
        }
    }

    cout << ans.substr(1);

    return 0;
}