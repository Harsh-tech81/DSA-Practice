#include <iostream>
using namespace std;
int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1; // we assumed 1-indexed fibonacci series and find ith fibonacci series
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    for (int i = 1; i <= 12; i++)
        cout << fibo(i) << "  ";
    return 0;
}