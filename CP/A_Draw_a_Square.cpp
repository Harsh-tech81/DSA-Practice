#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a!=b || b!=c || c!=d || d!=a) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
   return 0;
}