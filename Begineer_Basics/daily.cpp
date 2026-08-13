#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
 int longestPalindrome(vector<string>& words) {
        int count1 = 0;
        int count2 = 0;
        string s;
        string p;
        int n = words.size();
        bool flag = true;
        for (int i = 0; i < n; i++) {
             s = words[i];
             p=words[i];
            if (flag) {
                for (int i = 0; i < 1; i++) {
                    if (s[i] == s[i + 1]) {
                        count2+=2;
                        flag = false;
                    }
                }
            }
            for (int j = i + 1; j < n; j++) {
                reverse(s.begin(), s.end());
                if (s==p)  {
                    count1 += 4;
                    break;
                }
            }
        }

        int ans = count1 + count2;
        return ans;
    }
int main(){
vector<string>words={"cc","ll","xx"};
cout<<longestPalindrome(words);


return 0;
}