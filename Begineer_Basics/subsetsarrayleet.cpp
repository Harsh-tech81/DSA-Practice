// Total number of subsets of the array is 2^n where n is number of elements 
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printSubset(vector<int>ans,int arr[],int n,int idx){
if(idx==n){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" "; 
    }
    cout<<endl;
    return;
}
printSubset(ans,arr,n,idx+1);
ans.push_back(arr[idx]);
printSubset(ans,arr,n,idx+1);



}
int main(){
int arr[]={1,2,3};
int n=sizeof(arr)/4;
vector<int>ans;
printSubset(ans,arr,n,0);

return 0;
}














