#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
vector<int>arr={-1,-8,0,5,-9};
sort(arr.begin(),arr.end());
for(int val:arr) cout<<val<<"  ";
int n=arr.size();
cout<<endl;
// vector<int>ans(n);
// Suffix Sum and product

for(int i=n-2;i>=0;i--){
    arr[i]+=arr[i+1];
}

// Prefix Sum and Product 
// ans[0]=arr[0];
// for(int i=1;i<n;i++){
//     ans[i]=ans[i-1]+arr[i];
// }

for(int val:arr) cout<<val<<"  ";

return 0;
}