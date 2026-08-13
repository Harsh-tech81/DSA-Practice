// parameterised way to sum the numbers from 1 to N using parameters 
#include<iostream>
using namespace std;
int sum1(int ans,int n){
 if(n==1) return ans;
 sum1(ans+n,n-1);
}
int main(){
    int n;
    cout<<" Enter any Number : ";
    cin>>n;
cout<<sum1(1,n);

return 0;
}