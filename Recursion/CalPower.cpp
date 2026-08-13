#include <iostream>
using namespace std;
int mod=1e9+7;
long long pow(long long a, long long b)
{
    if (b == 0 || a == 1)  // kisi ka bhi power 0 h to 1 return kr do ya phir 1 base rhe to 1 return kr do 
        return 1;
    return a * pow(a, b - 1);
}
int main()
{
    cout << pow(15,2) << endl;
    return 0;
}