// optimize  method is that using an extra space array of 26 size and constant space complexity 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>  // string-in-built-function can be used after including this header file  this below header file can also be used
#include<bits/stdc++.h> //  string-in-built-function can be used after including this header file 
using namespace std;
int main(){
string s;
getline(cin,s);
cout<<s<<endl;
int n=s.length();
// int count=0;
// int restore=0;
// char ans;
// for(int i=0;i<n-1;i++){
//     for(int j=i+1;j<n;j++){
//     if(s[i]==s[j]){
//         count++;
//         ans=s[j];
//     }
//     restore=count;
// }
//  if(count>restore)  ans=s[i];
// }

// cout<<ans<<"  "<<count;

vector<int>arr(26,0);
for(int i=0;i<n;i++){
    char ch=s[i];
    int ascii=(int)ch;
    arr[ascii-97]++;
}
int max=0;
for(int i=0;i<26;i++){
    if(max<arr[i]) max=arr[i];
}
for(int i=0;i<26;i++){
    if(arr[i]==max){
        int ascii=i+97;
        char ch=(char)ascii;
        cout<<ch<<"  "<<max<<endl;
    }
}

return 0;
}