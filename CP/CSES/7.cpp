#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long sum=n*(n+1)/2;
    long long cal=0;
    for(int i=1;i<n;i++){
        long long x;
        cin>>x;
        cal+=x;
    }
    cout<<sum-cal<<endl;
   return 0;
}