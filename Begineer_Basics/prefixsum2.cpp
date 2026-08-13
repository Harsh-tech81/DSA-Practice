// continuous way of partition of an array 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
vector<int>arr={1,2,3,4,5,5,10,10};
for(int val:arr) cout<<val<<"  ";
int n=arr.size();
cout<<endl;


for(int i=1;i<n;i++){
    arr[i]+=arr[i-1];
}

bool flag=false;
for(int i=0;i<n;i++){
    if(2*arr[i]==arr[n-1]){
    cout<<i;
    flag=true;
    break;
    }
}
if(!flag) cout<<"-1";


    return 0;
}









