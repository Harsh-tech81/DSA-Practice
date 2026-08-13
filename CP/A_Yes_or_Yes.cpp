#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        int cy=0,cn=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N') cn++;
            else cy++;
        }
        if(cy<=1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
   return 0;
}