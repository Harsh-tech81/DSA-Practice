// smallest missing non-negative element by using binary search algorithm 
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int main(){
vector<int>nums={0,1,2,3,4,7};
int n=nums.size();
// This is done by linear search algorithm 

// for(int i=0;i<n;i++){
//     if(i==nums[i]){
//     }
//     else{
//     cout<<i<<endl;
//     break;
//     }
// }

//  optimized code for the binary search 
int ans=-1;
int st=0;
int end=n-1;
while(st<=end){
 int mid=st+(end-st)/2;
if(mid==nums[mid]) st=mid+1;
else {
  ans=mid;
  end=mid-1;
}
}

cout<<ans;

return 0;
}













