
#include<iostream>
using namespace std;
int power(int a,int b){ 
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) return power(a,b/2) * power(a,b/2);
else return  power(a,b/2) * power(a,b/2)*a;
  // recursive call of the function using recursion 
}
int main(){
    int a;
    cout<<" Enter base : ";
    cin>>a;
  int b;
    cout<<" Enter power : ";
    cin>>b;
cout<<power(a,b);
return 0;
}