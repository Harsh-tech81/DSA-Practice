#include<iostream>
using namespace std;
int main(){
 int m,n;
 cout<<" Enter number of rows of matrix : ";
cin>>m;
 cout<<" Enter number of columns of matrix : ";
cin>>n;
    cout<<" Enter the Elements of matrix : " <<endl;
    int arr[m][n];
 for(int i=0;i<m;i++)
  for(int j=0;j<n;j++)
cin>>arr[i][j];
 for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
cout<<arr[i][j]<<"  ";
  }
  cout<<endl;
}
// Code for wave matrix printing by solving different ways of printing the wave like structure 
 for(int j=0;j<n;j++){
  for(int i=0;i<m;i++){
    if(j%2!=0) cout<<arr[m-1-i][j]<<" ";
else  cout<<arr[i][j]<<" ";
  }
}


return 0;
}