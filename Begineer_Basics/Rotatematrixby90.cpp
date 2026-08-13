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
// first find the transpose of the matrix
for(int i=0;i<m;i++){
  for(int j=i;j<m;j++){      // very important step in this to start j from i or even you start from j=i+1
swap(arr[i][j],arr[j][i]);
  }
} 
// Then write code for rotating it by 90 degrees Clockwise
// To rotate 90 deg clockwise take transpose of the matrix and then row reverse (reverse all the rows )
// To rotate 90 deg AntiClockwise take transpose of the matrix and then col reverse(reverse all the cols )
// first find the transpose of the matrix then do it as shown above 
 for(int i=0;i<m;i++){
int j=0;
int k=m-1;
while(j<k){
int temp=arr[i][j];  //swaping the two...
 arr[i][j]=arr[i][k];
arr[i][k]=temp;
j++;
k--;
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