#include<iostream>
using namespace std;
int main(){
int arr[]={12,56,53,12,56,22,22};
int n=sizeof(arr)/4;
for(int i=0;i<n-1;i++){
    bool flag=false;
 for(int j=i+1;j<n;j++){   
if(arr[i]==arr[j]) flag=true;
}
if(flag==false){
    cout<<arr[i];
    break;
}
}

    return 0;
}