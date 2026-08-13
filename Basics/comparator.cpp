
#include <bits/stdc++.h>
using namespace std;
// bool myComparator(int a, int b) {
//   if (a >= b)
//     return true;
//   return false;
// }
bool myComparator(pair<int, int> p1, pair<int, int> p2) {
  return p1.first == p2.first ? p1.second >= p2.second : p1.first >= p2.first;
}
void print(vector<int> &v) {
  for (int el : v) {
    cout << el << " ";
  }
  cout << endl;
}
int main() {

  //   vector<int>v={6,1,3,5,6,2};
  //     sort(v.begin(),v.end(),myComparator);
  //     print(v);

  vector<pair<int, int>> vec = {{5, 6}, {2, 4}, {2, 3}};
  //   sort(vec.begin(), vec.end(),
  //        greater<pair<int, int>>()); // descending order me sort

  sort(vec.begin(), vec.end(), myComparator);
  for (auto x : vec) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}