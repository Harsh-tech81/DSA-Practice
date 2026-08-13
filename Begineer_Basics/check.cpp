#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
int n=nums.size();
int store=nums[0];
// int ans=1;
for(int i=1;i<=n;i++){
    if(store==nums[i]){

    }
    else{
        an.push_back(store);
        store=nums[i];
        // ans++;
    }
}
for(int val:nums) cout<<val<<"  ";
cout<<endl;
   return nums.size();     
    }
int main(){
vector<int>nums={0,0,1,1,1,2,2,3,3,4};
cout<<removeDuplicates(nums);
// for(int val:ans) cout<<val<<"  ";



    return 0;
}