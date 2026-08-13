#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int mx=-1;
    int curr=1;
    for(int i=0;i<s.length()-1;i++){
        if(s[i]==s[i+1]) curr++;
        else{
            mx=max(mx,curr);
            curr=1;
        }
    }
     mx=max(mx,curr);
    cout<<mx<<endl;
   return 0;
}