// by making an extra array isVisited array 
#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
// #include<string>
// #include<bits/stdc++.h>
using namespace std;
int main(){
    int count=0;
int arr[]={19,12,23,8,16};
int n= sizeof(arr)/4;
vector<int>isVisited(n,0);
for(int i=0;i<n;i++){
    int min=INT_MAX;
    int idx=-1;
for(int j=0;j<n;j++){
    if(isVisited[j]==0) continue;
    else{
 if(min>arr[j]){
idx=j;
min=arr[j];
}
    }
}
    arr[idx]=count;
    isVisited[idx]=1;
    count++;
}


for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}



