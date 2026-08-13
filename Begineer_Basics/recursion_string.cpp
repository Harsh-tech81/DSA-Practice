// Recursion in strings Question 
// Skip a character 
#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
#include<string>
using namespace std;
// void removechar(string ans,string original){
//     if(original.size()==0){
//         cout<<ans<<endl;
//         return;
//     }
// char ch=original[0];
// // You want to remove any character from the word that you want 
// if(ch=='a') removechar(ans,original.substr(1));  // use of in-built function in string substr() function 
// else removechar(ans+ch,original.substr(1));
    
// }

// void removechar2(string ans,string original,int idx){
//     if(idx==original.size()){
//         cout<<ans<<endl;
//         return;
//     }
// char ch=original[idx];
// // You want to remove any character from the word that you want 
// if(ch=='a') removechar2(ans,original,idx+1);  // use of in-built function in string substr() function 
// else removechar2(ans+ch,original,idx+1);
    
// }
void removechar2(vector<int>&ans,vector<int>&nums,int idx){
    if(idx==nums.size()){
      for(int val:ans) cout<<val<<"  ";
        return;
    }
int ch=nums[idx];
// You want to remove any character from the word that you want 
if(ch==1) removechar2(ans,nums,idx+1);  // use of in-built function in string substr() function 
else{
ans.push_back(ch);
 removechar2(ans,nums,idx+1);
}
}
int main(){
// string s;
// getline(cin,s);
// cout<<s<<endl;

// string s;
// getline(cin,s);
// cout<<s<<endl

// int n=s.size();
// string ans;
// for(int i=0;i<n;i++){
//     if(s[i]!='a') ans.push_back(s[i]);
// }
// cout<<ans<<endl;
// This is done by using For loop now it is done by using Recursion 
// removechar("",s); // send an empty string to the function 
// removechar2("",s,0); 
vector<int>nums={1,2,3,1,1,4,1,7};
vector<int>ans;
removechar2(ans,nums,0);

return 0;
}