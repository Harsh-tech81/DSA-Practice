// Print N to 1 using recursion
#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0) // base Case
        return;
    // cout << n << "  ";  // Kaam work  print N to 1 phle kaam baad me call
    print(n - 1);      // recursive call of the function
    cout << n << "  "; // print 1 to N  phle call baad me kaam esse reverse ho jata h
}
void print1toNusingParam(int n, int t)
{
    if (t > n)
        return;
    cout << t << "  ";
    print1toNusingParam(n, t + 1);
}
int main()
{
    print1toNusingParam(20, 1);  // using extra parameter t which is used

    return 0;
}