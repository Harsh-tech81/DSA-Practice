// Leetcode 2429 pending solution 

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int set_bits(int tempr){
   int temp=tempr;
int i=0, count=0;
while(temp>0){
if((tempr&1)!=0) count++;
temp/=2;
tempr=temp;
} 
return count;
}
    int minimizeXor(int num1, int num2) {
        int x=1;
        while(x<=num1){
int store=set_bits(num2);
int s=set_bits(x);
  if(s==store)  return x;
  ++x;    
        }
// x=num1;
while(1){
int store=set_bits(num2);
int s=set_bits(x);
if(s==store) return x;
++x;
        // return x;
    }
    return x;
    }


int main(){
cout<<minimizeXor(1,12);

return 0;
}
