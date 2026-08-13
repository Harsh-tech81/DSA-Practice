// leetcode Q of maximum citizen or adult citizen age is greater than 60
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
     string store;
  int countSeniors(vector<string>& details) {
        int ans=0,pro;
        // string store;
int n=details.size();
for(int i=0;i<n;i++){
store=details[i].substr(11,2);
//  pro=store[0];
// for(int j=1;j<2;j++){
// pro=pro*10+store[j];
// }
//  if(pro>60) ans++;
}

return pro;
}

int main(){
    vector<string>details={"1313579440F2036","2921522980M5644"};
cout<<countSeniors(details);

return 0;
}