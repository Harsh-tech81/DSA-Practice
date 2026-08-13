// Trapping Rainwater leetcode --> 42 (Hard Level Q)
#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
int main(){
// We have to made two different arrays i.e. previous Greatest Element(arr) and next Greatest element(brr) these two arrays are important to solve this problem 
vector<int>nums={4,2,3};
int n=nums.size();
vector<int>ans(n);
ans[0]=-1;
int max=nums[0];
for(int i=1;i<n;i++){
    ans[i]=max;
    if(max<nums[i]) max=nums[i];
}

// for(int val: ans ) cout<<val<<"  "; 
cout<<endl<<endl;
vector<int>brr(n);
brr[n-1]=-1;
for(int i=0;i<n-1;i++){
 max=INT_MIN;
for(int j=i+1;j<n;j++){
    // brr[i]=max;
    if(max<nums[j]) max=nums[j];
}
  brr[i]=max;
}
// for(int val: brr ) cout<<val<<"  "; 
vector<int>num(n);
for(int i=0;i<n;i++){
    num[i]=min(ans[i],brr[i]);
}
// for(int val: num ) cout<<val<<"  "; 

int sum=0;
for(int i=0;i<n;i++){
    if(num[i]>nums[i]) sum+=num[i]-nums[i];
}
cout<<sum;


    return 0;
}