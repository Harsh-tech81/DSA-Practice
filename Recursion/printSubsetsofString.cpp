#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printSubset(string ans, string ori)
{
    if (ori == "")
    {
        cout << ans << endl;
        return;
    }
    char ch = ori[0];
    printSubset(ans + ch, ori.substr(1));
    printSubset(ans, ori.substr(1));
}

void vectorSubset(string ans, string ori, vector<string> &v)
{
    if (ori == "")
    {
        v.push_back(ans);
        return;
    }
    char ch = ori[0];
    vectorSubset(ans + ch, ori.substr(1), v);
    vectorSubset(ans, ori.substr(1), v);
}

int main()
{
    printSubset("", "abcc");
    vector<string> v;
    // vectorSubset("", "abc", v);


    return 0;
}