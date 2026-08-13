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
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='u'){
                if(i==0){
                    s[0]='s';
                    ans++;
                }else if(i==n-1){
                    s[n-1]='s';
                    ans++;
                }
                else{
                    if(s[i-1]!='s'){
                        ans++;
                        s[i-1]='s';
                    }
                    if(s[i+1]!='s'){
                        ans++;
                        s[i+1]='s';
                    }
                }
            }
        }
        cout<<ans<<endl;

    }
   return 0;
}