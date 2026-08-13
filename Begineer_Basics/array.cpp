// Rotate a vector by k-th positions right or left but in this Q it is made for right shifting a vector by k-th position 
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
vector<int>vec={1,2,3,4,5,6};
int n=vec.size();
int k;
cout<<" Enter how much position you want to rotate an array : ";
cin>>k;
k%=n;  // very important to do this modulo else it will give an error 
for(int val:vec) cout<<val<<"  ";
cout<<endl<<endl;
reverse(vec.begin(),vec.end()-k);
reverse(vec.end()-k,vec.end());
reverse(vec.begin(),vec.end());
for(int val:vec) cout<<val<<"  ";

    return 0;
}