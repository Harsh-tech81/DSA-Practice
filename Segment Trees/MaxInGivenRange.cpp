#include <bits/stdc++.h>
using namespace std;
vector<int> st; // segment Trees

void buildTree(vector<int> &arr, int idx, int lo, int hi) {
  if (lo == hi) {
    st[idx] = arr[lo];
    return;
  }
  int mid = lo + (hi - lo) / 2;
  buildTree(arr, 2 * idx + 1, lo, mid);     // Left SubTree
  buildTree(arr, 2 * idx + 2, mid + 1, hi); // Right SubTree
  st[idx] = max(st[2 * idx + 1], st[2 * idx + 2]);  // its children left and right child 2*i+1 and 2*i+2 respectively
}
int getMax(int idx, int lo, int hi, int &l, int &r) {
  if (r < lo || l > hi)
    return INT_MIN;
  if (lo >= l && hi <= r)
    return st[idx];
  int mid = lo + (hi - lo) / 2;
  int leftMax = getMax(2 * idx + 1, lo, mid, l, r);
  int rightMax = getMax(2 * idx + 2, mid + 1, hi, l, r);
  return max(leftMax, rightMax);
}

int main() {
  vector<int> arr = {1, 4, 2, 8, 6, 4, 9, 3};
  int n = arr.size();
  st.resize(4 * n);
  buildTree(arr, 0, 0, n - 1);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << getMax(0, 0, n - 1, l, r) << endl;
  }

  return 0;
}