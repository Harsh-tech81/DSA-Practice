// Total number of subsets in a string containing duplicate elements is absolutely less than 2^N
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void removechar2(string an,string original,vector<string> & ans,bool flag){
    if(original==""){   // original becomes empty string 
    ans.push_back(an);
        return; 
    }
 char ch=original[0];
if(original.length()==1){
    if(flag==true) removechar2(an+ch,original.substr(1),ans,true);
    removechar2(an,original.substr(1),ans,true);
    return; // taaki niche ki dono condition nahi chle esliye return kiya h 
}
char dh=original[1];
if(ch==dh){  // duplicate exist then 
 if(flag==true) removechar2(an+ch,original.substr(1),ans,true); 
 removechar2(an,original.substr(1),ans,false);
}
else { // when duplicate doesn't exist
   if(flag==true) removechar2(an+ch,original.substr(1),ans,true); 
 removechar2(an,original.substr(1),ans,true);  
}

}

int main(){
string original="baaabc";
sort(original.begin(),original.end());
vector<string>ans;
removechar2("",original,ans,true);
for(string val:ans) cout<<val<<endl;

return 0;
}














