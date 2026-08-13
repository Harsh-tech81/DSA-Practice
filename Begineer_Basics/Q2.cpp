#include<iostream>
#include<vector>
using namespace std;
void intersection(vector<int>& nums1, vector<int>& nums2) {
int n=nums1.size();
int m=nums2.size();
vector<int>ans1;
   ans1.push_back(nums1[0]);
for(int i=0;i<n-1;i++){
   for(int j=i+1;j<n;j++){ 
    // int store=arr1[i];
    // ans.push_back(store);
    if(nums1[i]!=nums1[j]){
          ans1.push_back(nums1[i]);
    }
    else{}
}}
n=ans1.size();
vector<int>ans2;
   ans2.push_back(nums2[0]);
for(int i=0;i<m-1;i++){
     for(int j=i+1;j<m;j++){ 
    // int store=arr1[i];
    // ans.push_back(store);
    if(nums2[i]!=nums2[j]){
          ans2.push_back(nums2[i]);
    }
    else{}
}}
m=ans2.size();
vector<int>ans;
for(int i=0;i<n;i++){
   for(int j=0;j<m;j++){   
    if(ans1[i]==ans2[j]){
ans.push_back(ans1[i]);
    }
        else{} 
}

}
for(int val:ans) cout<<val<<" ";





}
 int main(){
vector<int>nums1={4,5,9};
vector<int>nums2={4,4,8,8,9};
intersection(nums1,nums2);

return 0;
}
