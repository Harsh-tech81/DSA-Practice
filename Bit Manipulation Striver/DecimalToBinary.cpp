#include <bits/stdc++.h>
using namespace std;

// bitset<8>(40)  built-in function to make the binary integer in 8 bit
int decimalToBinary(int n) {
  int ans = 0;
  int place = 1;
  while (n > 0) {
    int ld = n % 2;
    ans += ld * place;
    place *= 10;
    n /= 2;
  }
  return ans;
}
int main() { 
    int n;
    cin>>n;
    int ans=decimalToBinary(n);
    cout<<ans<<endl;


    return 0;
 }