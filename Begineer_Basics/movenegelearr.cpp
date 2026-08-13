#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int>nums={1,-2,3,-4,-5,6,8};
int n=nums.size();
for(int i=1;i<=n;i++){
for(int j=0;j<n-1;j++){
    if(nums[j]>0 && nums[j+1]<0) swap(nums[j],nums[j+1]);
}    
}

// -6  -2  -5  -4  -3  1  4  8  9  12  15
// int i=0;
// int j=n-1;
// // This can be solved by three different ways 
// while(i<j){
//      if(nums[i]>0 && nums[j]<0){
//      swap(nums[i],nums[j]);
// i++;j--;
//     }
//     if(nums[j]>0) j--;
//     if(nums[i]<0) i++;
    // if(i>j) break;  // Edge case 
//    else if(nums[i]==1 && nums[j]==0){
//      swap(nums[i],nums[j]);
// i++;j--;
//     }

for(int val:nums) cout<<val<<"  ";









return 0;
}