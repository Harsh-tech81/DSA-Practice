#include <bits/stdc++.h>
using namespace std;
void permutations(string ans, string orig)
{
    if (orig == "")
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < orig.size(); i++)
    {
        char ch = orig[i];
        string left = orig.substr(0, i);
        string right = orig.substr(i + 1);
        permutations(ans + ch, left + right);
    }
}
int main()
{
    string str = "123";
//  vector<int>arr;
//  for(char ch : str) {
//      arr.push_back(ch-'0');
//  }
//  for(int el : arr){
//         cout << el << " ";
//  }
    permutations("", str);
    // string s = "1001010";
    // vector<int> ans;
    // vector<int> v;
    // printSubset(arr, 3, 0, ans, 2);
    // printSubset2("", s, 0, 2);
    // printSubset4(arr, 3, 0, ans);
    // printSubset21("", s, 0);
    return 0;
}