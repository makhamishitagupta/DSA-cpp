
    #include <iostream>
    #include <string>
    using namespace std;

    class Solution {
        public:
            int pre(char s) {
                switch(s) {
                    case 'I' : return 1;
                    case 'V' : return 5;
                    case 'X' : return 10;
                    case 'L' : return 50;
                    case 'C' : return 100;
                    case 'D' : return 500;
                    case 'M' : return 1000;
                }
        
                return -1;
            }
            int romanToInt(string s) {
                int i=0;
                int ans = 0;
                while(s[i] != '\0') {
                    if(pre(s[i]) < pre(s[i+1])) {
                        int val = pre(s[i+1]) - pre(s[i]);
                        ans += val;
                        i += 2;
                        continue;
                    }
                    ans += pre(s[i]);
                    i++;
                }
                return ans;
            }
    };

    int main() {
        Solution solution;
        string roman;
        cout << "Enter a Roman numeral: ";
        cin >> roman;
        int result = solution.romanToInt(roman);
        cout << "The integer value is: " << result << endl;
        return 0;
    }