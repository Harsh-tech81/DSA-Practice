#include<iostream>
#include<climits>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void permutations(string ans,string original){
if(original.size()==0){
    cout<<ans<<endl;
    return;
}

for(int i=0;i<original.length();i++){
char ch=original[i];
string left=original.substr(0,i);
string right=original.substr(i+1);
permutations(ans+ch,left+right);
}

}
int main(){
string str="abc";
permutations("",str);  // empty string 

return 0;
}


