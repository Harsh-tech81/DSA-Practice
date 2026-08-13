#include<iostream>
using namespace std;
int main(){
int arr[]={12,5,3,6,9,0,7};
int brr[]={9,0,7,6};
int n=sizeof(arr)/4;
int m=sizeof(brr)/4;
for(int i=0;i<m;i++){
    bool flag=false;
 for(int j=0;j<n;j++){   
if(brr[i]==arr[j]) flag=true;
}
if(flag==false){
    cout<<"No";
    return 0;
}
}

  cout<<"yes";

    return 0;
}