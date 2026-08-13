// Le --> 31 Next permutation Medium level Question 

class Solution {
public:
 void reverse(vector<int>& nums,int i,int j){
while(i<j){
    swap(nums[i],nums[j]);
    i++;
    j--;
}
return;
 }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        // Finding Pivot index 
        int idx=-1;
    for(int i=n-2;i>=0;i--){
if(nums[i]<nums[i+1]){
    idx=i;
    break;
}
    }
    if(idx==-1){
     reverse(nums,0,n-1);
     return;
    }
reverse(nums,idx+1,n-1);
int store=-1;
for(int i=idx+1;i<n;i++){
    if(nums[i]>nums[idx]){
        store=i;
        break;
    }
}
 swap(nums[idx],nums[store]) ;  
return;
    }
};