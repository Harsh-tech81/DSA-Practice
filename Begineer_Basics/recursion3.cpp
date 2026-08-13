#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& nums,int idx){
int n=nums.size();
if(idx==n) return;  // Base case
cout<<nums[idx]<<"  ";  // Kaam 
print(nums,idx+1);  // Recursive Call 
}

int main(){
vector<int>nums{0,1,2,3,4,5,6,7,8,9,10};
int n=nums.size();
//    for(int i=0;i<n;i++){
//     cout<<arr[i]<<"   ";
//    }

print(nums,0); 
// for(int val:nums) cout<<val<<"  ";  // for each loop can be used also to print the elements of the array 

return 0;
}






