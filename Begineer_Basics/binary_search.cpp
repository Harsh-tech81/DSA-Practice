    // Lower Bound and upper bound using binary search using alogorithm  

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int st=0,mid;
int end=nums.size()-1;
while(st<=end){
 mid=st+(end-st)/2;
if(nums[mid]==target) return nums[mid+1];
else if(nums[mid]>target) end=mid-1;
else st=mid+1;
// else return nums[st-1];
}
// main thing that is different from binary search algorithm 

return nums[st];
    }
int main(){
 vector<int>nums={1,2,4,5,9,15,18,21,24};
int target = 13;
cout<<searchInsert(nums,target);



return 0;
}