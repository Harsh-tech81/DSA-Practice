// Brute Force Approach to solve this next greater Element using vectors but the best approach to solve this problem is by using Stacks

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<int> vec = {3, 1, 2, 5, 4, 6, 2, 3};
    int n = vec.size();
    vector<int> ans(n, -1); // Next Greater Element Array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] > vec[i])
            {
                ans[i] = vec[j];
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "  ";
    }

    return 0;
}