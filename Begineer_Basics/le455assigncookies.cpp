#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
 int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        int i=0;
        int j=0;
     while(i<n && j<m){
       if(s[j]>=g[i]){
      count++;
      i++;
      j++;
       }
       else j++;
      } 
      
return count;
 }

int main(){
vector<int>arr1={};
vector<int>arr2={1,2,3};
cout<<findContentChildren(arr1,arr2);












return 0;
}
