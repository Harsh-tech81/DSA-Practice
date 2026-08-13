#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
vector<int>arr={1,4,5,3,2,7,6};
for(int val:arr) cout<<val<<"  ";
int n=arr.size();
cout<<endl;
vector<int>ans(n);   // we have to optimize the code by not using any extra vector we hwve to return the original vector 
// ans[0]=arr[0];
// for(int i=1;i<n;i++){
//     ans[i]=arr[i]+ans[i-1];
// }

for(int i=1;i<n;i++){
    arr[i]+=arr[i-1];
}
// for(int i=0;i<n;i++){
//     int sum=0;
//  for(int j=0;j<=i;j++){
//     sum+=arr[j];
   
// }   
//     ans.push_back(sum);
// }


for(int val:arr) cout<<val<<"  ";
// for(int val:ans) cout<<val<<"  ";








    return 0;
}