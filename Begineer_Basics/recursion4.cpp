// Calculate the maximum value in the array using recursion 
#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
void max_calculate(vector<int>& nums,int idx,int max){
int n=nums.size();
if(idx==n){
    cout<<max<<endl;
    return;
}
if(max<nums[idx]) max=nums[idx];
max_calculate(nums,idx+1,max);
}
// Calculate maximum value and return the max value from the function of int type
int max_in(vector<int>&nums,int idx){
    int n=nums.size();
if(idx==n) return INT_MIN;
return max(nums[idx],max_in(nums,idx+1));

}
int main(){
vector<int>nums{-5,45,6,-67,12,12,-78};
// max_calculate(nums,0,INT_MIN); 
// cout<<max_in(nums,0);


return 0;
}






