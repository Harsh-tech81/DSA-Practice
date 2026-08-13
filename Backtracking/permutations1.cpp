#include <bits/stdc++.h>
using namespace std;
void permutations(string ipt, string opt) {
  if (ipt.length() == 0) {
    cout << opt << endl;
    return;
  }
  for (int i = 0; i < ipt.size(); i++) {
    permutations(ipt.substr(0, i) + ipt.substr(i + 1), opt + ipt[i]);
  }
}
int main() {
  permutations("abc", "");
  return 0;
}