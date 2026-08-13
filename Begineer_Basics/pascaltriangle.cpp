// Same Q on Leetcode 118
#include<iostream>
using namespace std;
long long fact(int n){
  if(n==0 || n==1) return 1;
  return n*fact(n-1);
}
long long nCr(int n,int r){
  return fact(n)/(fact(r) * fact(n-r));
}
int main(){
int n;
cout<<" Enter Number of rows of pascal's Triangle : ";
cin>>n;
for(int i=0;i<n;i++){
  for(int j=0;j<i+1;j++){
  cout<<nCr(i,j)<<" "; 
}
cout<<endl;
}

return 0;
}