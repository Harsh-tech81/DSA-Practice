#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int pos=0;
    bool check(vector<int>& nums) {
        int n=nums.size();
  
       
        while(pos<=n){
            
for(int i=1;i<=pos;i++) {
int restore=nums[0];
 for(int i=0;i<n-1;i++){
  nums[i]=nums[i+1];
 }
   nums[n-1]=restore;
}

for(int i=0;i<n-1;i++){
    if(nums[i]<=nums[i+1]) {

    }
    else {
        // flag=false;
        ++pos;
  check(nums);
}
}
return true;
        }
        return false;
    }
int main(){
vector<int>nums={2,1,3,4};
cout<<check(nums);











return 0;
}