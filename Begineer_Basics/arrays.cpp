#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
// string arr[]={"Ram","Rohan","manoj","Mona"};
// for(int i=0;i<4;i++)
// cout<<arr[i]<<"  ";
vector<int>v={3,4,-7,5,-22,45,1};
// cout<<v.capacity()<<endl;
// cout<<v.size();
sort(v.begin(),v.end());  // by using begin()+7 it can also be easily done 
 // In today's compiler it doesn't work sort() that easily sort the vector it is working but we have to add an extra header file i.e. #include<bits/stdc++.h> this is the header file that we have to add to use it 
// Reverse() is also work when this header file is already exist else give error 


for(int val:v) cout<<val<<" ";

















    return 0;
}