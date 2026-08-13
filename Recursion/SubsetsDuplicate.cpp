#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printSubset(string ans, string ori, vector<string> &v, bool flag)
{
    if (ori == "")
    {
        v.push_back(ans);
        return;
    }
    char ch = ori[0];
    if (ori.length() == 1)
    {
        if (flag == true)
            printSubset(ans + ch, ori.substr(1), v, true);
        printSubset(ans, ori.substr(1), v, true);
        return; // takki niche ki do condition na chle
    }
    char dh = ori[1];
    if (ch == dh) // duplicate
    {
        if (flag == true){
            printSubset(ans + ch, ori.substr(1), v, true);
        }
        printSubset(ans, ori.substr(1), v, false);
    }
    else // No duplicate
    {
        if (flag == true){
  printSubset(ans + ch, ori.substr(1), v, true);
        }
          
        printSubset(ans, ori.substr(1), v, true);
    }
}

int main()
{
    string str = "abb";
    vector<string> v;
    printSubset("", str, v, true);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}