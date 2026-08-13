#include<iostream>
#include<climits>
using namespace std;
int main(){
  int m;
  cout<<" Enter Number of Rows/columns : ";
  cin>>m;
int arr[m][m];
cout<<" Enter elements of the Matrices : ";
for(int i=0;i<m;i++){
  for(int j=0;j<m;j++){
    cin>>arr[i][j];
  }
} 
for(int i=0;i<m;i++){
  for(int j=0;j<m;j++){
    cout<<arr[i][j]<<"  ";
  }
  cout<<endl;
} 
cout<<endl;
cout<<" Transpose of the Given Matrix : "<<endl;
// Transpose of the matrix calculate Code 
// 1. --> by changing the original array 
for(int i=0;i<m;i++){
  for(int j=i;j<m;j++){      // very important step in this to start j from i or even you start from j=i+1
swap(arr[i][j],arr[j][i]);
  }
} 

for(int i=0;i<m;i++){
  for(int j=0;j<m;j++){
    cout<<arr[i][j]<<"  ";
  }
  cout<<endl;
} 

return 0;
}