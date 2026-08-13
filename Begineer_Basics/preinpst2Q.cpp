#include<iostream>
using namespace std;
void preInpost(int n){
if(n==0) return;
cout<<n; // Pre kaam before any call of the function
preInpost(n-1);
cout<<n;  // kaam which is in between the Two call of the function 
preInpost(n-1);
cout<<n;  // post kaam jo last me function khtm ho  jane ke baad lgta h

}
int main(){
    int n;
    cout<<" Enter any Number : ";
    cin>>n;
preInpost(n);

return 0;
}