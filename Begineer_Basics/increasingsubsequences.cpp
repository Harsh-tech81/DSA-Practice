// Total number of subsets of the array is 2^n where n is number of elements 
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printSubset(vector<int>ans,int arr[],int n,int idx,int k){
if(idx==n){
    if(ans.size()==k)
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" "; 
    }
    cout<<endl;
    return;
}
if(ans.size()+(n-idx) < k) return;  // Time complexity better ho jaygi  ye condition lagane se 
printSubset(ans,arr,n,idx+1,k);
ans.push_back(arr[idx]);
printSubset(ans,arr,n,idx+1,k);

}
int main(){
int arr[]={1,2,3,4,5};
int n=sizeof(arr)/4;
vector<int>ans;
printSubset(ans,arr,n,0,3);

return 0;
}














