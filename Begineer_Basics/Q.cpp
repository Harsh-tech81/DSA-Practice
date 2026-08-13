#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
void binary(int decimal){
    int restore=decimal;
    vector<int>ans(2);
int temp=decimal;
int i=0, count=0;
while(temp>0){
if((decimal&1)!=0) count++;
temp/=2;
decimal=temp;
}
int a=0;
int j=0;
int st=restore;
while(st>0){
restore&=1<<j;
if(j%2==0 && restore>0) a++;
j++;
st/=2;
restore=st;
}
ans[0]=a;
ans[1]=count-a;




for(int val:ans) cout<<val<<"  ";
}

int main(){
binary(50);









    return 0;
}