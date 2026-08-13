#include <iostream>
using namespace std;
int sum1ToN(int n)
{
    if (n == 1)
        return 1;
    return n + sum1ToN(n - 1);
}
void sumWithParameter(int n, int sum)   // little bit of confusing keep it in mind this concept with parameter sum 1 to N 
{
    if (n == 0)
    {
        cout << sum << endl;
        return;
    }

    sumWithParameter(n - 1, sum + n);
}
int main()
{
    // cout<<sum1ToN(1)<<endl;
    sumWithParameter(8, 0);
    return 0;
}