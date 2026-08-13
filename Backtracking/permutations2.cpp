#include <bits/stdc++.h>
using namespace std;
void permutations(
    string &str,
    int i) { // string is passed by ref and this is backtracking means I
             // reverted the changes which is swap when I backtrack
  if (i == str.length() - 1) {
    cout << str << endl;
    return;
  }
  unordered_set<char> st;
  for (int idx = i; idx < str.size(); idx++) {
    if (!st.count(str[idx])) {
      swap(str[idx], str[i]);
      st.insert(str[idx]);
      permutations(str, i + 1);
      swap(str[idx], str[i]);  // revert the changes during backtrack
    }
  }
}
int main() {
  string str = "123";
  permutations(str, 0);
  return 0;
}