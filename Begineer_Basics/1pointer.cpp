#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int>nums={1,1,0,1,0,1,1,0};
int n=nums.size();
int i=0;
int j=n-1;
// This can be solved by three different ways 
while(i<j){
     if(nums[i]==1 && nums[j]==0){
     swap(nums[i],nums[j]);
i++;j--;
    }
    if(nums[j]==1) j--;
    if(nums[i]==0) i++;
    // if(i>j) break;  // Edge case 
//    else if(nums[i]==1 && nums[j]==0){
//      swap(nums[i],nums[j]);
// i++;j--;
//     }
}
for(int val:nums) cout<<val<<"  ";

return 0;
}



















































