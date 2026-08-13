#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int main(){
string s="harsh is a  good and excellent boy and hero also at the same time ";
stringstream ss(s);
string temp;
vector<string>ans;
int count=0;

while(ss>>temp){
ans.push_back(temp);
}
int n=ans.size();
for(int i=0;i<n;i++) cout<<ans[i]<<endl;
for(int i=0;i<n-1;i++){
    count=1;
  for(int j=i+1;j<n;j++){
if(ans[i]==ans[j]) count++;
    
}  
}












return 0;
}