#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int>arr1={1,2,2,4,5,6,6,8,8,12};
int n=arr1.size();
vector<int>arr2={2,2,2,4,4,4,5,5,6,9,9,13,15,15,19};
int m=arr2.size();
vector<int>ans;
   ans.push_back(arr1[0]);
for(int i=0;i<n-1;i++){
    // int store=arr1[i];
    // ans.push_back(store);
    if(arr1[i]!=arr1[i+1]){
          ans.push_back(arr1[i+1]);
    }
    else{}
}
int size=ans.size();
// for(int val:ans) cout<<val<<" ";
bool flag;
for(int i=0;i<m;i++){
size=ans.size();
 flag=false;
for(int j=0;j<size;j++){ 
if(arr2[i]==ans[j]) {
    flag=true;
}
}
if(flag==false) ans.push_back(arr2[i]);
}
size=ans.size();
// Algorithm to sort an array by bubble sorting algorithm 
for(int i=1;i<size;i++){
  for(int j=0;j<size-1;j++){
   if(ans[j] > ans[j+1]) {
    swap(ans[j],ans[j+1]);
   
   }
  }
 }
for(int val:ans) cout<<val<<" ";

return 0;
}