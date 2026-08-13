// First occurrence in a binary search algorithm in array 
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
        int st=0,mid;
int end=nums.size()-1;
int first;
bool flag=false;
while(st<=end){
 mid=st+(end-st)/2;
if(nums[mid]==target){
    flag=true;
    first=mid;
    end=mid-1;
}
else if(nums[mid]>target) end=mid-1;
else st=mid+1;
// else return nums[st-1];
}
// main thing that is different from binary search algorithm 
if(!flag) return -1;
else return first;

    }
int main(){
 vector<int>nums={1,2,2,3,3,3,3,3,4,4,5,8,9};
int target = 9;
cout<<searchInsert(nums,target);

return 0;
}