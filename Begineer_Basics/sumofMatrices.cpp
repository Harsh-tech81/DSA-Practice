#include<iostream>
#include<climits>
using namespace std;
int main(){
  int m,n;
  cout<<" Enter Number of Rows : ";
  cin>>m;
  cout<<" Enter Number of Columns : ";
  cin>>n;
int arr[m][n];
int brr[m][n];
cout<<" Enter elements of the Matrices : ";

for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
    cin>>arr[i][j];
  }
} 
cout<<endl;
for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
    cin>>brr[i][j];
  }
} 
cout<<endl;
for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){ 
arr[i][j]+=brr[i][j];
  }
  
}
for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){ 
cout<<arr[i][j]<<"  ";
  }
  cout<<endl;
}


















return 0;
}