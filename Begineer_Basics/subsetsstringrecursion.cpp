//  Total numebr of subsets in the array of size N is 2^n 

#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
#include<bits/stdc++.h>
#include<string>
using namespace std;
// void removechar2(string ans,string original){
//     if(original==""){   // original becomes empty string 
//         cout<<ans<<endl;
//         return;
//     }
//  char ch=original[0];
// // You want to remove any character from the word that you want 
//  removechar2(ans,original.substr(1));  // use of in-built function in string substr() function 
//  removechar2(ans+ch,original.substr(1));

// }
// void removechar2(string ans,string original,int idx){
//     if(original==""){   // original becomes empty string 
//         cout<<ans<<endl;
//         return;
//     }
//  char ch=original[0];
// // You want to remove any character from the word that you want 
//  removechar2(ans,original.substr(1),idx+1);  // use of in-built function in string substr() function 
//  removechar2(ans+ch,original.substr(1),idx+1);

// }
void removechar2(vector<string>&ans,string original,string answer){
    if(original==""){   // original becomes empty string 
     ans.push_back(answer);
        return;
    }
 char ch=original[0];
// You want to remove any character from the word that you want 
 removechar2(ans,original.substr(1),answer+ch);  // use of in-built function in string substr() function 
 removechar2(ans,original.substr(1),answer);

}



int main(){
    // string ans;
    string original="abcd";
// removechar2("",original);
// removechar2("",original,0);
vector<string>ans;
string an;
removechar2(ans,original,an);
for(string val:ans) cout<<val<<endl;





return 0;
}