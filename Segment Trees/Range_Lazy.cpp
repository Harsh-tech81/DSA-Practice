#include <bits/stdc++.h>
using namespace std;
vector<int> st;   // segment Trees
vector<int> lazy; // Lazy Trees
void buildTree(vector<int> &arr, int idx, int lo, int hi) {
  if (lo == hi) {
    st[idx] = arr[lo];
    return;
  }
  int mid = lo + (hi - lo) / 2;
  buildTree(arr, 2 * idx + 1, lo, mid);     // Left SubTree
  buildTree(arr, 2 * idx + 2, mid + 1, hi); // Right SubTree
  st[idx] =
      st[2 * idx + 1] + st[2 * idx + 2]; // its children left and right child
                                         // 2*i+1 and 2*i+2 respectively
}
void updateRange(int idx, int lo, int hi, int l, int r, int val) {
  // check for pending Lazy updates
  if (lazy[idx] != 0) {
    int rangeSize = hi - lo + 1;
    st[idx] += rangeSize * lazy[idx];
    if (lo != hi) { // send lazy to left and right child
      lazy[2 * idx + 1] += lazy[idx];
      lazy[2 * idx + 2] += lazy[idx];
    }
    lazy[idx] = 0;
  }
  if (r < lo || l > hi) // out of range
    return;
  if (lo >= l && hi <= r) { // update the entire [lo,hi]
    int rangeSize = hi - lo + 1;
    st[idx] += rangeSize * val;
    if (lo != hi) { // send lazy to left and right child
      lazy[2 * idx + 1] += val;
      lazy[2 * idx + 2] += val;
    }
    return;
  }
  int mid = lo + (hi - lo) / 2;
  updateRange(2*idx+1, lo, mid, l, r, val);
  updateRange(2*idx+2, mid + 1, hi, l, r, val);
  st[idx] = st[2 * idx + 1] + st[2 * idx + 2];
}
int getSum(int idx, int lo, int hi, int l, int r) {
  // check for pending Lazy updates
  if (lazy[idx] != 0) {
    int rangeSize = hi - lo + 1;
    st[idx] += rangeSize * lazy[idx];
    if (lo != hi) { // send lazy to left and right child
      lazy[2 * idx + 1] += lazy[idx];
      lazy[2 * idx + 2] += lazy[idx];
    }
    lazy[idx] = 0;
  }

  if (r < lo || l > hi)
    return 0;
  if (lo >= l && hi <= r)
    return st[idx];
  int mid = lo + (hi - lo) / 2;
  int leftSum = getSum(2 * idx + 1, lo, mid, l, r);
  int rightSum = getSum(2 * idx + 2, mid + 1, hi, l, r);
  return leftSum + rightSum;
}

int main() {
  vector<int> arr = {1, 4, 2, 8, 6, 4, 9, 3};
  int n = arr.size();
  st.resize(4 * n);
  lazy.resize(4 * n, 0); // Initialize the lazy tree with 0
  buildTree(arr, 0, 0, n - 1);
  cout << getSum(0, 0, n - 1, 1, 3) << endl;
  updateRange(0, 0, n - 1, 2, 5, 10);
  cout << getSum(0, 0, n - 1, 1, 3) << endl;
  return 0;
}