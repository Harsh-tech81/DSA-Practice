#include <bits/stdc++.h>
using namespace std;
// Knuth-Morris-Pratt KMP String Matching Algorithm
void computeLPS(vector<int> &LPS, string &pattern) {
  int length = 0; // length of prev longest prefix and suffix which were equal
  int m = pattern.size();
  int i = 1;
  while (i < m) {
    if (pattern[i] == pattern[length]) {
      length++;
      LPS[i] = length;
      i++;
    } else {
      if (length != 0)
        length = LPS[length - 1];
      else {
        LPS[i] = 0;
        i++;
      }
    }
  }
}
vector<int> KMP(string txt, string pattern) {
  int n = txt.size();
  int m = pattern.size();
  vector<int> ans;
  // create an LPS array to store the length of longest proper prefix which is
  // also a suffix lps[i]=the longest length of the proper prefix of
  // pattern[0..i] which is also a suffix of pattern[0..i]
  vector<int> LPS(m, 0);
  computeLPS(LPS, pattern);
  // Apply KMP algo
  int i = 0;
  int j = 0;
  while (i < n) {
    if (txt[i] == pattern[j]) {
      i++;
      j++;
    }
    if (j == m) {           // found
      ans.push_back(i - j); // 0-based indexing if it is 1-based indexing then i-j+1
      j = LPS[j - 1];
    } else if (pattern[j] != txt[i]) {
      if (j != 0)
        j = LPS[j - 1];
      else
        i++;
    }
  }
  return ans;
}
int main() {
  string txt, pattern;
  cin >> txt >> pattern;
  vector<int> ans = KMP(txt, pattern);
  for (int el : ans)
    cout << el << " ";
  cout << endl;
  return 0;
}