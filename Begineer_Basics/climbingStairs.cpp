// Le-->70 TLE but code is accepted it must be optimized more by DP which I didn't Know at that time 
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;
    int climbStairs(int n) {
        if(n==1 || n==2) return n;  
        int totalways=climbStairs(n-1)+climbStairs(n-2);
        return totalways;
    }
int main(){
cout<<climbStairs(4);
















    
return 0;
}