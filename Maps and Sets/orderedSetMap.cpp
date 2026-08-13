#include <iostream>
#include <set> // for ordered set and map
#include <map>
using namespace std;
int main()
{
    // set<int> s;  // ordered set
    // s.insert(-5);
    // s.insert(-12);
    // s.insert(69);
    // s.insert(12);
    // for (auto ele : s)  // always print in increasing order
    //     cout << ele << "  ";

    map<string, int> m; // ordered map
    m["Zaid"] = 20;
    m["Apple"] = 10;
    m["Harsh"] = 30;

    for (auto ele : m) // always print in increasing order
        cout << ele.first << "  " << ele.second << endl;
    // In maps sorting occurs on the basis of the key not values

    return 0;
}