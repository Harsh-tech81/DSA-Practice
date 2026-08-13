#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main(){
string str;
getline(cin,str);
// cout<<str.length();
// cout<<endl<<str.size();
// str.pop_back();
// cout<<str<<endl;
// str.push_back('t');
// int x=90;
// string s =to_string(x);
// cout<<s.length();   // Integer value gets converted into string value and we can used in-built string function
cout<<str<<endl;
//  reverse(str.begin(),str.begin()+5); 
sort(str.begin(),str.end()); // sort on the basis of the ASCII values of the alphabets 
cout<<str<<endl;
// string str2=" rathor Sah";
// cout<<str+str2<<endl;   // use of addition operator in the strings 


return 0;
}