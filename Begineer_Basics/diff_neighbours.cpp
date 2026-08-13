// different neighbours in a string 
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
string name;
getline(cin,name);
cout<<name<<endl;
int count=0;
int n=name.length();
for(int i=0;i<n;i++){
    if(n==1) break; 
    if(n==2 && name[0]!=name[1]){
 count=1;
 break;
    }
if(i==0 && name[i]!=name[i+1])  count++; 
else if(i==n-1 && name[i]!=name[i-1])  count++; 
else if(name[i]!=name[i+1] && name[i]!=name[i-1])  count++;
}    

cout<<count;

return 0;
}