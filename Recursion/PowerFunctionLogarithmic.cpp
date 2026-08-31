#include <iostream>
using namespace std;
// Binary Exponentiation for calculating the higher power 
int loga(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    int ans = loga(x, n / 2);
    if (n % 2 == 0)
        return ans * ans;
    else
        return x * ans * ans;
}
int main()
{
    cout << loga(2,10) << endl;
    return 0;
}