#include <bits/stdc++.h>
using namespace std;
// int t[21][5001][5001] // This will give MLE so memoize it in 2-D vector
// only Now we r using 2-D vector one of indices and other one is diff of
// (l1-l2)
// maintain a offset value to solve the problem of negative indices of the diff
// value so add the common offset value of 5000
int t[21][10003];
int helper(int i, vector<int> &rods, int diff) { // diff is l1-l2
  if (i == rods.size()) {
    if (diff == 0) {
      return 0;
    }
    return INT_MIN;
  }
  if (t[i][diff + 5000] != -1) // we have added the offset value so that it becomes postive index range 
    return t[i][diff + 5000]; // we have added the offset value of 5000 since
                              // the diff range goes from -5000 to 5000 after
                              // adding 5000 it goes from 0 to 10000
                              // so everywhere add diff+5000 new concept
  int skip = helper(i + 1, rods, diff);
  int take1 = rods[i] + helper(i + 1, rods, diff + rods[i]);
  int take2 = rods[i] + helper(i + 1, rods, diff - rods[i]);
  return t[i][diff + 5000] = max({skip, take1, take2});
}
int tallestBillboard(vector<int> &rods) {
  memset(t, -1, sizeof(t));
  return helper(0, rods, 0) /
         2; // as we have got the sum of all the possible rods in the set
}
int main() { 
    vector<int>rods={1,2};
    cout<<tallestBillboard(rods)<<endl;


    return 0; }
