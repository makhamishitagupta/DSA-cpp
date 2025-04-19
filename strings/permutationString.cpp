#include<iostream>
#include<string>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]){
    for(int i=0; i<26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }

    return true;
}

int main(){
    string s1 = "ab";
    string s2 = "efdbaoo";
    //frequency
    int freq[26] = {0};
    for(int i=0; i<s1.size(); i++){
        freq[s1[i] - 'a']++;
    }
    //window frequency
    int windSize = s1.size();
    for(int i=0; i<s2.size(); i++){
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};

        while(windIdx < windSize && idx < s2.size()){
            windFreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        if(isFreqSame(freq, windFreq)){
            cout << "TRUE"<<endl;
        }
    }


    return 0;
}