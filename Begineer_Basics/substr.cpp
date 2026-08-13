#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){

string s="12345";
int n=s.length();
for(int i=0;i<n;i++){
    for(int j=0;j<n+1-i;j++){
        cout<<s.substr(i,j)<<"  ";
    }
    cout<<endl;
}
//      for (int i = 0; i < n; i++) {  // new method is used here s.find() 
        //     if (s.find(patterns[i]) != -1)   // not equal to -1 signifies that the element is exist in the array count++;
        //         count++;
        // }

    return 0;
}