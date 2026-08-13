// Leetcode Q 1160
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
  int countCharacters(vector<string>& words, string chars) {
        int n=words.size();
        int ans=0;
        bool flag=false;
        int m=chars.size();
for(int i=0;i<n;i++){
    flag=false;
    string word=words[i];
int size=word.size();
for(int j=0;j<size;j++){
 for(int k=0;k<m;k++){
    flag=false;
    if(word[j]==chars[k]) flag=true;
}
}
if(flag==true) ans+=word.size();

}
   return ans;   
    }

int main(){
  vector<string>words={"cat","bt","hat","tree"};
  string chars =  "atach";
cout<<countCharacters( words,chars);

return 0;
}