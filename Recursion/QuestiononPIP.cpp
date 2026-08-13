// Print Zig - Zag
#include <iostream>
using namespace std;
void zigzag(int n)
{
    if (n == 0)
        return;
    cout << n;
    zigzag(n - 1);
    cout << n;
    zigzag(n - 1);
    cout << n;
}

int main()
{
    cout << endl;
    for (int i = 1; i <= 4; i++)
    {
        zigzag(i);
        cout << endl;
    }

    cout << endl;
    return 0;
}