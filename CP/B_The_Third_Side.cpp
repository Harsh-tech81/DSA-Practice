#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        int x=n-1;
        while(n--){
            int m;
            cin>>m;
            sum+=m;
        }
        cout<<sum-x<<endl;
    }
   return 0;
}