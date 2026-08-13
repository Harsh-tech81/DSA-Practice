#include<iostream>
using namespace std;
void preInpost(int n){
if(n==0) return;
cout<<"Pre : "<<n<<endl; // Pre kaam before any call of the function
preInpost(n-1);
cout<<"In : "<<n<<endl;  // kaam which is in between the Two call of the function 
preInpost(n-1);
cout<<"Post : "<<n<<endl;  // post kaam jo last me function khtm ho  jane ke baad lgta h

}
int main(){
preInpost(3);

return 0;
}